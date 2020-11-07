#include "../BigInteger.hpp"

bool SniBh::operator==(const std::string& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } == rhs);
}

bool SniBh::operator==(const long long& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } == rhs);
}


bool SniBh::operator!=(const std::string& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } != rhs);
}

bool SniBh::operator!=(const long long& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } != rhs);
}


bool SniBh::operator<(const std::string& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } < rhs);
}

bool SniBh::operator<(const long long& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } < rhs);
}


bool SniBh::operator<=(const std::string& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } <= rhs);
}

bool SniBh::operator<=(const long long& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } <= rhs);
}


bool SniBh::operator>(const std::string& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } > rhs);
}

bool SniBh::operator>(const long long& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } > rhs);
}


bool SniBh::operator>=(const std::string& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } >= rhs);
}

bool SniBh::operator>=(const long long& lhs, const BigInteger& rhs) {
	return (BigInteger{ lhs } >= rhs);
}