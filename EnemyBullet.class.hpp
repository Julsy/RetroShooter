/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:24:53 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 21:59:31 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_BULLET_HPP
# define ENEMY_BULLET_HPP

#include "GameObject.class.hpp"

class EnemyBullet : public GameObject
{
public:
	EnemyBullet();
	EnemyBullet(int x, int y);
	~EnemyBullet();
	EnemyBullet(EnemyBullet const & src);
	using GameObject::operator=;
	void makeStep();
};

#endif
