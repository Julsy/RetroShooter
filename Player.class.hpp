/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:40:32 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 22:00:34 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <ncurses.h>
#include "GameObject.class.hpp"

class Player : public GameObject
{
public:
	Player();
	~Player();
	Player(Player const & src);
	using GameObject::operator=;
	virtual void makeStep();
	void 	mvup();
	void 	mvdown();
	void	mvleft();
	void	mvright();
	int		getmv();
	int 	getPrevX();
	int 	getPrevY();
	int 	getScore();
	void 	setScore();
	void 	saveState();
private:
	int		_score;
	int 	_prevX;
	int 	_prevY;
};

#endif