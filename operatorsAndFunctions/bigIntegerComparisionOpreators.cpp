#include "../BigInteger.hpp"

bool SniBh::BigInteger::operator==(const BigInteger& comparator) const {
	return (this->digits == comparator.digits) && (this->sign == comparator.sign);
}

bool SniBh::BigInteger::operator!=(const BigInteger& comparator) const {
	return !(*this == comparator);
}

bool SniBh::BigInteger::operator<(const BigInteger& comparator) const {
	if ((this->sign && !comparator.sign) || (this->digits.length() < comparator.digits.length())) return true;
	if ((!this->sign && comparator.sign) || (this->digits.length() > comparator.digits.length())) return false;
	return this->digits < comparator.digits;
}

bool SniBh::BigInteger::operator<=(const BigInteger& comparator) const {
	return (*this < comparator) || (*this == comparator);
}

bool SniBh::BigInteger::operator>=(const BigInteger& comparator) const {
	return !(*this > comparator);
}

bool SniBh::BigInteger::operator>(const BigInteger& comparator) const {
	return !(*this <= comparator);
}