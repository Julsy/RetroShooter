/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:07:58 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 21:58:27 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

Bullet::Bullet() : GameObject()
{
	this->_character = '-';
}

Bullet::Bullet(int x, int y) : GameObject('-', x, y, 1) {}

Bullet::Bullet(const Bullet& src) : GameObject(src.getChar(), src.getX(), src.getY(), src.isAlive()) {}

Bullet::~Bullet() {}

void Bullet::makeStep()
{
	this->_xStart++;
	if (this->_xStart < 1)
		this->Die();	
}
