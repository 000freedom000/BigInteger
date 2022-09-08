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
	P = new UC[count];
	for (long long i = str.length() - 1; i >= 0; i--) {
		P[str.length()-i-1] = (unsigned char)(str[i] - 48);
	}
}
BigInteger::BigInteger(const BigInteger& number)
{
	{
		this->Signed = number.Signed;
		this->count = number.count;
		this->P = new UC[this->count];
		for (ULL i = 0; i < this->count; i++) {
			this->P[i] = number.P[i];
		}
	}
}
BigInteger::~BigInteger()
{
	delete[] P;
	count = 0;
	Signed = 0;
}
BigInteger& BigInteger::operator=(const BigInteger& number) {
	this->count = number.count;
	this->Signed = number.Signed;
	if (this->P != nullptr) {
		delete[]P;
	}
	this->P = new unsigned char[this->count];
	for (ULL i = 0; i < this->count; i++) {
		this->P[i] = number.P[i];
	}
	return *this;
}
bool BigInteger::operator==(BigInteger number) const
{
	if (this->Signed != number.Signed) {
		return false;
	}
	if (this->count != number.count) {
		return false;
	}
	for (ULL i = 0; i < this->count; i++) {
		if (this->P[i] != number.P[i]) {
			return false;
		}
	}
	return true;
}

bool BigInteger::operator>(BigInteger number)const
{
	if (this->Signed < number.Signed) {
		return true;
	}
	if (this->Signed > number.Signed) {
		return false;
	}
	if (this->count > number.count) {
		return true;
	}
	if (this->count < number.count) {
		return false;
	}
	for (ULL i = 0; i < this->count; i++) {
		if (this->P[i] > number.P[i]) {
			return true;
		}
		if (this->P[i] < number.P[i]) {
			return false;
		}
	}
	return false;
}

bool BigInteger::operator<(BigInteger number)const
{
	if (this->Signed > number.Signed) {
		return true;
	}
	if (this->Signed < number.Signed) {
		return false;
	}
	if (this->count < number.count) {
		return true;
	}
	if (this->count > number.count) {
		return false;
	}
	for (ULL i = 0; i < this->count; i++) {
		if (this->P[i] < number.P[i]) {
			return true;
		}
		if (this->P[i] > number.P[i]) {
			return false;
		}
	}
	return false;
}

bool BigInteger::operator>=(BigInteger number)const
{
	return this->operator==(number) || this->operator>(number);
}

bool BigInteger::operator<=(BigInteger number)const
{
	return this->operator==(number) || this->operator<(number);
}

std::ostream& operator<<(std::ostream& os, BigInteger& number)
{
	int temp;
	if (number.Signed) {
		os << "-";
	}
	for (ULL i = 0; i < number.count; i++) {
		temp = number.P[i];
		os << temp;
	}
	return os;
}