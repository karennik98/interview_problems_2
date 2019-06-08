#pragma once
#include <string>

class separate_string
{
public:
	separate_string(size_t step, std::string value)
		: step_(step)
		, value_(value)
	{
	}


private:
	size_t step_;
	std::string value_;
};

