#include "../includes/Utils.hpp"

size_t hexToDecimal(const std::string& hex) {
  size_t decimal = 0;
  int len = hex.length();

  for (int i = 0; i < len; i++) {
    char c = hex[i];

    int val;
    if ('0' <= c && c <= '9') {
      val = c - '0';
    } else if ('a' <= c && c <= 'f') {
      val = c - 'a' + 10;
    } else if ('A' <= c && c <= 'F') {
      val = c - 'A' + 10;
    } else
      val = 0;

    decimal += val * pow(16, len - 1 - i);
  }

  return decimal;
}

int ftStoi(std::string str) {
  int ret = 0;
  bool neg = false;

  if (str[0] == '-') {
    neg = true;
    str = str.substr(1, str.size() - 1);
  }
  for (size_t i = 0; i < str.size() && str[i] >= '0' && str[i] <= '9'; i++) {
    ret *= 10;
    ret += str[i] - '0';
  }
  if (neg) ret = -ret;
  return ret;
}

std::string ftItos(int num) {
  std::string ret;
  bool neg = false;

  if (num == 0) return "0";
  if (num < 0) {
    neg = true;
    num = -num;
  }
  while (num) {
    ret += num % 10 + '0';
    num /= 10;
  }
  std::reverse(ret.begin(), ret.end());
  if (neg) ret = "-" + ret;
  return ret;
}

void ftToupper(std::string& str) {
  std::string res;

  for (size_t i = 0; i < str.length(); i++) {
    res += static_cast<char>(std::toupper(str.at(i)));
  }
  str = res;
}
/*convert to seconde unit, defualt is second*/
size_t convertTimeUnits(std::string value) {
  std::stringstream ss(value);
  size_t sum = 0;
  std::string timeUnits[4] = {"", "MS", "S", "M"};
  float times[4] = {1, 0.001, 1, 60000};

  while (true) {
    int num = 0;
    std::string unit;
    ss >> num >> unit;
    if (num == 0) break;
    ftToupper(unit);
    for (int index = 0; index < 4; index++) {
      if (unit == timeUnits[index]) {
        sum += num * times[index];
        break;
      }
    }
  }
  return sum;
}

size_t convertByteUnits(std::string value) {
  int num;
  std::string unit;
  std::stringstream ss(value);
  const std::string byteUnits[4] = {"", "K", "M", "G"};
  int index;

  ss >> num >> unit;
  ftToupper(unit);
  for (index = 0; index < 4; index++)
    if (unit == byteUnits[index]) break;

  return (num * std::pow(1024, index));
}

std::string ftInetNtoa(struct in_addr addr) {
  __uint32_t ip = htonl(addr.s_addr);
  unsigned char bytes[4];
  bytes[0] = (ip >> 24) & 0xFF;
  bytes[1] = (ip >> 16) & 0xFF;
  bytes[2] = (ip >> 8) & 0xFF;
  bytes[3] = ip & 0xFF;

  std::stringstream ss;
  ss << static_cast<int>(bytes[0]) << "." << static_cast<int>(bytes[1]) << "."
     << static_cast<int>(bytes[2]) << "." << static_cast<int>(bytes[3]);

  return ss.str();
}

std::string getCurrentTime() {
  std::time_t t = std::time(NULL);
  /*시간을 tm구조로 변환해 줌*/
  std::tm* timePtr = std::gmtime(&t);

  char buffer[1000];
  /*날짜/시간을 문자열로 변환*/
  std::strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S GMT", timePtr);

  return (std::string(buffer));
}