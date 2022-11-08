/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:12:26 by mriant            #+#    #+#             */
/*   Updated: 2022/11/08 17:47:19 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.h"

int pow_2(unsigned int n)
{
	if (n == 0)
		return 1;
	int result = 2;
	for (unsigned int i = 1; i < n; i++)
		result *= 2;
	return result;
}

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "=== a and b ===" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "=== ++a" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << "=== a++" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "=== a + b ===" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << "=== a - b ===" << std::endl;
	std::cout << a - b << std::endl;
	std::cout << "=== a * b ===" << std::endl;
	std::cout << a * b << std::endl;
	std::cout << "=== a / b ===" << std::endl;
	std::cout << a / b << std::endl;

	std::cout << "=== a < b ===" << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << "=== a > b ===" << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << "=== a <= b ===" << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << "=== a >= b ===" << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << "=== a == b ===" << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << "=== a != b ===" << std::endl;
	std::cout << (a != b) << std::endl;
	
	std::cout << "=== max (a and b) ===" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "=== min (a and b) ===" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	
	std::cout << "=== --a ===" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << "=== a-- ===" << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	return 0;
}