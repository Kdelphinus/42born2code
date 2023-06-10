#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
        void runDebug(int level);
        void runInfo(int level);
        void runWarning(int level);
        void runError(int level);
        void runDefault(void);
		void complain(std::string level);
        int getLevel(std::string level);
};

#endif
