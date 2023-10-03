#include "../includes/ServerBlock.hpp"

ServerBlock::ServerBlock(RootBlock &rootBlock)
    : RootBlock(rootBlock),
      _listenPort(0),
      _listenHost(),
      _root(),
      _index(),
      _serverName(),
      _autoindex("off") {}

ServerBlock::ServerBlock(ServerBlock &copy)
    : RootBlock(copy),
      _listenPort(copy._listenPort),
      _listenHost(copy._listenHost),
      _root(copy._root),
      _index(copy._index),
      _serverName(copy._serverName) {}

ServerBlock::~ServerBlock() {}

void ServerBlock::setListen(std::string value) {
  size_t tmp = value.find_first_of(":");
  if (tmp != std::string::npos) {
    _listenHost = value.substr(0, tmp - 1);
    _listenPort =
        std::atoi(value.substr(tmp + 1, value.size() - tmp - 1).c_str());
  } else {
    if (value.find_first_not_of("0123456789") != std::string::npos) {
      _listenHost = value;
    } else {
      _listenPort = std::atoi(value.c_str());
    }
  }
}
void ServerBlock::setLimitExcept(std::string value) { _limitExcept = value; }

void ServerBlock::setRoot(std::string value) { _root = value; }

void ServerBlock::setIndex(std::string value) { _index = value; }

void ServerBlock::setServerName(std::string value) { _serverName = value; }

void ServerBlock::setAutoindex(std::string value) { _autoindex = value; }

void ServerBlock::setCgi(std::string value) { _cgi = value; }

void ServerBlock::setCgiRedir(std::string value) { _cgiRedir = value; }

void ServerBlock::setKeyVal(std::string key, std::string value) {
  typedef void (ServerBlock::*funcptr)(std::string);
  std::map<std::string, funcptr> funcmap;

  funcmap["listen"] = &ServerBlock::setListen;
  funcmap["root"] = &ServerBlock::setRoot;
  funcmap["index"] = &ServerBlock::setIndex;
  funcmap["server_name"] = &ServerBlock::setServerName;
  funcmap["client_max_body_size"] = &ServerBlock::setClientMaxBodySize;
  funcmap["autoindex"] = &ServerBlock::setAutoindex;

  if (funcmap.find(key) != funcmap.end())
    (this->*(funcmap[key]))(value);
  else
    (this->RootBlock::setKeyVal(key, value));
}

int ServerBlock::getListenPort() const { return _listenPort; }
const std::string &ServerBlock::getListenHost() const { return _listenHost; }
const std::string &ServerBlock::getRoot() const { return _root; }
const std::string &ServerBlock::getIndex() const { return _index; }
const std::string &ServerBlock::getServerName() const { return _serverName; }

const std::string &ServerBlock::getLimitExcept() const { return _limitExcept; }

const std::string &ServerBlock::getAutoindex() const { return _autoindex; }

const std::string &ServerBlock::getCgi() const { return _cgi; }

const std::string &ServerBlock::getCgiRedir() const { return _cgiRedir; }