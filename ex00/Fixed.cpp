/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:44 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/24 16:21:26 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &point)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = point.getRawBits();
}

Fixed::Fixed(int const raw)
{
	_rawBits = raw;
	std::cout << "Fixed point overload constructor" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

Fixed Fixed::operator=(const Fixed &comp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = comp.getRawBits();
	return (*this);
}
