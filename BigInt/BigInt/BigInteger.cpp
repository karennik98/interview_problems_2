#include <iostream>
#include <cmath>
#include "BigInteger.h"

#define MAX 10000


BigInteger::BigInteger()
{
	setNumber("0");
	setSign(false);
}

BigInteger::BigInteger(std::string number)
{
	if (isdigit(number[0])) 
	{
		setNumber(number);
		setSign(false);
	}
	else
	{
		setNumber(number.substr(1));
		setSign(number[0] == '-'); 
	}
}

BigInteger::BigInteger(std::string number, bool sign)
{
	if (sign)
	{
		setNumber(number.substr(1));
		setSign(sign);
	}
	else
	{
		setNumber(number);
		setSign(sign);
	}
}

void BigInteger::setNumber(std::string num)
{
	m_number = num;
}

const std::string& BigInteger::getNumber()const
{
	return m_number;
}

void BigInteger::setSign(bool sign)
{
	m_sign = sign;
}

const bool& BigInteger::getSign()const
{
	return m_sign;
}

bool BigInteger::Equals(BigInteger num1, BigInteger num2)
{
	return (num1.getNumber() == num2.getNumber() && num1.getSign() == num2.getSign());
}

bool BigInteger::Less(BigInteger num1, BigInteger num2) 
{
	bool sign1 = num1.getSign();
	bool sign2 = num2.getSign();
	if (sign1 && sign2)
	{
		if (num1.getNumber().length() > num2.getNumber().length())
		{
			return true;
		}
		else if (num1.getNumber().length() < num2.getNumber().length())
		{

			return false;
		}
		else if (num1.getNumber().length() == num2.getNumber().length())
		{
			for (int i = 0; i < num1.getNumber().length(); ++i)
			{
				if (num1.getNumber()[i] > num2.getNumber()[i])
				{
					return true;
				}
				else if (num1.getNumber()[i] < num2.getNumber()[i])
				{
					return false;
				}
			}
		}
	}
	else if (!(sign1 && sign2))
	{
		if (num1.getNumber().length() < num2.getNumber().length())
		{
			return true;
		}
		else if (num1.getNumber().length() > num2.getNumber().length())
		{

			return false;
		}
		else if (num1.getNumber().length() == num2.getNumber().length())
		{
			for (int i = 0; i < num1.getNumber().length(); ++i)
			{
				if (num1.getNumber()[i] < num2.getNumber()[i])
				{
					return true;
				}
				else if (num1.getNumber()[i] > num2.getNumber()[i])
				{
					return false;
				}
			}
		}
	}
	else if (sign1)
		return true;
	else if (sign2)
		return false;
}

bool BigInteger::Greater(BigInteger num1, BigInteger num2)
{
	return !Equals(num1, num2) && !Less(num1, num2);
}

std::string BigInteger::Add(std::string num1, std::string num2)
{
	std::string sum = (num1.length() > num2.length() ? num1 : num2);
	int diffInLenghts = std::abs(static_cast<int>(num1.size() - num2.size()));
	if (num1.size() > num2.size())
	{
		num2.insert(0, diffInLenghts, '0');
	}
	else
	{
		num1.insert(0, diffInLenghts, '0');
	}
	for (int i = num1.size() - 1; i >= 0; --i)
	{
		sum[i] = ((num1[i] - '0') + (num2[i] - '0') + '0');
		if (i != 0)
		{
			if (sum[i] > '9')
			{
				sum[i] -= 10;
				num1[i - 1] += 1;
			}
		}
	}
	if (sum[0] > '9')
	{
		sum[0] -= 10;
		sum.insert(0, 1, '1');
	}
	return sum;
}

std::string BigInteger::Subtract(std::string num1, std::string num2)
{
	std::string quotient = num1.length() > num2.length() ? num1 : num2;
	int diffInLenght = std::abs(static_cast<int>(num1.size() - num2.size()));
	if (num1.size() > num2.size())
	{
		num2.insert(0, diffInLenght, '0');
	}
	else
	{
		num1.insert(0, diffInLenght, '0');
	}
	for (int i = num1.length() - 1; i >= 0; --i)
	{
		if (num1[i] < num2[i])
		{
			num1[i] += 10;
			num1[i - 1] -= 1;
		}
		quotient[i] = ((num1[i] - '0') - (num2[i] - '0') + '0');
	}
	while (quotient[0] == '0' && quotient.length() != 1)
	{
		quotient.erase(0, 1);
	}
	return quotient;
}

std::pair<std::string, long long> BigInteger::Divide(std::string n, long long den)
{
	long long rem = 0;
	std::string result;
	result.resize(MAX);

	for (int indx = 0, len = n.length(); indx < len; ++indx)
	{
		rem = (rem * 10) + (n[indx] - '0');
		result[indx] = rem / den + '0';
		rem %= den;
	}
	result.resize(n.length());

	while (result[0] == '0' && result.length() != 1)
		result.erase(0, 1);

	if (result.length() == 0)
		result = "0";

	return std::make_pair(result, rem);
}

BigInteger BigInteger::absolute()
{
	return BigInteger(getNumber()); 
}

long long BigInteger::toInt(std::string str)
{
	long long sum = 0;

	for (int i = 0; i < str.length(); i++)
		sum = (sum * 10) + (str[i] - '0');

	return sum;
}

BigInteger BigInteger::operator + (BigInteger b)
{
	BigInteger addition;
	if (getSign() == b.getSign()) 
	{
		addition.setNumber(Add(getNumber(), b.getNumber()));
		addition.setSign(getSign());
	}
	else 
	{
		if (absolute() > b.absolute())
		{
			addition.setNumber(Subtract(getNumber(), b.getNumber()));
			addition.setSign(getSign());
		}
		else
		{
			addition.setNumber(Subtract(b.getNumber(), getNumber()));
			addition.setSign(b.getSign());
		}
	}
	if (addition.getNumber() == "0") 
		addition.setSign(false);

	return addition;
}
BigInteger BigInteger::operator - (BigInteger b)
{
	b.setSign(!b.getSign()); 
	return (*this) + b;
}
BigInteger BigInteger::operator * (BigInteger b)
{
	//TODO
}
BigInteger BigInteger::operator / (BigInteger b)
{
	long long den = toInt(b.getNumber());
	BigInteger div;

	div.setNumber(Divide(getNumber(), den).first);
	div.setSign(getSign() != b.getSign());

	if (div.getNumber() == "0") 
		div.setSign(false);

	return div;
}

bool BigInteger::operator > (BigInteger b)
{
	return Greater((*this), b);
}
bool BigInteger::operator < (BigInteger b)
{
	return Less((*this), b);
}

