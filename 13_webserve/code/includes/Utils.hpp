#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <netinet/in.h>

int ftStoi(std::string str);
std::string ftItos(int num);
void ftToupper(std::string& str);
size_t convertTimeUnits(std::string value);
size_t convertByteUnits(std::string value);
size_t hexToDecimal(const std::string& hex);
std::string ftInetNtoa(struct in_addr addr);
std::string getCurrentTime();

#endif
