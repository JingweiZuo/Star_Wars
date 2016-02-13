//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#ifndef __Plane_HPP_
#define __Plane_HPP_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Element.hpp"

#define SCREEN_WIDTH   500
#define SCREEN_HEIGHT  640
#define plane_WIDTH 50
#define plane_HEIGTH 50

class Plane: public Element
{
private:
int vie = 1;

public:
	int vx;
	int vy;
	Plane();
    virtual ~Plane();
    
	int getvx();
	int getvy();
	int get_vie();
	void perdre_vie();
	bool mort();
	bool collision_avec_plane(Plane plane);
	
	
};
#endif
