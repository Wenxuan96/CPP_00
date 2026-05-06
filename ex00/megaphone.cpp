#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	
	for (int i = 1; i < argc; i++)
	{
		std::string message(argv[i]);
		for (size_t j = 0; j < message.length(); j++)
			message[j] = std::toupper(message[j]);
		std::cout << message;
	}
	std::cout << std::endl;
	return 0;
}