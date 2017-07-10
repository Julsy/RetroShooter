/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:23:52 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 21:59:03 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "GameObject.class.hpp"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(int xStart, int yStart);
	~Enemy();
	Enemy(Enemy const & src);
	using GameObject::operator=;
};

#endif
