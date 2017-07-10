/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:06:41 by iiliuk            #+#    #+#             */
/*   Updated: 2017/07/09 22:10:53 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

#include "GameObject.class.hpp"

class Bullet : public GameObject
{
public:
	Bullet();
	Bullet(int x, int y);
	~Bullet();
	Bullet(Bullet const & src);
	using GameObject::operator=;
	void makeStep();
};

#endif
