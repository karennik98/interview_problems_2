#include <iostream>
#include <algorithm>
#include <string>

void print_substr(std::string str, std::string start_str, size_t sublenght, size_t depth)
{
	if (depth == sublenght)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			if(std::string::npos == start_str.find(str[i]))
				std::cout << start_str << str[i] << std::endl;
		}
	}
	else
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (std::string::npos == start_str.find(str[i]))
			{
				std::string tmp = start_str + str[i];
				print_substr(str, tmp, sublenght, depth + 1);
			}
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::string str;
	size_t sublenght;
	std::getline(std::cin, str);
	std::cin >> sublenght;
	std::sort(str.begin(), str.end());
	print_substr(str, "", sublenght, 1);
	system("pause");
	return 0;
}