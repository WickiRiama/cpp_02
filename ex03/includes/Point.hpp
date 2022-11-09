/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:02:35 by mriant            #+#    #+#             */
/*   Updated: 2022/11/09 17:09:27 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.h"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &src);
		~Point();

		Point &operator=(Point const &rhs);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

#endif