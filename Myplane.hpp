//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#ifndef __Myplane_HPP_
#define __Myplane_HPP_

#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Plane.hpp"

#define plane_WIDTH  50
#define plane_HEIGTH 50
#define SCREEN_WIDTH   500
#define SCREEN_HEIGHT  640

using namespace std;

class Myplane : public Plane
{

public:
	Myplane();
    virtual ~Myplane();
	SDL_Event event;
	int vitesse=10;
	//int vie;
	Plane plane;
	void handle_input();
	void move();
	
};

#endif
