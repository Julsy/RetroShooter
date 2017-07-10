/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:44:26 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 21:58:46 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy() : GameObject()
{
	char	type[3] = {'%', '#', '&'};
	_character = type[rand() % 3];
}

Enemy::Enemy(int x, int y) : GameObject()
{
	char	type[3] = {'%', '#', '&'};
	this->_character = type[rand() % 3];
	this->_xStart = x;
	this->_yStart = y;
	this->_life = 1;
}

Enemy::Enemy(const Enemy& src) : GameObject(src.getChar(), src.getX(), src.getY(), src.isAlive()) {}

Enemy::~Enemy() {}
