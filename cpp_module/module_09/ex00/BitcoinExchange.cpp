#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	addExchange();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &be)
		: _exchange(be._exchange) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &be) {
	if (this != &be) {
		_exchange.clear();
		_exchange = be._exchange;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::addExchange() {
	std::ifstream file;
	file.open("data.csv");

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line, date, value, delimiter = ",";
	size_t pos;

	int i = 0;
	while (std::getline(file, line)) {
		if (i == 0) {
			++i;
			continue;
		}
		pos = line.find(delimiter);
		date = line.substr(0, pos);
		value = line.substr(pos + 1, line.length() - pos);
		_exchange[date] = std::atof(value.c_str());
	}
	file.close();
}

bool BitcoinExchange::isInvalidDate(std::string &date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return true;

	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return true;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return true;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return true;

	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day > 29)
				return true;
		} else if (day > 28)
			return true;
	}
	return false;
}

bool BitcoinExchange::isNumeric(std::string &value) {
	int dotCnt = 0;
	int numCnt = 0;

	for (size_t i = 0; i < value.size(); ++i) {
		if (i == 0 && (value[i] == '-' || value[i] == '+'))
			continue;
		if (value[i] == '.') {
			if (dotCnt == 1)
				return false;
			++dotCnt;
			continue;
		}
		if (!std::isdigit(value[i]))
			return false;
		++numCnt;
	}
	if (numCnt == 0)
		return false;
	return true;
}

bool BitcoinExchange::isInvalidValue(std::string &value) {
	if (!isNumeric(value)) {
		std::cout << "Error: invalid number." << std::endl;
		return true;
	}

	double d = std::atof(value.c_str());
	if (d < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return true;
	}
	if (d > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return true;
	}
	return false;
}

double BitcoinExchange::getData(std::string &date) {
	if (_exchange.find(date) != _exchange.end())
		return _exchange[date];

	double value = 0;
	for (const_it i = _exchange.begin(); i != _exchange.end(); ++i) {
		if (date < i->first)
			return value;
		value = i->second;
	}
	return value;
}

void BitcoinExchange::printExchange(const char *fileName) {
	std::ifstream file;

	file.open(fileName);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line, date, value, delimiter = " | ";
	size_t pos;

	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: header must be \"date | value\".");

	while (std::getline(file, line)) {
		pos = line.find(delimiter);
		date = line.substr(0, pos);
		if (pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (isInvalidDate(date)) {
			std::cout << "Error: invalid date." << std::endl;
			continue;
		}
		value = line.substr(pos + delimiter.size(), line.length() - pos);
		if (isInvalidValue(value))
			continue;
		std::cout << date << " => " << value << " = "
							<< getData(date) * std::atof(value.c_str()) << std::endl;
	}
}
