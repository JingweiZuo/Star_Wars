//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Fond_du_jeu.hpp"
#include <string>
#include <SDL/SDL_mixer.h>
using namespace std;

Fond_du_jeu::Fond_du_jeu(int x,int y,string filename){
	this->bgX = x;
	this->bgY = y;
	// The image that's loaded
	SDL_Surface* loadedImage = IMG_Load(filename.c_str());
	SDL_Surface* optimizedImage = NULL;
	if (loadedImage != NULL)
	{
		// Créer une surface optimisée
		optimizedImage = SDL_DisplayFormat(loadedImage);
		// Free la surface ancienne
		SDL_FreeSurface(loadedImage);
		// s'il est optimisé
		if (optimizedImage != NULL)
		{
			// configurer le couleur qu'on veut enlever sur cette image
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));
		}
	}
	this->source = optimizedImage;//optimiser les images
	Mix_Music *music = NULL;
	music = Mix_LoadMUS( "background.wav" );//diffuser la musique du font
	Mix_PlayMusic( music, 1);//diffuser la musique à l'infini
}

Fond_du_jeu::~Fond_du_jeu(){

}

void Fond_du_jeu::move(){
		bgY += this->vitesse;
        //si le fond arrive à la fin de l'écran
        if( bgY >= SCREEN_HEIGHT )
        {
            //remettre la position de bgY
            bgY = 0;
        }
}

void Fond_du_jeu::voir_le_fond(SDL_Surface* destination){
		SDL_Rect offset1;
		SDL_Rect offset2;
		// configurer les déphasages sur l'écran
		offset1.x = bgX;
		offset1.y = bgY+120;
		offset2.x = bgX;
		offset2.y = bgY- SCREEN_HEIGHT+240;//comme l'image que l'on a choisi n'est pas bien correspondant de l'écran
		SDL_Rect* clip = NULL;
		// Blit
		SDL_BlitSurface (this->source, clip, destination, &offset1);
		SDL_BlitSurface (this->source, clip, destination, &offset2);//ajouter le font sur l'écran
}
