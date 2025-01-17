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
	Fixed &operator=(const Fixed&);

	float toFloat( void ) const;
	int toInt( void ) const;

	void setRawBits(int const raw);
	int getRawBits(void) const;

	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif