#include "Harl.h"

void Harl::debug() {
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
			  << "I really do!"
			  << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
			  << "You didn't put enough bacon in my buger!\n"
			  << "If you did, I wouldn't be asking for more!"
			  << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free.\n"
			  << "I've been coming for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*funcPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,};
	std::string cmd[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == cmd[i]) {
			(this->*funcPtr[i])();
			return ;
		}
	}
	std::cout << "Invaild command" << std::endl;
}

void Harl::runDebug(int level) {
    if (level == -1 || level > 0)
        return ;
    std::cout << "[ DEBUG ]" << std::endl;
    this->debug();
    std::cout << std::endl;
}

void Harl::runInfo(int level) {
    if (level == -1 || level > 1)
        return ;
    std::cout << "[ INFO ]" << std::endl;
    this->info();
    std::cout << std::endl;
}

void Harl::runWarning(int level) {
    if (level == -1 || level > 2)
        return ;
    std::cout << "[ WARNING ]" << std::endl;
    this->warning();
    std::cout << std::endl;
}

void Harl::runError(int level) {
    if (level == -1 || level > 3)
        return ;
    std::cout << "[ ERROR ]" << std::endl;
    this->error();
    std::cout << std::endl;
}

void Harl::runDefault() {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

int Harl::getLevel(std::string level) {
    std::string cmd[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level == cmd[i])
            return i;
    }
    return -1;
}