/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 13:04:28 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 22:38:34 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

static void	initializer(void)
{
	initscr();
	start_color();
	noecho();
	curs_set(0);
	cbreak();
	timeout(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	init_color(100, 0, 0, 0);
	init_color(101, 100, 100, 100);
	init_color(COLOR_BLUE, 50, 50, 50);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, 101);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_RED, 101);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, 101);
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
	init_pair(8, COLOR_GREEN, 101);
	init_pair(9, COLOR_CYAN, COLOR_BLACK);
	init_pair(10, COLOR_CYAN, COLOR_BLACK);
	init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(12, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(13, COLOR_BLUE, COLOR_BLACK);
	init_pair(14, COLOR_BLUE, 101);
	return ;
}

void	mainMenu(WINDOW *menuwin)
{
	keypad(menuwin, true);
	int left, right, top, bottom, topleftcorner, toprightcorner, bottomleftcorner, bottomrightcorner;
	topleftcorner = toprightcorner = bottomrightcorner = bottomleftcorner = (int)'*';
	left =	(int)'4';
	right = (int)'2';
	top = (int)'+';
	bottom = (int)'+';
	wattron(menuwin, COLOR_PAIR(10));
	wborder(menuwin, left, right, top, bottom, topleftcorner, toprightcorner, bottomleftcorner, bottomrightcorner);
	wattroff(menuwin, COLOR_PAIR(10));
	refresh();
	wrefresh(menuwin);
}

int main()
{
	initializer();

	int 		yMax, xMax;
	int 		choice;
	int 		highlight = 0;

	getmaxyx(stdscr, yMax, xMax);
	WINDOW 	*menuwin = newwin(12, 30, yMax/3, xMax/3 + 5);
	mainMenu(menuwin);
	
	std::string choices[3] = {"PLAY", "FALCON MUSIC", "EXIT"};
	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == highlight)
				wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i + 4, 12, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);
		switch(choice)
		{
			case KEY_UP:
				highlight--;
				system("afplay -t 20 ./mp3/hail.mp3 &");
				if(highlight == -1)
					highlight = 0;
				break;
			case KEY_DOWN:
				system("afplay -t 20 ./mp3/hail.mp3 &");
				highlight++;
				if(highlight == 3)
					highlight = 2;
				break;
			default:
				break;
		}
		if (choice == 10)
			break ;
	}
	clear();
	if (choices[highlight].compare("PLAY") == 0)
		Game play = Game();
	if (choices[highlight].compare("FALCON MUSIC") == 0)
	{
		system("afplay -t 20 ./mp3/falcon.mp3 &");
		system("say 'You are awesome but also i want cookies'");
		Game play = Game();
	}
	endwin();
	return 0;
}
