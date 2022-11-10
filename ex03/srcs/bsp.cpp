/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:00:27 by mriant            #+#    #+#             */
/*   Updated: 2022/11/10 17:13:05 by mriant           ###   ########.fr       */
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

Fixed triangle_area(Point const a, Point const b, Point const c) {
	Fixed area = (a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY())
			+ c.getX() * (a.getY() - b.getY())) / 2;
	if (area < 0) {
		area = area * -1;
	}
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed area_abc = triangle_area(a, b, c);
	Fixed area_abp = triangle_area(a, b, point);
	Fixed area_bcp = triangle_area(b, c, point);
	Fixed area_acp = triangle_area(a, c, point);

	if (area_abc == 0 || area_abp == 0 || area_acp == 0 || area_bcp == 0)
		return false;
	else if (area_abc == area_abp + area_acp + area_bcp)
		return true;
	return false;
}