#ifndef SERVERBLOCK_HPP
#define SERVERBLOCK_HPP

#include <iostream>
#include <list>
#include <map>
#include <vector>

#include "RootBlock.hpp"

class ServerBlock : public RootBlock {
 protected:
  int _listenPort;
  std::string _listenHost;
  std::string _root;
  std::string _index;
  std::string _serverName;
  std::string _autoindex;
  std::string _limitExcept;
  std::string _cgi;
  std::string _cgiRedir;

 public:
  ServerBlock(RootBlock &rootBlock);
  ServerBlock(ServerBlock &copy);
  ~ServerBlock();

  void setListen(std::string value);
  void setRoot(std::string value);
  void setIndex(std::string value);
  void setServerName(std::string value);
  void setAutoindex(std::string value);
  void setLimitExcept(std::string value);
  void setCgi(std::string value);
  void setCgiRedir(std::string value);
  virtual void setKeyVal(std::string key, std::string value);

  int getListenPort() const;
  const std::string &getListenHost() const;
  const std::string &getRoot() const;
  const std::string &getIndex() const;
  const std::string &getServerName() const;
  const std::string &getAutoindex() const;
  const std::string &getLimitExcept() const;
  const std::string &getCgi() const;
  const std::string &getCgiRedir() const;
};

#endif
