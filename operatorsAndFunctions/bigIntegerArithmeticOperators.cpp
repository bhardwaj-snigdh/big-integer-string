#include "../BigInteger.hpp"
#include "../utility/utilityFunctions.hpp"

SniBh::BigInteger SniBh::BigInteger::operator+() const {
	return BigInteger{ *this };
}

SniBh::BigInteger SniBh::BigInteger::operator-() const {
	return BigInteger { this->digits, !this->sign };
}

SniBh::BigInteger SniBh::BigInteger::operator+(const BigInteger& addend) const {
	BigInteger result{ "", false };
	if (this->sign == addend.sign) {
		result.digits = addStrings(this->digits, addend.digits);
		result.sign = this->sign;
	}
	else {
		result = (*this - addend);
		if (this->sign) result.sign = !result.sign;
	}

	return result;
}

SniBh::BigInteger SniBh::BigInteger::operator-(const BigInteger& subtrahend) const {
	return BigInteger{ subtractStrings(this->digits, subtrahend.digits), *this < subtrahend };
}

SniBh::BigInteger SniBh::BigInteger::operator*(const BigInteger& multiplier) const {
	return BigInteger{ multiplyStrings(this->digits, multiplier.digits), bool(this->sign ^ multiplier.sign) };
}

SniBh::BigInteger SniBh::BigInteger::operator/(const BigInteger& divisor) const {
	return BigInteger{ divideStrings(this->digits, divisor.digits), bool(this->sign ^ divisor.sign) };
}

unsigned long long SniBh::BigInteger::operator%(const unsigned long long& number) const {
	unsigned long long remainder{ 0 };
	for (size_t i{ 0 }; i < this->digits.length(); ++i)
		remainder = (remainder * 10 + int(this->digits[i]) - int('0')) % number;
	return remainder;
}

