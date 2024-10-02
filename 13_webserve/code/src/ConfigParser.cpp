#include "../includes/ConfigParser.hpp"

ConfigParser::ConfigParser(const char *path) : _pos(0), _start(0) {
  readConfig(path);
  if (_line.empty()) throw std::runtime_error("Empty config file!\n");
}

ConfigParser::~ConfigParser() {}

void ConfigParser::readConfig(const char *path) {
  std::ifstream filestream(path);
  if (!filestream.is_open()) {
    std::cerr << "Path error" << std::endl;
    return;
  }
  std::stringstream buffer;
  buffer << filestream.rdbuf();
  if (buffer.good() == false) {
    throw std::runtime_error("Config Filestream Read Function Error");
  }
  _line = buffer.str();
}

bool ConfigParser::skipBracket() {
  _pos = _line.find_first_of("{", _pos);
  if (_pos == std::string::npos) return false;
  _start = _line.find_first_of("}", _pos);
  if (_start == std::string::npos) return false;
  ++_pos;
  return true;
}

void ConfigParser::setKey(std::string &key) {
  key.clear();
  _start = _line.find_first_not_of(ISSPACE, _pos);  // spaces skip
  if (_start == std::string::npos) return;
  _pos = _line.find_first_of(ISSPACE, _start);  // find next index of directive
  if (_pos == std::string::npos) return;
  key = _line.substr(_start, _pos - _start);  // get directive
}

void ConfigParser::setValue(std::string &value) {
  value.clear();
  _start = _line.find_first_not_of(ISSPACE, _pos);  // spaces skip
  if (_start == std::string::npos) return;
  _pos = _line.find_first_of(SEMICOLON,
                             _start);  // find end of directives(end of line)
  if (_pos == std::string::npos) return;
  value = _line.substr(_start, _pos - _start);  // get directive's parameters
  ++_pos;
}

ServerBlockMap &ConfigParser::getServerBlockMap() { return _serverBlockMap; }

bool compareLoc(LocationBlock *a, LocationBlock *b) {
  return (a->getPath().length() > b->getPath().length());
}

LocationMap &ConfigParser::getSortedLocationMap() {
  for (LocationMap::iterator it = _locationMap.begin();
       it != _locationMap.end(); it++) {
    LocationList *temp = (*it).second;
    std::sort(temp->begin(), temp->end(), compareLoc);
  }
  return _locationMap;
}

RootBlock *ConfigParser::addBlock(RootBlock *block, enum BLOCK type) {
  RootBlock *newBlock;

  if (type == ROOT)
    newBlock = new ServerBlock(*block);
  else {
    newBlock = new LocationBlock(static_cast<ServerBlock &>(*block));
    std::string key;
    setKey(key);
    newBlock->setKeyVal("path", key);
    if (_locationMap.find(static_cast<ServerBlock *>(block)) ==
        _locationMap.end())
      _locationMap[static_cast<ServerBlock *>(block)] = new LocationList;
    _locationMap[static_cast<ServerBlock *>(block)]->push_back(
        static_cast<LocationBlock *>(newBlock));
  }
  return newBlock;
}

void ConfigParser::parseBlocks(RootBlock *block, enum BLOCK type) {
  std::string key;
  std::string value;

  while (true) {
    setKey(key);
    if (type != ROOT && key == "}")
      return;
    else if ((type == ROOT && key == "server") ||
             (type == ROOT && key == "event") ||
             (type == SERVER && key == "location")) {
      if (type == ROOT && !skipBracket()) continue;
      if (key == "event")
        parseBlocks(block, EVENT);
      else {
        RootBlock *temp = addBlock(block, type);
        if (type == SERVER && !skipBracket()) continue;
        parseBlocks(temp, static_cast<enum BLOCK>(type + 1));
      }
      continue;
    }
    setValue(value);
    if (key.empty() || value.empty()) return;
    block->setKeyVal(key, value);  // set data on the Block
    if (type == SERVER &&
        key == "listen") {  // When ServerBlock's port is determined
      int listenPort = static_cast<ServerBlock *>(block)->getListenPort();
      if (_serverBlockMap.find(listenPort) == _serverBlockMap.end())
        _serverBlockMap[listenPort] = new SPSBList;
      _serverBlockMap[listenPort]->push_back(static_cast<ServerBlock *>(block));
    }
  }
}
