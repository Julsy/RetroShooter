/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:20:08 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 22:50:08 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.class.hpp"

GameObject::GameObject(void) {}

GameObject::GameObject(GameObject const &src) { *this = src; }

GameObject const &	GameObject::operator=(GameObject const & rhs)
{
	(void)rhs;
	return *this;
}

GameObject::GameObject(char c, int x, int y, int life) : _character(c), _xStart(x), _yStart(y), _life(life) {}

int GameObject::getX() const { return this->_xStart; }

int GameObject::getY() const { return this->_yStart; }

void GameObject::setX(int x) { this->_xStart = x; }

void GameObject::setY(int y) { this->_yStart = y; }

char GameObject::getChar() const { return this->_character; }

void GameObject::makeAlive() { this->_life = 1; }

void GameObject::setLife() { this->_life -= 1; }

void GameObject::Die() { this->_life = 0; }

int GameObject::isAlive() const { return this->_life; }

int GameObject::getPrevX() { return _prevX; }

int GameObject::getPrevY() { return _prevY; }

void GameObject::saveState()
{
	_prevX=_xStart;
	_prevY=_yStart;
}

void GameObject::makeStep()
{
	this->_xStart--;
	if (this->_xStart < 3)
		this->Die();
}

bool GameObject::hasJustDied()
{
	bool tmp = this->justDied;
	this->justDied = 0;
	return tmp;
}

bool GameObject::colision(int x, int y) { return ((_xStart == x && _yStart == y) || (_xStart == x - 1 && _yStart == y)); }

GameObject::~GameObject(void) {}
