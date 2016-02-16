//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#ifndef __Ciel_HPP_
#define __Ciel_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <list>
#include "Myplane.hpp"
#include "enemy_plane.hpp"
#include "Bullet.hpp"

using namespace std;

#define SCREEN_WIDTH   500
#define SCREEN_HEIGHT  640
#define plane_WIDTH 50
#define plane_HEIGTH 50

class Ciel
{
public:
    list <Bullet> myplanebullets ;
    list <Bullet> enemybullets;
    list <enemy_plane> enemy_planes;
    list <Bullet> ::iterator it_bullet;
    list <enemy_plane> ::iterator it_enemy;
    SDL_Surface *notes= NULL;
    Myplane myplane;

	Ciel();
    virtual ~Ciel();
    void creer_enemy();
    void enemy_fire();
    void myplane_fire();
    void bullet_enemy_move();
    void mise_a_jour();
	
};
#endif
