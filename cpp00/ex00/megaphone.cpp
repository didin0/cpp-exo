#include <iostream>
#include <cctype>
#include <string>

std::string ft_toupper(char *str)
{
	std::string result = str;
	for (size_t i = 0; i < result.length(); i++)
		result[i] = toupper(result[i]);
	return result;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			std::cout << ft_toupper(argv[i]) << " ";
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
