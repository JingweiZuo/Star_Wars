//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#ifndef __enemy_plane_HPP_
#define __enemy_plane_HPP_

#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Myplane.hpp"

#define plane_WIDTH 50
#define plane_HEIGTH 50


class enemy_plane : public Plane
{

public:
	enemy_plane();
	virtual~enemy_plane();
	//void fire();
	int vitesse = 5;
	void setposition(int _x,int _y);
	int getvitesse();
	// void move();
	
};
#endif
