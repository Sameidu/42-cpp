#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

std::string replaceString ( std::string line, std::string s1, std::string s2 ) {
	size_t pos = 0;
	std::string result;

	while ( line != "" ) {
		if (( pos = line.find(s1, pos) ) != std::string::npos) {
			result += line.substr(0, pos);
			result += s2;
			line.erase(0, pos + s1.length());
			pos = 0;
		} 
		else {
			result += line;
			break;
		}
	}
	return result;
}

int main ( int ac, char **av ) {
	if ( ac != 4 ) {
		std::cerr << "Error usage: " << av[0] << " <filename> <string search> <string replace>" << std::endl;
		return 1;
	}
	std::string file = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string replace = file + ".replace";
	std::string line;

	std::ifstream readFile(file);
	if ( !readFile.is_open() ) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::ofstream replaceFile(replace);
	if ( !replaceFile.is_open() ) {
		std::cerr << "Error: could not open replace file" << std::endl;
		return 1;
	}

	while ( std::getline(readFile, line) ) 
		replaceFile << replaceString(line, s1, s2) << std::endl;
	
	readFile.close();
	replaceFile.close();
	return 0;
};