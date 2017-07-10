/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:55:38 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/10 15:55:40 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player() : GameObject('>', 10, 10, 3) {}

Player::Player(const Player& src) : GameObject(src.getChar(), src.getX(), src.getY(), src.isAlive()) {}

Player::~Player() {}

int Player::getPrevX() { return _prevX; }

int Player::getPrevY() { return _prevY; }

void Player::makeStep() {}

void Player::saveState()
{
	_prevX=_xStart;
	_prevY=_yStart;
}

int Player::getScore() { return _score; }

void Player::setScore() { _score += 10; }

void 	Player::mvup()
{
	saveState();
	_yStart--;
	if (_yStart < 1)
		_yStart = 1;
}

void 	Player::mvdown()
{
	saveState();
	_yStart++;
}

void 	Player::mvleft()
{
	saveState();
	_xStart--;
	if (_xStart < 3)
		_xStart = 3;
}

void 	Player::mvright()
{
	saveState();
	_xStart++;
}
