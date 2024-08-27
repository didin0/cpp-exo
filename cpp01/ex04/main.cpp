#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
	// Arguments
	if (argc != 4) {
		std::cout << "Usage: <filename> <string1> <string2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (filename.empty() || s1.empty() || s2.empty()) {
		std::cout << "You cannot provide empty arguments" << std::endl;
		return 1;
	}
	if (s1 == s2) {
		std::cout << "Please enter two different strings" << std::endl;
		return 1;
	}
	// Open file to read
	std::ifstream ifs(filename.c_str());
	if (!ifs) {
		std::cout << "Failed to open the file: " << filename << std::endl;
		return 2;
	}
	// Create file to write
	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs) {
		std::cout << "Failed to create the file: " << filename + ".replace" << std::endl;
		return 3;
	}
	// Find and replace occurences than write
	std::string line;
	while (std::getline(ifs, line)) {
		size_t pos;
		while ((pos = line.find(s1)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		ofs << line << std::endl;
	}
	// Closing streams
	ifs.close();
	ofs.close();

	return 0;
}

