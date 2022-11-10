/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:17 by mriant            #+#    #+#             */
/*   Updated: 2022/11/10 15:14:18 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.h"

int main(void) {
	Point a(-2, 5);
	Point b(-4, 1);
	Point c(2, 1);
	Point point_in(-2, 3);
	Point point_out(2, 4);
	Point point_edge(-3, 3);

	std::cout << "in " << bsp(a, b, c, point_in) << std::endl;
	std::cout << "out " << bsp(a, b, c, point_out) << std::endl;
	std::cout << "edge " << bsp(a, b, c, point_edge) << std::endl;
	return 0;
}