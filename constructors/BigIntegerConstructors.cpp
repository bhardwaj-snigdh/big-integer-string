#include "../BigInteger.hpp"
#include <stdexcept>

SniBh::BigInteger::BigInteger(const std::string& number, bool sign) :
	digits{ number }, sign{ sign }
{
}

SniBh::BigInteger::BigInteger() :
	digits{ "0" }, sign{ false }
{
}

SniBh::BigInteger::BigInteger(long long sourceNumber) :
	sign { sourceNumber < 0 }
{
	sourceNumber = (sourceNumber < 0) ? -sourceNumber : sourceNumber;
	digits = std::to_string(sourceNumber);
}

SniBh::BigInteger::BigInteger(std::string sourceString) {
	size_t beginIndex{ 0 };
	while (std::isspace(sourceString[beginIndex]))
		++beginIndex;

	if (!std::isdigit(sourceString[beginIndex]) && sourceString[beginIndex] != '-' && sourceString[beginIndex] != '+')
		throw std::invalid_argument{ ("Invalid Arguement: Encountered \'" + (sourceString.substr(beginIndex, beginIndex + 1)) + "\', expected string of numbers.\n") };
	
	if (!std::isdigit(sourceString[beginIndex]))
		sign = sourceString[beginIndex++] == '-';
	else
		sign = false;

	while (sourceString[beginIndex] == '0')
		++beginIndex;

	size_t endIndex{ beginIndex };
	while (std::isdigit(sourceString[endIndex]))
		++endIndex;
	
	digits = sourceString.substr(beginIndex, endIndex - beginIndex);

	if (digits.length() == 0)
		throw std::invalid_argument{ "Invalid Arguement: No numbers found.\n" };
}

SniBh::BigInteger::BigInteger(const BigInteger& sourceNumber) :
	digits{ sourceNumber.digits }, sign{ sourceNumber.sign }
{
}