#include <iostream>
#include <string>

int main(int argc, char ** argv) {
	std::string loud_text;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {

		for (int i = 1; i < argc; i++) {
			for (size_t j = 0; j < strlen(argv[i]); j++) {
				loud_text += toupper(argv[i][j]);
			}
		}
	}
	std::cout << loud_text << std::endl;
	return 0;
}
