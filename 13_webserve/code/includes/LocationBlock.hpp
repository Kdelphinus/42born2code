#ifndef LOCATIONBLOCK_HPP
#define LOCATIONBLOCK_HPP

#include <iostream>
#include <map>

#include "ServerBlock.hpp"

class LocationBlock : public ServerBlock {
 private:
  std::string _path;

 public:
  LocationBlock(ServerBlock &serverBlock);
  ~LocationBlock();

  void setPath(std::string value);
  void setKeyVal(std::string key, std::string value);

  const std::string &getPath() const;
};

#endif
