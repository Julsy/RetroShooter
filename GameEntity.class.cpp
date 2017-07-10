/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:54:28 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/10 15:54:31 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.class.hpp"
#include <cstdlib>
#include <unistd.h>

GameEntity::GameEntity() {}

GameEntity::GameEntity(WINDOW *win)
{
	_curwin = win;
	getmaxyx(_curwin, _yMax, _xMax);
	srand(time(NULL));
	enemyObj = new Enemy[500];
	spaceX = new Player();
	bullets = new Bullet[500];
	enemy_bullets = new EnemyBullet[500];
}

int GameEntity::getmv() { return (wgetch(_curwin)); }

int GameEntity::getMaxX() {	return _xMax; }

int GameEntity::getMaxY() { return _yMax; }

void GameEntity::addWave(int waveSize)
{
	for (int i = 0; i < 500; i++)
	{
		if (!enemyObj[i].isAlive())
		{
			int setTries = 0;
			int yPos = (rand() % (_yMax - 2)) + 1;
			while (!isSpaceAvailable(_xMax - 2, yPos) && setTries < 11)
			{
				setTries++;
				yPos = (rand() % (_yMax - 2)) + 1;
			}
			if (setTries < 11)
			{
				enemyObj[i].setX(_xMax - 2);
				enemyObj[i].setY(yPos);
				enemyObj[i].makeAlive();
				waveSize--;
			}
		}
		if (waveSize < 1)
			break;
	}
}

void GameEntity::shootBullets(int waveSize)
{
	for (int i = 0; i < 500; i++)
	{
		if (!bullets[i].isAlive())
		{
			bullets[i].setX(spaceX->getX() + 1);
			bullets[i].setY(spaceX->getY());
			bullets[i].makeAlive();
			waveSize--;
		}
		if (waveSize < 1)
			break;
	}
}

void GameEntity::shootEnemyBullets(int shootSize)
{
	for (int i = 0; i < 500; i++)
	{
		if (enemyObj[i].isAlive())
		{

			int canShoot = 1;
			for(int j = 0; j < 500; j++)
			{
				if((enemyObj[j].isAlive() 
					&& enemyObj[j].getX() - 20 > spaceX->getX() 
					&& (enemyObj[i].getY() == enemyObj[j].getY() 
					&& enemyObj[i].getX() > enemyObj[j].getX()))
					|| (enemyObj[i].getX() < enemy_bullets[j].getX() + 100
					&& enemyObj[i].getY() == enemy_bullets[j].getY()))
				{
					canShoot = 0;
					break;
				}
			}
			if(canShoot)
			{
				for (int j = 0; j < 500; j++)
				{
					if (!enemy_bullets[j].isAlive())
					{
						enemy_bullets[j].setX(enemyObj[i].getX() - 2);
						enemy_bullets[j].setY(enemyObj[i].getY());
						enemy_bullets[j].makeAlive();
						shootSize--;
						break;
					}
				}
			}
		}
		if (shootSize < 1)
			break;
	}
}

Player *GameEntity::getPlayer()
{
	return spaceX;
}

int GameEntity::isSpaceAvailable(int x, int y)
{
	for (int i = 0; i < 500; i++)
	{
		if (enemyObj[i].getX() == x && enemyObj[i].getY() == y)
			return 0;
	}
	return 1;
}

