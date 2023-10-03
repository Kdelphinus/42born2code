#include "../includes/LocationBlock.hpp"

LocationBlock::LocationBlock(ServerBlock &serverBlock)
    : ServerBlock(serverBlock), _path() {}

LocationBlock::~LocationBlock() {}

void LocationBlock::setPath(std::string value) { _path = value; }

const std::string &LocationBlock::getPath() const { return _path; }

void LocationBlock::setKeyVal(std::string key, std::string value) {
  typedef void (LocationBlock::*funcptr)(std::string);
  std::map<std::string, funcptr> funcmap;

  funcmap["path"] = &LocationBlock::setPath;
  funcmap["autoindex"] = &LocationBlock::setAutoindex;
  funcmap["limit_except"] = &LocationBlock::setLimitExcept;
  funcmap["cgi"] = &LocationBlock::setCgi;
  funcmap["cgi_redir"] = &LocationBlock::setCgiRedir;

  if (funcmap.find(key) != funcmap.end())
    (this->*(funcmap[key]))(value);
  else
    (this->ServerBlock::setKeyVal(key, value));
}
