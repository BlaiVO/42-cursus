#include <string>
#include <iostream>
#include <fstream>

void	generate_new_file(std::ifstream &ifile, std::ofstream &ofile, std::string s1, std::string s2) {
	size_t			occurence;
	std::string 	line;
	std::string		content;
	char			last;

	if (ifile.peek() == std::ifstream::traits_type::eof())
		return ;
	while (std::getline(ifile, line)) {
		if (s1 != "") {
			occurence = line.find(s1);
			while (occurence != std::string::npos) {
				line.erase(occurence, s1.length());
				line.insert(occurence, s2);
				occurence = line.find(s1, occurence + s2.length());
			}
		}
		content.append(line += '\n');
	}

	ifile.clear();
	ifile.seekg(-1, std::ios_base::end);
	ifile.get(last);
	if (last != '\n')
		content.erase(content.end() - 1);
	ofile << content;
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	std::string	filename(argv[1]);
	std::ifstream ifile;
	std::ofstream ofile;

	ifile.open(filename.c_str());
	if (!ifile.is_open()) {
		std::cout << "Error: File could not be open" << std::endl;
		return 1;
	}

	ofile.open(filename.append(".replace").c_str());
	if (!ofile.is_open()) {
		std::cout << "Error: File could not be open" << std::endl;
		return 1;
	}
	generate_new_file(ifile, ofile, argv[2], argv[3]);
}