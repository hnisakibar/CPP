#include "Harl.hpp"
#include <iostream> 

typedef void (Harl::*complaintAction)(void);

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!" << '\n';
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!" << '\n';
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years, whereas you started working here "
		<< "just last month." << '\n';
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< '\n';
}

void	Harl::complain(std::string level)
{
	std::string	levels[4];
	complaintAction	actions[4];

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	actions[0] = &Harl::debug;
	actions[1] = &Harl::info;
	actions[2] = &Harl::warning;
	actions[3] = &Harl::error;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*actions[i])();
			return ;
		}
	}
	std::cout << "Unknown complaint level." << '\n';
}