void	GameEntity::display()
{
	int i = 0;
	while (i < 500)
	{
		if (enemyObj[i].isAlive() || enemyObj[i].hasJustDied())
		{
			mvwaddch(_curwin, enemyObj[i].getY(), enemyObj[i].getX(), ' ');
			if (enemyObj[i].isAlive())
			{
				enemyObj[i].makeStep();
				if (enemyObj[i].isAlive())
				{
					if (enemyObj[i].getChar() == '%')
					{
						wattron(_curwin, COLOR_PAIR(7));
						mvwaddch(_curwin, enemyObj[i].getY(), enemyObj[i].getX(), enemyObj[i].getChar());
						wattroff(_curwin, COLOR_PAIR(7));
					}
					if (enemyObj[i].getChar() == '#')
					{
						wattron(_curwin, COLOR_PAIR(3));
						mvwaddch(_curwin, enemyObj[i].getY(), enemyObj[i].getX(), enemyObj[i].getChar());
						wattroff(_curwin, COLOR_PAIR(3));
					}
					if (enemyObj[i].getChar() == '&')
					{
						wattron(_curwin, COLOR_PAIR(13));
						mvwaddch(_curwin, enemyObj[i].getY(), enemyObj[i].getX(), enemyObj[i].getChar());
						wattroff(_curwin, COLOR_PAIR(13));
					}
				}
			}
		}
		if (bullets[i].getX()>_xMax - 5)
			bullets[i].Die();
		if (bullets[i].isAlive() || bullets[i].hasJustDied())
		{
			mvwaddch(_curwin, bullets[i].getY(), bullets[i].getX(), ' ');
			if (bullets[i].isAlive())
			{
				bullets[i].makeStep();
				if (bullets[i].isAlive())
				{
					wattron(_curwin, COLOR_PAIR(5));
					mvwaddch(_curwin, bullets[i].getY(), bullets[i].getX(), bullets[i].getChar());
					wattron(_curwin, COLOR_PAIR(5));
				}
			}
		}
		if (enemy_bullets[i].isAlive() || enemy_bullets[i].hasJustDied())
		{
			mvwaddch(_curwin, enemy_bullets[i].getY(), enemy_bullets[i].getX(), ' ');
			if(enemy_bullets[i].isAlive())
			{
				enemy_bullets[i].makeStep();
				if (enemy_bullets[i].isAlive())
					mvwaddch(_curwin, enemy_bullets[i].getY(), enemy_bullets[i].getX(), enemy_bullets[i].getChar());
			}
		}
		i++;
	}
	if (spaceX->isAlive())
	{
		mvwaddch(_curwin, spaceX->getPrevY(), spaceX->getPrevX(), ' ');
		if (spaceX->getY() > _yMax - 2)
			spaceX->setY(_yMax - 2);
		if (spaceX->getX() > _xMax - 2)
			spaceX->setX(_xMax - 2);
		if (spaceX->isAlive())
		{
			wattron(_curwin, COLOR_PAIR(10));
			mvwaddch(_curwin, spaceX->getY(), spaceX->getX(), spaceX->getChar());
			wattroff(_curwin, COLOR_PAIR(10));
		}
	}
	refresh();
	wrefresh(_curwin);
}

bool	GameEntity::collision()
{
	for (int i = 0; i < 500; i++)
	{
		if (enemyObj[i].isAlive())
			for(int j = 0; j < 500; j++)
			{
				if (bullets[j].isAlive() && (enemyObj[i].colision(bullets[j].getX(), bullets[j].getY())))
				{
					bullets[j].Die();
					enemyObj[i].Die();
				}
			}
		if (enemyObj[i].isAlive() && (enemyObj[i].colision(spaceX->getX(), spaceX->getY())))
		{
			enemyObj[i].Die();
			spaceX->setLife();
			system("afplay -t 20 ./mp3/explode.mp3 &");
			wattron(_curwin, COLOR_PAIR(4));
			mvwprintw(_curwin, enemyObj[i].getY(), enemyObj[i].getX(), "*");
			wattron(_curwin, COLOR_PAIR(4));
		}
		if (enemy_bullets[i].isAlive() && (enemy_bullets[i].colision(spaceX->getX(), spaceX->getY())))
		{
			enemy_bullets[i].Die();
			spaceX->setLife();
		}
		if (!spaceX->isAlive())
			return 1;
	}
	for (int j = 0; j < 500; ++j)
	{
		for (int k = 0; (k < 500 && bullets[j].isAlive()); ++k)
		{
			if (enemyObj[k].isAlive() && bullets[j].colision(enemyObj[k].getX(), enemyObj[k].getY()))
			{
				bullets[j].Die();
				enemyObj[k].Die();
				system("afplay -t 20 ./mp3/hail.mp3 &");
				spaceX->setScore();
			}
		}
	}
	return 0;
}

GameEntity::~GameEntity(void) {}
