#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

std::string replaceString ( std::string line, std::string s1, std::string s2 ) {
	size_t pos = 0;
	std::string result;

	 while ((pos = line.find(s1)) != std::string::npos) {
        result += line.substr(0, pos) + s2;
        line = line.substr(pos + s1.length());
    }
    result += line;
    return result;
}

int main ( int ac, char **av ) {
	if ( ac != 4 ) {
		std::cerr << "Error usage: " << av[0] << " <filename> <string search> <string replace>" << std::endl;
		return 1;
	}

	std::ifstream readFile(av[1]);
	if ( !readFile.is_open() ) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::string outFile = std::string(av[1]) + ".replace";
	std::ofstream replaceFile;
	replaceFile.open(outFile.c_str());
	if ( !replaceFile.is_open() ) {
		std::cerr << "Error: could not open replace file" << std::endl;
		return 1;
	}

	std::string line;
	while ( std::getline(readFile, line) ) 
		replaceFile << replaceString(line, av[2], av[3]) << std::endl;
	
	readFile.close();
	replaceFile.close();
	return 0;
};
