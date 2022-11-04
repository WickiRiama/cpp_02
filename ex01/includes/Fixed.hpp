/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:35:01 by mriant            #+#    #+#             */
/*   Updated: 2022/11/04 18:11:27 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int _value;
	static const int _fractionBits;

public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(int const nb);
	Fixed(int const nb);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void);
	int toInt(void);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif