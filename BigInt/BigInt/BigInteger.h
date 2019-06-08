
#pragma once
#include <string>

class BigInteger {
public:
	BigInteger();
	BigInteger(std::string);
	BigInteger(std::string, bool);
	void setNumber(std::string);
	const std::string& getNumber()const;
	void setSign(bool);
	const bool& getSign()const;
public:
	BigInteger operator + (BigInteger b);
	BigInteger operator - (BigInteger b);
	BigInteger operator * (BigInteger b);
	BigInteger operator / (BigInteger b);
	bool operator > (BigInteger b);
	bool operator < (BigInteger b);
private: 
	bool Equals(BigInteger, BigInteger); 
	bool Less(BigInteger, BigInteger); 
	bool Greater(BigInteger, BigInteger); 
	std::string Add(std::string, std::string);
	std::string Subtract(std::string, std::string); 
	//std::string Multiply(std::string, std::string); //TODO
	std::pair<std::string, long long> Divide(std::string num, long long den); 
	BigInteger absolute();
	long long toInt(std::string str);
private:
	std::string     m_number;
	bool            m_sign;

};