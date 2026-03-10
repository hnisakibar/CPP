#include <iostream>
#include <string>

int	main(void)
{
	std::string		brain;
	std::string		*stringPTR;
	std::string		&stringREF = brain;

	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;

	std::cout << &brain << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n';

	std::cout << brain << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n';
	return (0);
}
