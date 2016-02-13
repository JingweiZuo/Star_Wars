//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#ifndef __Bullet_HPP_
#define __Bullet_HPP_

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Plane.hpp"
#include "Element.hpp"

#define SCREEN_WIDTH   500
#define SCREEN_HEIGHT  640
#define bullet_WIDTH 8
#define bullet_HEIGTH 17
#define plane_WIDTH 50
#define plane_HEIGTH 50

class Bullet : public Element
{
public:
	Bullet();
    virtual ~Bullet();
    int vitesse=5;
    void setvitesse(int vitesse);
    int getvitesse();
    void setposition(int _x,int _y);
	bool collision_avec_plane(Plane plane);
    
};

#endif
