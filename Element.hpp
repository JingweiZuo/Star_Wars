//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#ifndef __Element_HPP_
#define __Element_HPP_

#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


using namespace std;

class Element 
{
private:
	int vie;//la vie d'element

public:
	Element();
    virtual ~Element();
	SDL_Event event;
	int vitesse;
	int x;
    int y;
	int getposition_x();
    int getposition_y();
    int get_vie();
	void perdre_vie();
};
#endif

