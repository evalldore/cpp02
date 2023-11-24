/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:01:57 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/24 16:09:44 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		Fixed();
		Fixed(int const raw);
		Fixed(const Fixed &comp);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed operator=(const Fixed &comp);
	private:
		int _rawBits;
};