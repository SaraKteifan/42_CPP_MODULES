#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractional_bits = 8;

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int int_num)
{
	this->value = int_num << Fixed::fractional_bits;
}

Fixed::Fixed(const float float_num)
{
	this->value = roundf(float_num * (1 << Fixed::fractional_bits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return(*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits( void ) const
{
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	float	float_value = static_cast<float>(this->value) / (1 << Fixed::fractional_bits);
	return (float_value);
}

int	Fixed::toInt( void ) const
{
	int	int_value = this->value >> Fixed::fractional_bits;
	return (int_value);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->value > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->value < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->value >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->value <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->value == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->value != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	result;
	long long	add = this->value + rhs.getRawBits();
	result.value = static_cast<int>(add);
	return(result);
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	result;
	long long	subtract = this->value - rhs.getRawBits();
	result.value = static_cast<int>(subtract);
	return(result);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed	result;
	long long	multiply = (this->value * rhs.getRawBits()) >> Fixed::fractional_bits;
	result.value = static_cast<int>(multiply);
	return(result);
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed	result;
	long long	divide = (this->value << Fixed::fractional_bits) / rhs.getRawBits();
	result.value = static_cast<int>(divide);
	return(result);
}

Fixed&	Fixed::operator++()
{
	this->value++;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result(*this);
	this->value++;
	return(result);
}

Fixed&	Fixed::operator--()
{
	this->value--;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result(*this);
	this->value--;
	return(result);
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

