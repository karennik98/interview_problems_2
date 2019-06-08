#include <iostream>

#include "BigInteger.h"

int main()
{
	BigInteger a = BigInteger("234278477388299839288377266677");
	BigInteger b = BigInteger("475883992884857488277488372738");

	BigInteger c = a + b;

	std::cout << c.getNumber()<<std::endl;

	system("pause");
	return 0;
}