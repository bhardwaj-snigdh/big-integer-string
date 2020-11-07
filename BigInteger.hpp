#pragma once

#ifndef BIGINTEGER_HPP
#define BIGINTEGER_HPP

#include <string>
#include <cctype>

namespace SniBh {
	class BigInteger {
	private:
		std::string digits;
		bool sign;
		
		explicit BigInteger(const std::string&, bool);

	public:
		// Constructors
		BigInteger();
		BigInteger(long long);
		BigInteger(std::string);
		BigInteger(const BigInteger&);
		
		// Unary arithmetic operators
		BigInteger operator+() const;
		BigInteger operator-() const;

		// Arithmetic operators
		BigInteger operator+(const BigInteger&) const;
		BigInteger operator-(const BigInteger&) const;
		BigInteger operator*(const BigInteger&) const;
		BigInteger operator/(const BigInteger&) const;
		unsigned long long operator%(const unsigned long long&) const;

		// Comparision operators
		bool operator==(const BigInteger&) const;
		bool operator!=(const BigInteger&) const;
		bool operator<(const BigInteger&) const;
		bool operator<=(const BigInteger&) const;
		bool operator>(const BigInteger&) const;
		bool operator>=(const BigInteger&) const;

		// Ensuring two way arithmatic and compariosins

		// Arithmatic 
		friend BigInteger operator+(const std::string&, const BigInteger&);
		friend BigInteger operator+(const long long&, const BigInteger&);

		friend BigInteger operator-(const std::string&, const BigInteger&);
		friend BigInteger operator-(const long long&, const BigInteger&);

		friend BigInteger operator*(const std::string&, const BigInteger&);
		friend BigInteger operator*(const long long&, const BigInteger&);

		friend BigInteger operator/(const std::string&, const BigInteger&);
		friend BigInteger operator/(const long long&, const BigInteger&);

		friend unsigned long long operator%(const std::string&, const BigInteger&);
		friend unsigned long long operator%(const unsigned long long&, const BigInteger&);

		// Comparision
		friend bool operator==(const std::string&, const BigInteger&);
		friend bool operator==(const long long&, const BigInteger&);

		friend bool operator!=(const std::string&, const BigInteger&);
		friend bool operator!=(const long long&, const BigInteger&);

		friend bool operator<(const std::string&, const BigInteger&);
		friend bool operator<(const long long&, const BigInteger&);

		friend bool operator<=(const std::string&, const BigInteger&);
		friend bool operator<=(const long long&, const BigInteger&);

		friend bool operator>(const std::string&, const BigInteger&);
		friend bool operator>(const long long&, const BigInteger&);

		friend bool operator>=(const std::string&, const BigInteger&);
		friend bool operator>=(const long long&, const BigInteger&);

		// Math functions
		BigInteger abs() { return BigInteger{ this->digits, false }; }

		// Conversions
		std::string toString() { return (this->sign ? "-" : "") + this->digits; }
		long long toNumber() { return std::stoll(this->digits); }
	};
}

#endif // BIGINTEGER_HPP