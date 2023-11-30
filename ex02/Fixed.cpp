/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:44 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/30 15:50:58 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {

}

Fixed::~Fixed() {

}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::Fixed(const int raw) : _rawBits(raw << _numFracBits) {

}

Fixed::Fixed(const float fp) :_rawBits(roundf(fp * (1 << _numFracBits))) {

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

Fixed&	Fixed::min(Fixed& left, Fixed& right) {
	if (right.toFloat() < left.toFloat())
		return (right);
	return (left);
}

const Fixed&	Fixed::min(const Fixed& left, const Fixed& right) {
	if (right.toFloat() < left.toFloat())
		return (right);
	return (left);
}

Fixed&	Fixed::max(Fixed& left, Fixed& right) {
	if (right.toFloat() > left.toFloat())
		return (right);
	return (left);
}

const Fixed&	Fixed::max(const Fixed& left, const Fixed& right) {
	if (right.toFloat() > left.toFloat())
		return (right);
	return (left);
}

// post/pre increment and decrement

Fixed&	Fixed::operator++(void)
{
	_rawBits += 1;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;

	(this->_rawBits) +=1;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;

	(this->_rawBits) -=1;
	return (tmp);
}

//Arithmetic

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator+(const Fixed& other) {
	Fixed add = Fixed(toFloat() + other.toFloat());
	_rawBits = add.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator-(const Fixed& other) {
	Fixed add = Fixed(toFloat() - other.toFloat());
	_rawBits = add.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator*(const Fixed& other) {
	Fixed add = Fixed(toFloat() * other.toFloat());
	_rawBits = add.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed& other) {
	Fixed add = Fixed(toFloat() / other.toFloat());
	_rawBits = add.getRawBits();
	return (*this);
}

//Comparison

bool	Fixed::operator<(const Fixed& other) {
	return (toFloat() < other.toFloat());
}

bool	Fixed::operator>(const Fixed& other) {
	return (toFloat() > other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) {
	return (toFloat() <= other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) {
	return (toFloat() >= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other) {
	return (_rawBits == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) {
	return (_rawBits != other.getRawBits());
}

//Stream

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed) {
	o << fixed.toFloat();
	return (o);
}