//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#ifndef __FOND_DU_JEU_HPP_
#define __FOND_DU_JEU_HPP_

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#include <string>
#define SCREEN_HEIGHT  640
using namespace std ;

class Fond_du_jeu
{
private:
	int vitesse = 5;
	
public:
	Fond_du_jeu(int x,int y,string filename);
    virtual ~Fond_du_jeu();
	int bgX ;
    int bgY ;
    SDL_Surface* source;
    void move();
    void voir_le_fond(SDL_Surface* destination);
    
};

#endif
