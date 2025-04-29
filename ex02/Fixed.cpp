#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed()
    : _fp_number(0)
{
    std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
    std::cout << "Fixed Int Constructer called" << std::endl;
    this->_fp_number = input << this->_frac_bits;
}

Fixed::Fixed(const float input)
{
    std::cout << "Fixed FLoat Constructer called" << std::endl;
    this->_fp_number = roundf(input *(1 << this->_frac_bits));
}

Fixed::Fixed(const Fixed &copy)
    : _fp_number(copy._fp_number)
{
    std::cout << "Fixed Copy Constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Fixed Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Fixed Assignation operator called" << std::endl;
	if (this != &src)
		this->_fp_number = src._fp_number;

	return *this;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->_fp_number > fixed._fp_number);
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->_fp_number < fixed._fp_number);
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->_fp_number >= fixed._fp_number);
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->_fp_number <= fixed._fp_number);
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->_fp_number == fixed._fp_number);
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->_fp_number != fixed._fp_number);
}

Fixed	Fixed::operator+(Fixed fixed) const
{
	return (this->_fp_number + fixed._fp_number);
}

Fixed	Fixed::operator-(Fixed fixed) const
{
	return (this->_fp_number - fixed._fp_number);
}

Fixed	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_fp_number++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_fp_number--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_fp_number;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_fp_number;
	return (tmp);
}

float   Fixed::toFloat(void)const
{
    return((float)this->_fp_number / (float)(1 << this->_frac_bits));
}

int Fixed::toInt(void) const
{
    return (this->_fp_number >> this->_frac_bits);
}

int Fixed::getRawBits(void)const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_fp_number);
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
	this->_fp_number = raw;
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
    if (first.toFloat() <= second.toFloat())
        return(first);
    else
        return (second);
}
const Fixed &Fixed::min(Fixed const &first, Fixed const &second)
{
    if (first.toFloat() <= second.toFloat())
        return (first);
    else
        return (second);
}
Fixed &Fixed::max(Fixed &first, Fixed &second)
{
    if (first.toFloat() >= second.toFloat())
        return (first);
    else
        return (second);
}
const Fixed &Fixed::max(Fixed const &first, Fixed const &second)
{
    if (first.toFloat() >= second.toFloat())
        return(first);
    else
        return (second);
}

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}