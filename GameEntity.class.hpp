/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:34:31 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 21:59:55 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_H
# define GAMEENTITY_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "GameObject.class.hpp"
#include "Enemy.class.hpp"
#include "EnemyBullet.class.hpp"
#include "Bullet.class.hpp"
#include "Player.class.hpp"

class GameEntity
{
public:
	Enemy 	*enemyObj;
	Player	*spaceX;
	Bullet	*bullets;
	EnemyBullet *enemy_bullets;
	GameEntity(WINDOW *win);
	~GameEntity();
	void	display();
	bool	collision();		
	void	addWave(int waveSize);
	void	shootBullets(int amount);
	int		isSpaceAvailable(int x, int y);
	void 	shootEnemyBullets(int shootSize);
	Player 	*getPlayer();
	int 	getmv();
	int 	getMaxX();
	int 	getMaxY();
protected:
	GameEntity();
	int		_xMax;
	int		_yMax;
	WINDOW 	*_curwin;
};

#endif
