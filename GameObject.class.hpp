/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:19:56 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 22:10:16 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>

class GameObject
{
public:
	GameObject(char c, int xStart, int yStart, int life);
	GameObject(GameObject const &);
	GameObject const & operator=(GameObject const &);
	~GameObject(void);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void makeAlive();
	char getChar() const;
	void Die();
	void setLife();
	int isAlive() const;
	virtual void makeStep();
	bool colision(int x, int y);
	bool hasJustDied();
	int 	getPrevX();
	int 	getPrevY();
	void 	saveState();
protected:
	GameObject(void);
	char	_character;
	int		_xStart;
	int		_yStart;
	int		_life;
	bool	justDied;
	int 	_prevX;
	int 	_prevY;
};

#endif
