#pragma once

#ifndef BIG_INTEGER_UTILITY_HPP
#define BIG_INTEGER_UTILITY_HPP

#include <string>
#include <stdexcept>


void inplaceReverse(std::string& str) {
	size_t len = str.length();
	for (size_t i{ 0 }; i < len / 2; ++i) {
		char temp{ str[i] };
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

void stripLeadingZerores(std::string& str) {
	size_t i{ 0 };
	while (str[i] == '0') i++;
	str = str.substr(i, str.length());
	if (str.length() == 0) str = "0";
}

void makeShift(std::string& str, size_t n) {
	for (unsigned i{ 0 }; i < n; ++i)
		str.push_back('0');
}

size_t makeEqualLength(std::string& s1, std::string& s2) {
	size_t maxLen{ (s1.length() > s2.length()) ? s1.length() : s2.length() };

	inplaceReverse(s1);
	for (unsigned i{ 0 }; i < maxLen - s1.length(); ++i)
		s1.push_back('0');

	inplaceReverse(s2);
	for (unsigned i{ 0 }; i < maxLen - s2.length(); ++i)
		s2.push_back('0');

	inplaceReverse(s1);
	inplaceReverse(s2);
	return maxLen;
}

std::string addStrings(std::string lhs, std::string rhs) {
	inplaceReverse(lhs);
	inplaceReverse(rhs);

	size_t minDigits{ (lhs.length() < rhs.length()) ? lhs.length() : rhs.length() };
	size_t maxDigits{ (lhs.length() > rhs.length()) ? lhs.length() : rhs.length() };

	std::string result;

	bool carry{ false };
	for (size_t i{ 0 }; i < minDigits; ++i) {
		short digitsSum{ (lhs[i] - '0') + (rhs[i] - '0') + carry };
		if (digitsSum > 9) {
			carry = true;
			digitsSum -= 10;
		}
		else carry = false;
		result += char(digitsSum + '0');
	}

	auto& remainedDigits{ (lhs.length() > minDigits) ? lhs : rhs };
	for (size_t i{ minDigits }; i < maxDigits; ++i) {
		if (remainedDigits[i] - '0' + carry > 9) {
			carry = true;
			result += char(remainedDigits[i] - 9);
		}
		else {
			result += char(remainedDigits[i] + carry);
			carry = false;
		}
	}
	if (carry)
		result += '1';

	inplaceReverse(result);
	return result;
}

std::string subtractStrings(std::string lhs, std::string rhs) {
	if (lhs == rhs)
		return "0";

	makeEqualLength(lhs, rhs);
	std::string& subtrahend = (lhs < rhs) ? lhs : rhs;
	std::string& minuend = (lhs > rhs) ? lhs : rhs;

	inplaceReverse(minuend);
	inplaceReverse(subtrahend);


	for (size_t i{ 0 }; i < subtrahend.length(); ++i) {
		if (minuend[i] >= subtrahend[i])
			minuend[i] = minuend[i] - subtrahend[i] + '0';
		else {
			minuend[i + 1] -= 1;
			minuend[i] = 10 + minuend[i] - subtrahend[i] + '0';
		}
	}

	for (size_t i{ subtrahend.length() }; i < minuend.length() && minuend[i] == '0' - 1; ++i) {
		minuend[i + 1] -= 1;
		minuend[i] += 10;
	}

	if (*(minuend.end() - 1) == '0')
		minuend.pop_back();

	inplaceReverse(minuend);
	stripLeadingZerores(minuend);
	return minuend;
}

std::string multiplyStrings(std::string lhs, std::string rhs) {
	size_t n = makeEqualLength(lhs, rhs);

	if (n == 1) return std::to_string(std::stoi(lhs) * std::stoi(rhs));

	size_t firstHalf{ n / 2 };
	size_t secondHalf{ n - firstHalf };

	std::string lhsLeftPart{ lhs.substr(0, firstHalf) };
	std::string lhsRightPart{ lhs.substr(firstHalf, secondHalf) };

	std::string rhsLeftPart{ rhs.substr(0, firstHalf) };
	std::string rhsRightPart{ rhs.substr(firstHalf, secondHalf) };

	std::string part1{ multiplyStrings(lhsLeftPart, rhsLeftPart) };
	std::string part2{ multiplyStrings(lhsRightPart, rhsRightPart) };
	std::string part3{ multiplyStrings(addStrings(lhsLeftPart, lhsRightPart), addStrings(rhsLeftPart, rhsRightPart)) };

	stripLeadingZerores(part1);
	stripLeadingZerores(part2);
	stripLeadingZerores(part3);


	std::string tempValue{ subtractStrings(part3, part1) };
	tempValue = subtractStrings(tempValue, part2);

	makeShift(part1, 2 * secondHalf);
	makeShift(tempValue, secondHalf);

	std::string result{ addStrings(tempValue, addStrings(part1, part2)) };
	stripLeadingZerores(result);
	return result;
}

std::string greatestMultipleNotExceeding(const std::string& number, std::string limit) {
	if (number.length() > limit.length()) return "0";

	std::string temp{ std::string(limit.length() - number.length(), '0') + number };

	size_t times = 0;
	while (temp <= limit) {
		temp = addStrings(temp, number);
		makeEqualLength(temp, limit);
		times++;
	}

	return std::to_string(times);
}

unsigned countTrailingZeroes(const std::string& numberString) {
	unsigned trailingZeroes{ 0 };
	for (long i = numberString.length() - 1; i > 0 && numberString[i] == '0'; ++i)
		++trailingZeroes;
	return trailingZeroes;
}

void _balanceDenominator(std::string& denominator, const std::string& numerator) {
	inplaceReverse(denominator);

	if (denominator.length() > numerator.length()) {
		while (denominator.length() > numerator.length() && *(denominator.end() - 1) == '0')
			denominator.pop_back();
	}
	else {
		for (size_t i{ 0 }; i < numerator.length() - denominator.length(); ++i)
			denominator.push_back('0');	
	}

	inplaceReverse(denominator);
}

std::string divideStrings(std::string numerator, std::string denominator) {
	if (denominator == "0")
		throw std::runtime_error{ "Math Error: Division by zero.\n" };

	std::string denominatorToCompare{ denominator };
	size_t trailingZeroes{ countTrailingZeroes(numerator) };

	makeEqualLength(numerator, denominatorToCompare);
	std::string quotient;
	while (numerator >= denominatorToCompare) {
		_balanceDenominator(denominatorToCompare, numerator);
		stripLeadingZerores(numerator);

		std::string numeratorPart{ numerator.substr(0, denominator.length()) };
		std::string times{ greatestMultipleNotExceeding(denominator, numeratorPart) };

		bool isIncreased{ false };
		if (times == "0") {
			isIncreased = true;
			numeratorPart += numerator[denominator.length()];
			times = greatestMultipleNotExceeding(denominator, numeratorPart);
		}

		std::string greatestMultiple{ multiplyStrings(denominator, times) };
		size_t zeroesForPadding{ numerator.length() - numeratorPart.length() };
		makeShift(greatestMultiple, zeroesForPadding);

		numerator = subtractStrings(numerator, greatestMultiple);
		quotient += times;

		_balanceDenominator(denominatorToCompare, numerator);
	}

	if (quotient.length() == 0) quotient = "0";
	else makeShift(quotient, trailingZeroes);
	return quotient;
}

#endif // BIG_INTEGER_UTILITY_HPP