/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:14:49 by abba          #+#    #+#                 */
/*   Updated: 2022/04/06 16:14:49 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "copy constructor called" << std::endl;
//	copy.operator=(copy);
	this->_value = copy.getRawBits();
}

Fixed::Fixed(int const value)
{
	std::cout << "int constructor called" << std::endl;
	_value = value << _bits;
	return;
}

Fixed::Fixed(float const value)
{
	std::cout << "float constructor called" << std::endl;
	_value = (int)roundf(value * (1 << _bits));
	return;
}

Fixed &Fixed::operator= (Fixed const & fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &output, Fixed const & fixed)
{
	output << fixed.toFloat();
	return output;
}

float Fixed::toFloat(void) const
{
	return (float)(_value / (float)(1 << _bits));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int Fixed::toInt(void) const
{
	return _value >> _bits;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
