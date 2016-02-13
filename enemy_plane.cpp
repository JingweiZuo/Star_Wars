//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemy_plane.hpp"


enemy_plane::enemy_plane():Plane::Plane(){
	//initialiser les paramères
	this->x = plane_WIDTH;
	this->y = 0;
}

enemy_plane::~enemy_plane()
{}

/*void enemy_plane::fire()
{
	Bullet* bullet ;
	bullet->setPosition(this->getposition_x()+(this->W)/2,this->getposition_y());
	this->monciel->enemybullets.push_back(bullet);//à vérifier
}*/

void enemy_plane::setposition(int _x,int _y)
{
	x = _x;
	y = _y;
}

int enemy_plane::getvitesse()
{
	return this->vitesse ;
}

// void enemy_plane::move()
// {
// 	this->y += this->vy; 
// }//dans la définition de la class "Ciel"


