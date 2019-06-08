#include <queue>
#include <unordered_map>
#include <iostream>
#include <string>

std::pair<std::string, double> parse(std::string str)
{
	std::string name;
	std::string price;

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			price += str[i];
		}
	}
	size_t pos = str.find(price);
	if (pos != std::string::npos)
	{
		str.erase(pos, price.size());
	}
	return std::make_pair(str, std::stof(price));
}

void add_map(std::string str, std::unordered_map<std::string, double>& map)
{
	std::pair<std::string, double> pair = parse(str);

	auto it = map.find(pair.first);

	if (it != map.end())
	{
		it->second = it->second + pair.second;
	}
	else
	{
		map.insert(pair);
	}
}

void print_map(std::unordered_map<std::string, double>& map)
{
	for (const auto it : map)
	{
		std::cout << it.first << std::ends << it.second << std::endl;
	}
}


void insert(std::string str, double price, std::unordered_map<std::string,double>& map)
{
	auto it = map.find(str);

	if (it != map.end())
	{
		it->second = it->second + price;
	}
	else
	{
		map.insert({str,price});
	}
}

int main()
{
	std::unordered_map<std::string, double> map;

	std::string count_str;
	std::getline(std::cin, count_str);
	size_t count = std::stoi(count_str);

	std::string str;

	for (size_t i = 0; i < count; ++i)
	{
		std::getline(std::cin, str);
		add_map(str, map);
	}

	print_map(map);

	system("pause");
}