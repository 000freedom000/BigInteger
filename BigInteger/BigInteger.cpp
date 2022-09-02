#include"BigInteger.h"
BigInteger::BigInteger()
{
	count = 1;
	Signed = 0;
	P = new UC[count];
	P[0] = 0;
}
void BigInteger::StringToBCD(std::string str)
{
	count = str.length();
	P = new unsigned char[count];
	for (long long i = str.length() - 1; i >= 0; i--) {
		P[str.length()-i-1] = (unsigned char)(str[i] - 48);
	}
}
std::ostream& operator<<(std::ostream& os, BigInteger& number)
{
	int temp;
	if (number.Signed) {
		os << "-";
	}
	for (unsigned long long i = 0; i < number.count; i++) {
		temp = number.P[i];
		os << temp;
	}
	return os;
}