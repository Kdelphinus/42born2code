#include "../includes/RootBlock.hpp"

RootBlock::RootBlock()
    : _workerProcesses(0),
      _workerRlimitNofile(0),
      _workerConnections(0),
      _clientMaxBodySize(4096),
      _keepAliveTime(0) {}

RootBlock::RootBlock(RootBlock &copy)
    : _user(copy._user),
      _group(copy._group),
      _workerProcesses(copy._workerProcesses),
      _errorLog(copy._errorLog),
      _pid(copy._pid),
      _workerRlimitNofile(copy._workerRlimitNofile),
      _workerConnections(copy._workerConnections),
      _include(copy._include),
      _clientMaxBodySize(copy._clientMaxBodySize),
      _keepAliveTime(copy._keepAliveTime) {}

RootBlock::~RootBlock() {}

void RootBlock::setUser(std::string value) {
  size_t tmp = value.find_first_of(" \t\n\r\f\v");
  if (tmp != std::string::npos) {
    _user = value.substr(0, tmp - 1);
    tmp = value.find_first_not_of(" \t\n\r\f\v", tmp);
    _group = value.substr(tmp, value.size() - tmp);
  } else {
    _user = value;
    _group = value;
  }
}

void RootBlock::setWorkerProcesses(std::string value) {
  _workerProcesses = atoi(value.c_str());
}

void RootBlock::setErrorLog(std::string value) { _errorLog = value; }

void RootBlock::setPid(std::string value) { _pid = value; }

void RootBlock::setWorkerRlimitNofile(std::string value) {
  _workerRlimitNofile = atoi(value.c_str());
}

void RootBlock::setWorkerConnections(std::string value) {
  _workerConnections = atoi(value.c_str());
}

void RootBlock::setInclude(std::string value) { _include = value; }

void RootBlock::setKeepAliveTime(std::string value) {
  _keepAliveTime = convertTimeUnits(value);
}

void RootBlock::setClientMaxBodySize(std::string value) {
  _clientMaxBodySize = convertByteUnits(value);
}

void RootBlock::setKeyVal(std::string key, std::string value) {
  typedef void (RootBlock::*funcptr)(std::string);
  std::map<std::string, funcptr> funcmap;

  funcmap["user"] = &RootBlock::setUser;
  funcmap["worker_processes"] = &RootBlock::setWorkerProcesses;
  funcmap["error_log"] = &RootBlock::setErrorLog;
  funcmap["pid"] = &RootBlock::setPid;
  funcmap["worker_rlimit_nofile"] = &RootBlock::setWorkerRlimitNofile;
  funcmap["worker_connections"] = &RootBlock::setWorkerConnections;
  funcmap["include"] = &RootBlock::setInclude;
  funcmap["client_max_body_size"] = &RootBlock::setClientMaxBodySize;
  funcmap["keepalive_timeout"] = &RootBlock::setKeepAliveTime;

  if (funcmap.find(key) != funcmap.end()) (this->*(funcmap[key]))(value);
}

const std::string RootBlock::getUser() const { return _user; }

const std::string RootBlock::getGroup() const { return _group; }

int RootBlock::getWorkerProcesses() const { return _workerProcesses; }

const std::string RootBlock::getErrorLog() const { return _errorLog; }

const std::string RootBlock::getPid() const { return _pid; }

int RootBlock::getWorkerRlimitNofile() const { return _workerRlimitNofile; }

int RootBlock::getWorkerConnection() const { return _workerConnections; }

const std::string RootBlock::getInclude() const { return _include; }

const size_t &RootBlock::getClientMaxBodySize() const {
  return _clientMaxBodySize;
}

const size_t &RootBlock::getKeepAliveTime() const { return _keepAliveTime; }