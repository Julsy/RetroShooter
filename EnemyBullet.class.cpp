/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:24:18 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 22:42:05 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyBullet.class.hpp"

EnemyBullet::EnemyBullet() : GameObject()
{
	this->_character = '*';
}

EnemyBullet::EnemyBullet(int x, int y) : GameObject('*', x, y, 1) {}

EnemyBullet::EnemyBullet(const EnemyBullet& src) : GameObject(src.getChar(), src.getX(), src.getY(), src.isAlive()) {}

EnemyBullet::~EnemyBullet() {}

void EnemyBullet::makeStep()
{
	this->_xStart -= 2;
	if (this->_xStart < 3)
		this->Die();
}
