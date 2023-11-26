/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:01:57 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/25 19:44:53 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(int const raw);
		Fixed(const Fixed& other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed& operator=(const Fixed& other);
	private:
		int _rawBits;
};