/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:54:41 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/10 15:54:42 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

Game::Game() { start(); }

Game::Game(Game const &src) { *this = src; }

Game::~Game()
{
	endwin();
	std::cout << "GAME OVER" << std::endl;
	system("afplay -t 20 ./mp3/gameover.mp3 &");
}

Game const &	Game::operator=(Game const & rhs)
{
	(void)rhs;
	return *this;
}

int		Game::scoreBoard(WINDOW *score, int scorestart, GameEntity game)
{
	nodelay(score, TRUE);

	int yMax, xMax;
	getmaxyx(score, yMax, xMax);
	time_t clk = time(NULL);
	int scoretime = 0;
    struct tm *cur_time = localtime(&clk);
    const char *day = cur_time->tm_hour >= 12 ? "PM" : "AM";

    if (cur_time->tm_hour != 0 || cur_time->tm_min != 0 || cur_time->tm_sec != 0)
   		scoretime = cur_time->tm_hour * 1000 + cur_time->tm_min * 100 + cur_time->tm_sec;

	wattron(score, COLOR_PAIR(9));
	mvwprintw(score, 2, 2, "[TIME] %d:%d:%d %s", cur_time->tm_hour % 12 ,cur_time->tm_min,cur_time->tm_sec, day);
	mvwprintw(score, 2, xMax/2 + 20, "SCORE:[%d]", game.spaceX->getScore());
	if (cur_time->tm_hour != 0 || cur_time->tm_min != 0 || cur_time->tm_sec != 0)
		mvwprintw(score, 2, xMax/5 + 10, "GAMETIME: {{%d}} ", scoretime - scorestart);
	wattroff(score, COLOR_PAIR(9));
	
	wattron(score, COLOR_PAIR(3));
	mvwprintw(score, 2, xMax - 13, "LIFE : [%d] ", game.spaceX->isAlive());
	wattroff(score, COLOR_PAIR(3));
	
	refresh();
	wrefresh(score);
	if (scoretime - scorestart == 7)
		system("say 'Hey. PLAYER i am your father. Hard Mode Engaged'");
	if (scoretime - scorestart > 7)
	{
		wattron(score, COLOR_PAIR(3));
		mvwprintw(score, 2, xMax/2 - 6, "[HARD MODE]");
		wattroff(score, COLOR_PAIR(3));
		wrefresh(score);
		return (1);
	}
	return (0);
}

void	Game::start()
{
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	int hardmode = 0;

	WINDOW 		*playwin = newwin(yMax - 8, xMax - 3, 5, 1);
	WINDOW 		*score = newwin(5, xMax - 3, 0, 1);
	WINDOW		*control = newwin(3, xMax - 3, yMax - 3, 1);
	keypad(playwin, true);

	nodelay(playwin, TRUE);
	wattron(score, COLOR_PAIR(10));
	box(score, 0, 0);
	wattroff(score, COLOR_PAIR(10));
	wattron(playwin, COLOR_PAIR(10));
	box(playwin, 0, 0);
	wattroff(playwin, COLOR_PAIR(10));
	wattron(control, COLOR_PAIR(11));
	box(control, 0, 0);
	wattroff(control, COLOR_PAIR(11));
	wattron(control, COLOR_PAIR(3));
	mvwprintw(control, 1, 20, "CONTROLS:      [SPACEBAR]: Shoot      |      [KEY_ARROWS]: Movement     |     [X]: Exit     |     [HAPPINESS]: Living");
	wattroff(control, COLOR_PAIR(3));
	refresh();
	wrefresh(control);
	wrefresh(playwin);
	
	time_t clk = time(NULL);
    struct tm *cur_time = localtime(&clk);
	int scorestart = 0;
	if (cur_time->tm_hour != 0 || cur_time->tm_min != 0 || cur_time->tm_sec != 0)
		scorestart = cur_time->tm_hour * 1000 + cur_time->tm_min * 100 + cur_time->tm_sec;

	GameEntity game(playwin);

	int i = 0;
	while (getmv(game)!='x')
	{
		if(i % 10 == 0)
		{
			game.addWave(1);
			if (hardmode == 1)
				game.shootEnemyBullets(2);
		}
		game.display();
		if (game.collision())
			break ;
		hardmode = scoreBoard(score, scorestart, game);
		wrefresh(score);
		wrefresh(playwin);
		usleep(30000);
	}
	endwin();
}

int		Game::getmv(GameEntity game)
{
	int choice = game.getmv();

	switch(choice)
	{
		case KEY_UP:
			game.getPlayer()->mvup();
			break;
		case KEY_DOWN:
			game.getPlayer()->mvdown();
			break;
		case KEY_LEFT:
			game.getPlayer()->mvleft();
			break;
		case KEY_RIGHT:
			game.getPlayer()->mvright();
			break;
		case 32:
			game.shootBullets(1);
			system("afplay -t 20 ./mp3/laser.mp3 &");
			break;
		default:
			break;
	}
	return choice;
}
