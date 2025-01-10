#include <string>
#include <iomanip>
#include <iostream>

int	main ( void ) {
	std::string brain = "HI THIS IIS BRAIN";
	std::string *stringPTR = &brain;
	std::string stringREF = brain;

	std::cout << "Memorie address of brain " << &brain << std::endl;
	std::cout << "Memorie address of stringPTR " << stringPTR << std::endl;
	std::cout << "Memorie address of stringREF " << &stringREF << std::endl;
	std::cout << "Content of brain: " << brain << std::endl;
	std::cout << "Content of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Content of stringREF: " << stringREF << std::endl;
}