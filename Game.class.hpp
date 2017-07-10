/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:54:35 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/10 15:54:36 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include "Player.class.hpp"
#include "Enemy.class.hpp"
#include "EnemyBullet.class.hpp"
#include "Bullet.class.hpp"
#include "GameEntity.class.hpp"
#include "GameObject.class.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Game
{
public:
	Game();
	Game(Game const &);
	~Game();
	Game const & operator=(Game const &);
	void 	start();
	int		getmv(GameEntity game);
	int 	scoreBoard(WINDOW *score, int scorestart, GameEntity game);

};

#endif
