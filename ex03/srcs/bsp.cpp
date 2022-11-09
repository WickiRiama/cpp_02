/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:00:27 by mriant            #+#    #+#             */
/*   Updated: 2022/11/09 17:47:56 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

int pow_2(unsigned int n)
{
	if (n == 0)
		return 1;
	int result = 2;
	for (unsigned int i = 1; i < n; i++)
		result *= 2;
	return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	(void)a;
	(void)b;
	(void)c;
	(void)point;
	return true;
}