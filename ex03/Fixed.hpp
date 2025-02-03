#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int rawBits;
	static const int bitsFraction = 8;
public:
	Fixed();
	Fixed(const int x);
	Fixed(const float x);
	~Fixed();
	Fixed (const Fixed&);

	float toFloat( void ) const;
	int toInt( void ) const;

	void setRawBits(int const raw);
	int getRawBits(void) const;

	static int getBitsFraction();

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	Fixed &operator=(const Fixed&);
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
};
// io operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
// Arithmetic Operators
Fixed operator+(const Fixed& a, const Fixed& b);
Fixed operator-(const Fixed& a, const Fixed& b);
Fixed operator*(const Fixed& a, const Fixed& b);
Fixed operator/(const Fixed& a, const Fixed& b);
// Comparison Operators
bool operator>(const Fixed& lhs, const Fixed& rhs);
bool operator<(const Fixed& lhs, const Fixed& rhs);
bool operator>=(const Fixed& lhs, const Fixed& rhs);
bool operator<=(const Fixed& lhs, const Fixed& rhs);
bool operator==(const Fixed& lhs, const Fixed& rhs);
bool operator!=(const Fixed& lhs, const Fixed& rhs);

#endif