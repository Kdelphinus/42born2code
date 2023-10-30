#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange {
 private:
  std::map<std::string, double> _exchange;
 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &be);
  BitcoinExchange &operator=(const BitcoinExchange &be);
  ~BitcoinExchange();

  void addExchange(std::string fileName);
};

#endif
