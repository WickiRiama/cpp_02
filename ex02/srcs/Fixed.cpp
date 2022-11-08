/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:36:04 by mriant            #+#    #+#             */
/*   Updated: 2022/11/08 16:26:59 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.h"

const int Fixed::_fractionBits = 8;
const int Fixed::_maxN = pow_2(sizeof(int) * 8 - _fractionBits - 1);

//==============================================================================
//  Constructors Destructor
//==============================================================================

Fixed::Fixed(void) : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const nb)
{
	// std::cout << "Int constructor called" << std::endl;
	if (nb > _maxN - 1 || nb < _maxN * -1)
		std::cout << "Warning: Overflow with value " << nb << std::endl;
	this->_value = nb << _fractionBits;
}

Fixed::Fixed(float const nb)
{
	// std::cout << "Float constructor called" << std::endl;
	if (nb > _maxN - 1 || nb < _maxN * -1)
		std::cerr << "Warning: Overflow with value " << nb << std::endl;
	this->_value = roundf(nb * pow_2(_fractionBits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

//==============================================================================
//  Operators
//==============================================================================

Fixed &Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	if (rhs.getRawBits() == 0)
	{
		std::cerr << "Warning, you tried to divide by 0, no change has been "
				  << "made" << std::endl;
	}
	else
		return Fixed(this->toFloat() / rhs.toFloat());
	return *this;
}

bool Fixed::operator<(Fixed const &rhs)
{
	if (this->_value < rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>(Fixed const &rhs)
{
	if (this->_value > rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const &rhs)
{
	if (this->_value >= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const &rhs)
{
	if (this->_value <= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const &rhs)
{
	if (this->_value == rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const &rhs)
{
	if (this->_value != rhs.getRawBits())
		return true;
	return false;
}

Fixed &Fixed::operator++(void)
{
	this->_value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;

	operator++();
	return old;
}

Fixed &Fixed::operator--(void)
{
	this->_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;

	operator--();
	return old;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

//==============================================================================
// Functions
//==============================================================================

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / pow_2(_fractionBits);
}

int Fixed::toInt(void) const
{
	return this->_value >> _fractionBits;
}

Fixed &Fixed::min(Fixed &a, Fixed&b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	Fixed cpy = a;
	
	if (cpy < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	Fixed cpy = a;

	if (cpy > b)
		return a;
	return b;
}
