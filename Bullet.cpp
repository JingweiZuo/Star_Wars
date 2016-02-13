//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Bullet.hpp"
#include "Element.hpp"


Bullet::Bullet():Element::Element(){
	// Initialiser les positions
	x = (SCREEN_WIDTH - (SCREEN_WIDTH -plane_WIDTH)) / 2;
	y = SCREEN_HEIGHT - plane_HEIGTH - bullet_HEIGTH;
	
}

Bullet::~Bullet(){

}

void Bullet::setvitesse(int vitesse){
	this->vitesse = vitesse;
}

int Bullet::getvitesse(){
	return this->vitesse;
}

void Bullet::setposition(int _x,int _y){
  this->x = _x;
  this->y = _y;
}

/*

void Bullet::move(){
  this->y +=this->vitesse;
}

*/

bool Bullet::collision_avec_plane(Plane plane){//de la forme de boolean, vérifier s'il y a des collision avec plane
	int bottomA = y;
	int bottomB = plane.y;
	int topA = y - plane_HEIGTH;
	int topB = plane.y - plane_HEIGTH;
	int leftA = x;
	int leftB = plane.x;
	int rightA = x +plane_WIDTH;
	int rightB = plane.x +plane_WIDTH;//les quatre bords de chaque rectangle
//il faut bien connaître la théorie de collision dans SDL
	if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    return true;//s'il n'y a aucun
}

