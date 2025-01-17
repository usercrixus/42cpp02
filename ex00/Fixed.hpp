#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int rawBits;
	static const int bitsFraction = 8;
public:
	Fixed();
	~Fixed();
	Fixed (const Fixed&);
	Fixed &operator=(const Fixed&);

	void setRawBits(int const raw);
	int getRawBits(void) const;
};

#endif