#pragma once
#include <string>
#include <unordered_map>
#include <cassert>


class list_of_items
{
public:
	std::pair<std::string, double> parse(std::string str);
	void create_list();
	void insert(std::string str, double price);
	void set_count(size_t count)
	{
		assert(count > 0);
		m_count = count;
	}
private:

	size_t m_count;
};

