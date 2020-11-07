#include "../BigInteger.hpp"


SniBh::BigInteger SniBh::operator+(const std::string& augend, const BigInteger& addend) {
	return (BigInteger{ augend } + addend);
}

SniBh::BigInteger SniBh::operator+(const long long& augend, const BigInteger& addend) {
	return (BigInteger{ augend } + addend);
}


SniBh::BigInteger SniBh::operator-(const std::string& minuend, const BigInteger& subtrahend) {
	return (BigInteger{ minuend } - subtrahend);
}

SniBh::BigInteger SniBh::operator-(const long long& minuend, const BigInteger& subtrahend) {
	return (BigInteger{ minuend } - subtrahend);
}


SniBh::BigInteger SniBh::operator*(const std::string& multiplicand, const BigInteger& multiplier) {
	return (BigInteger{ multiplicand } * multiplier);
}

SniBh::BigInteger SniBh::operator*(const long long& multiplicand, const BigInteger& multiplier) {
	return (BigInteger{ multiplicand } * multiplier);
}


SniBh::BigInteger SniBh::operator/(const std::string& dividend, const BigInteger& divisor) {
	return (BigInteger{ dividend } / divisor);
}

SniBh::BigInteger SniBh::operator/(const long long& dividend, const BigInteger& divisor) {
	return (BigInteger{ dividend } / divisor);
}

unsigned long long SniBh::operator%(const std::string& lhs, const BigInteger& rhs) {
	return (std::stoull(lhs) % std::stoull(rhs.digits));
}

unsigned long long SniBh::operator%(const unsigned long long& lhs, const BigInteger& rhs) {
	return (lhs % std::stoull(rhs.digits));
}