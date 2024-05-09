#include <iostream>
#include <fstream>
#include <string>

void	printError(std::string str)
{
	std::cerr << str << std::endl;
}

void	replaceSubstring(std::string& line, std::string& search, std::string& replacement)
{
	// int	startPos;
	while (1)
	{
		size_t startPos = line.find(search);
		int		length = search.length();
		if (startPos == std::string::npos)
			return ;
		bool isEqual = (line.substr(startPos, length) == search.substr(0, length));
		if (!isEqual)
			return ;
		line.erase(startPos, search.length());
		line.insert(startPos, replacement);
		startPos = line.find(search, startPos + replacement.length());
	}
	
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (printError("Error: expecting arguments: \
		./replace filename string_to_find string_to_replace"), 1);
	std::string		name = av[1];
	std::string		toFind = av[2];
	std::string		replace = av[3];
	std::string		line;

	std::ifstream inF(name.c_str());
	if (!inF.is_open())
		return (printError("Error opening file"), 1);
	name = name + ".replace";
	std::ofstream	outF(name.c_str());
	if (!outF.is_open())
	{
		inF.close();
		return (printError("Error opening file"), 1);
	}
	while (1)
	{
		std::getline(inF, line);
		if (inF.eof())
		{
			replaceSubstring(line, toFind, replace);
			outF << line;
			break ;
		}
		replaceSubstring(line, toFind, replace);
		outF << line << "\n";
	}
	inF.close();
	outF.close();
	return 0;
}
