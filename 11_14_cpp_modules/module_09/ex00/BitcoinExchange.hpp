#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

typedef std::map<std::string, double>::const_iterator const_it;

class BitcoinExchange {
 private:
  std::map<std::string, double> _exchange;

  void addExchange();
  bool isInvalidDate(std::string &date);
  bool isNumeric(std::string &value);
  bool isInvalidValue(std::string &value);
  double getData(std::string &date);
 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &be);
  BitcoinExchange &operator=(const BitcoinExchange &be);
  ~BitcoinExchange();

  void printExchange(const char *fileName);
};

#endif
