/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:44 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/25 21:00:44 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int raw) : _rawBits(raw << _numFracBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fp) :_rawBits(roundf(fp * (1 << _numFracBits))) {
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return float(_rawBits) / float(1 << _numFracBits);
}

int Fixed::toInt(void) const {
	return (_rawBits >> _numFracBits);
}

int Fixed::getRawBits(void) const {
	return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}


std::ostream	&operator<<(std::ostream &o, const Fixed &fixed) {
	o << fixed.toFloat();
	return (o);
}