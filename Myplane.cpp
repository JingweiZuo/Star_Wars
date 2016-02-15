//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Myplane.hpp"

Myplane::Myplane():Plane::Plane()
{
	x = 0;
	y = SCREEN_HEIGHT - plane_HEIGTH;
	vx = 0;
	vy = 0;
}

Myplane::~Myplane()
{}

void Myplane::handle_input()//agir selon les entrées
{
    if (event.type == SDL_KEYDOWN)//les evennements du clavier appuyé
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            vy -= plane_HEIGTH / 4;
            break;
        case SDLK_DOWN:
            vy += plane_HEIGTH / 4;
            break;
        case SDLK_LEFT:
            vx -= plane_WIDTH / 4;
            break;
        case SDLK_RIGHT:
            vx += plane_WIDTH / 4;
            break;
        }
    }

    if (event.type == SDL_KEYUP)//les evennements du clavier libéré
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            vy += plane_HEIGTH / 4;
            break;
        case SDLK_DOWN:
            vy -= plane_HEIGTH / 4;
            break;
        case SDLK_LEFT:
            vx += plane_WIDTH / 4;
            break;
        case SDLK_RIGHT:
            vx -= plane_WIDTH / 4;
            break;
        }
    }
}


void Myplane::move()
{
    // le movement est à gauche ou à droit
    x += vx;

    // s'il est abordé l'écran (axe X)
    if ((x < 0) || (x  + plane_WIDTH > SCREEN_WIDTH))
    {
        // revien sur l'écran
        x -= vx;
    }

    // Move the PPlane up or down
    y += vy;

    // s'il est abordé l'écran (axe Y)
    if ((y < 0) || (y + plane_HEIGTH > SCREEN_HEIGHT))
    {
        // revien sur l'écran
        y -= vy;
    }
}

// void Myplane::action_sur_event(char e)
// {
// 	switch (e){
// 		case 'u':
//         this->setPosition(this->getposition_x(),this->getposition_y()-this->vitesse);
//    		case 'd':
//         this->setPosition(this->getposition_x(),this->getposition_y()+this->vitesse);
//         case 'l':
//         this->setPosition(this->getposition_x()-this->vitesse,this->getposition_y());
//    		case 'r':
//         this->setPosition(this->getposition_x()+this->vitesse,this->getposition_y());
// 	}
// }
/*void Myplane::fire()
{
	Bullet* bullet ;
	bullet->setPosition(this->getposition_x()+(this->W)/2,this->getposition_y()-(this->H));
	this->monciel->myplanebullets.push_back(bullet);//à vérifier
}*/

