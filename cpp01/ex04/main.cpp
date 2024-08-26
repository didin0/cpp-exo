#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

int main(int argc, char **argv) {
	if (argc == 3) {
		// arguments
		if (strlen(argv[1]) <= 0 || strlen(argv[2]) <= 0) {
			std::cout << "You cannot provide empty arguments" << std::endl;
			return 1;
		}
		else if (!strcmp(argv[1], argv[2])) {
			std::cout << "Please, enter 2 differents arugments" << std::endl;
			return 1;
		}
		// opening file
		std::ifstream ifs;
		ifs.open("test.txt", std::ifstream::in);
		char c = ifs.get();
		while (ifs.good()) {
			std::cout << c;
			c = ifs.get();
		}

		ifs.close();
	}	
	else
		std::cout << "here"	<< std::endl;

	return 0;
}
