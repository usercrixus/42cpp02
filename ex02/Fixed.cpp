#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0)
{
};

Fixed::Fixed(const int x)
{
	this->setRawBits(x << this->bitsFraction);
};

Fixed::Fixed(const float x)
{
	this->rawBits = static_cast<int>(roundf(x * (1 << bitsFraction)));
};

Fixed::~Fixed()
{
};

Fixed::Fixed(const Fixed &original)
{
	this->rawBits = original.getRawBits();
};

Fixed& Fixed::operator=(const Fixed &other)
{
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

Fixed operator+(const Fixed &a, const Fixed &b)
{
    Fixed result;
    result.setRawBits(a.getRawBits() + b.getRawBits());
    return result;
}

Fixed operator*(const Fixed &a, const Fixed &b)
{
    Fixed result;
    result.setRawBits((a.getRawBits() * b.getRawBits()) >> Fixed::bitsFraction);
    return result;
}

Fixed operator-(const Fixed &a, const Fixed &b)
{
    Fixed result;
    result.setRawBits((a.getRawBits() - b.getRawBits()));
    return result;
}

Fixed operator/(const Fixed &a, const Fixed &b)
{
    if (b.getRawBits() == 0)
        throw std::runtime_error("Division by zero");

    Fixed result;
    result.setRawBits((a.getRawBits() << Fixed::bitsFraction) / b.getRawBits());
    return result;
}

Fixed &Fixed::operator++()
{
    this->rawBits++;
    return *this;
}

Fixed &Fixed::operator--()
{
    this->rawBits--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

bool operator>(const Fixed& lhs, const Fixed& rhs)
{
    return lhs.rawBits > rhs.rawBits;
}

bool operator<(const Fixed& lhs, const Fixed& rhs)
{
    return lhs.rawBits < rhs.rawBits;
}

bool operator>=(const Fixed& lhs, const Fixed& rhs)
{
    return lhs.rawBits >= rhs.rawBits;
}

bool operator<=(const Fixed& lhs, const Fixed& rhs)
{
    return lhs.rawBits <= rhs.rawBits;
}

bool operator==(const Fixed& lhs, const Fixed& rhs)
{
    return lhs.rawBits == rhs.rawBits;
}

bool operator!=(const Fixed& lhs, const Fixed& rhs)
{
    return lhs.rawBits != rhs.rawBits;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a.toFloat() < b.toFloat()) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() < b.toFloat()) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a.toFloat() > b.toFloat()) ? a : b;
}

const  Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() > b.toFloat()) ? a : b;
}