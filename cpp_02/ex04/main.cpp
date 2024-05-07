#include <iostream>
#include <fstream>
#include <string>

// std::string::replace

void	print_error(std::string str)
{
	std::cerr << str << std::endl;
}

void	replaceSubstring(std::string& line, std::string& search, std::string& replacement)
{
	size_t	startPos = line.find(search);

	if (startPos == std::string::npos)
		return ;
	line.erase(startPos, search.length());
	line.insert(startPos, replacement);
	startPos = line.find(search, startPos + replacement.length());
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (print_error("Error: expecting arguments: ./replace filename s1 s2"), 1);
	std::string	name = av[1];
	std::string		toFind = av[2];
	std::string		replace = av[3];
	std::ifstream	inF;
	std::ofstream	outF;
	std::string		line;

	inF.open(name);
	if (!inF.is_open())
		return (print_error("Error opening file"), 1);
	outF.open(name + ".replace");
	if (!outF.is_open())
	{
		inF.close();
		return (print_error("Error opening file"), 1);
	}
	while (1)
	{
		std::getline(inF, line);
		if (inF.eof())
		{
			outF << std::endl;
			break ;
		}
		replaceSubstring(line, toFind, replace);
		outF << line;
	}
	inF.close();
	outF.close();
	return 0;
}
