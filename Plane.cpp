//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Plane.hpp"
#include "Element.hpp"

Plane::Plane():Element::Element()
{
}

Plane::~Plane()
{

}



int Plane::getvx()
{
	return this->vx;
}

int Plane::getvy()
{
	return this->vx;
}

int Plane::get_vie()
{
        return this->vie;
}

void Plane::perdre_vie()
{
        this->vie --;
        
}

bool Plane::mort(){
	if(this->vie <= 0)
		return true;
	else
		return false;
}
bool Plane::collision_avec_plane(Plane plane)
{//de la forme de boolean, vérifier s'il y a des collision avec plane
	int bottomA = y;
	int bottomB = plane.y;
	int topA = y - plane_HEIGTH;
	int topB = plane.y - plane_HEIGTH;
	int leftA = x;
	int leftB = plane.x;
	int rightA = x +plane_WIDTH;
	int rightB = plane.x +plane_WIDTH;
//les quatre bords de chaque rectangle
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
