#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(x << this->bitsFraction);
};

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = static_cast<int>(roundf(x * (1 << bitsFraction)));
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	this->rawBits = original.getRawBits();
};

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->rawBits = other.getRawBits();
    }
    return *this;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->getRawBits()) / (1 << bitsFraction);
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->bitsFraction);
}

int Fixed::getRawBits(void) const
{
	return (this->rawBits);
};

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}