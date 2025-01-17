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

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	// io operator
	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
	// Assignment Operator
	Fixed &operator=(const Fixed&);
    // Arithmetic Operators
    friend Fixed operator+(const Fixed& a, const Fixed& b);
    friend Fixed operator-(const Fixed& a, const Fixed& b);
    friend Fixed operator*(const Fixed& a, const Fixed& b);
    friend Fixed operator/(const Fixed& a, const Fixed& b);
    // Increment and Decrement Operators
    Fixed& operator++();              // Pre-increment
    Fixed operator++(int);            // Post-increment
    Fixed& operator--();              // Pre-decrement
    Fixed operator--(int);            // Post-decrement
    // Comparison Operators
    friend bool operator>(const Fixed& lhs, const Fixed& rhs);
    friend bool operator<(const Fixed& lhs, const Fixed& rhs);
    friend bool operator>=(const Fixed& lhs, const Fixed& rhs);
    friend bool operator<=(const Fixed& lhs, const Fixed& rhs);
    friend bool operator==(const Fixed& lhs, const Fixed& rhs);
    friend bool operator!=(const Fixed& lhs, const Fixed& rhs);
};

#endif