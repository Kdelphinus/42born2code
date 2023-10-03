#ifndef CONFIGPARSER_HPP
#define CONFIGPARSER_HPP

#include <string.h>
#include <exception>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

#include "./LocationBlock.hpp"
#include "./RootBlock.hpp"
#include "./ServerBlock.hpp"

#define ISSPACE " \t\n\r\f\v"
#define SEMICOLON ";"

enum BLOCK { ROOT, SERVER, LOCATION, EVENT };

typedef std::vector<ServerBlock *> SPSBList;      // Same Port ServerBlock List
typedef std::map<int, SPSBList *> ServerBlockMap; // key:port, value:SPSBList

typedef std::vector<LocationBlock *> LocationList;
// key: serverBlock ptr, value: LocationList(LocationBlock * vector)
typedef std::map<ServerBlock *, LocationList *> LocationMap;

class ConfigParser {
  private:
    std::size_t _pos;
    std::size_t _start;
    std::string _line;
    ServerBlockMap _serverBlockMap;
    LocationMap _locationMap;

  private:
    void setKey(std::string &key);
    void setValue(std::string &value);
    void readConfig(const char *path);
    bool skipBracket();
    RootBlock *addBlock(RootBlock *block, enum BLOCK type);

  public:
    ConfigParser(const char *path);
    ~ConfigParser();
    void parseBlocks(RootBlock *block, enum BLOCK type);
    ServerBlockMap &getServerBlockMap();
    LocationMap &getSortedLocationMap();
};

#endif
