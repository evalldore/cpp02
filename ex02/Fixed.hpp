/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:01:57 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/28 13:08:40 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const int raw);
		Fixed(const float fp);
		Fixed(const Fixed& other);

		int						getRawBits(void) const;
		void					setRawBits(int const raw);
		float					toFloat(void) const;
		int						toInt(void) const;

		static Fixed&			min(Fixed& left, Fixed& right);
		static const Fixed&		min(const Fixed& left, const Fixed& right);
		static Fixed&			max(Fixed& left, Fixed& right);
		static const Fixed&		max(const Fixed& left, const Fixed& right);

		Fixed&					operator=(const Fixed& other);
		Fixed&					operator+(const Fixed& other);
		Fixed&					operator-(const Fixed& other);
		Fixed&					operator*(const Fixed& other);
		Fixed&					operator/(const Fixed& other);

		Fixed&					operator++(void);
		Fixed&					operator--(void);
		Fixed					operator++(int n);
		Fixed					operator--(int n);

		bool					operator<(const Fixed& other);
		bool					operator>(const Fixed& other);
		bool					operator<=(const Fixed& other);
		bool					operator>=(const Fixed& other);
		bool					operator==(const Fixed& other);
		bool					operator!=(const Fixed& other);
	private:
		int						_rawBits;
		static const int		_numFracBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);