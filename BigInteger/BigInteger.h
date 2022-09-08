#pragma once
#ifndef _BIG_INTEGER_H_
#define _BIG_INTEGER_H_
typedef unsigned char UC;
typedef unsigned long long ULL;
#include<iostream>
#include<string>
template<typename T>
concept typeLimit = (
	std::is_same_v<T,unsigned char>||
	std::is_same_v<T,char>||
	std::is_same_v<T,unsigned short>||
	std::is_same_v<T,short>||
	std::is_same_v<T,unsigned int>||
	std::is_same_v<T,int>||
	std::is_same_v<T,unsigned long>||
	std::is_same_v<T,long>||
	std::is_same_v<T,unsigned long long>||
	std::is_same_v<T,long long>||
	std::is_same_v<T, char const*>||
	std::is_same_v<T,std::string>
	);
class BigInteger {
private:
	UC* P;
	UC Signed;
	ULL count;
	void StringToBCD(std::string str);
	template <typename T>
	void GetSigned(T number) {
		if (number < 0) {
			Signed = 0xff;
		}
		else {
			Signed = 0x00;
		}
	}
	template <typename T>
	std::string NumberToString(T number) {
		std::string str;
		if (Signed) {
			number = abs(number);
		}
		do {
			str += (number % 10) + 48;
			number = number / 10;
		} while (number);
		return str;
	}
public:
	BigInteger();
	template<typeLimit T>
	BigInteger(T number)
	{
		GetSigned(number);
		std::string str = NumberToString(number);
		StringToBCD(str);
	}
	template<>
	BigInteger(std::string number) {
		Signed = 0x00;
		if (number[0] == '-') {
			Signed = 0xff;
			number = number.substr(1, number.length());
		}
		else if (number[0] == '+') {
			number = number.substr(1, number.length());
		}
		for (ULL i = 0; i < number.length(); i++) {
			if (number[i] != '0') {
				number = number.substr(i, number.length());
				break;
			}
		}
		reverse(number.begin(), number.end());
		StringToBCD(number);
	}
	template<>
	BigInteger(char const* number) {
		std::string str = number;
		Signed = 0x00;
		if (str[0] == '-') {
			Signed = 0xff;
			str = str.substr(1, str.length());
		}
		else if (str[0] == '+') {
			str = str.substr(1, str.length());
		}
		for (ULL i = 0; i < str.length(); i++) {
			if (str[i] != '0') {
				str = str.substr(i, str.length());
				break;
			}
		}
		reverse(str.begin(), str.end());
		StringToBCD(str);
	}
	BigInteger(const BigInteger& number);
	~BigInteger();
	BigInteger& operator=(const BigInteger& number);
	bool operator==(BigInteger number) const;
	bool operator>(BigInteger number) const;
	bool operator<(BigInteger number) const;
	bool operator>=(BigInteger number) const;
	bool operator<=(BigInteger number) const;
	friend std::ostream& operator<<(std::ostream& os, BigInteger& number);
};
#endif //_BIG_INTEGER_H_