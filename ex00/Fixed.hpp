/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:01:57 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/25 20:20:27 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(int const raw);
		Fixed(const Fixed& other);
	
		int getRawBits(void) const;
		void setRawBits(int const raw);
	
		Fixed& operator=(const Fixed& other);
	private:
		int					_rawBits;
		static const int	_numFracBits = 8;
};