//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <iostream>
#include <list>
#include "Timer.h"
#include "Bullet.hpp"
#include "Plane.hpp"
#include "Myplane.hpp"
#include "enemy_plane.hpp"
#include "Ciel.hpp"
#include "Fond_du_jeu.hpp"
#include <string>
#include <sstream>

#define SCREEN_WIDTH   500
#define SCREEN_HEIGHT  640
#define SCREEN_BPP      32

#define CAPTION   "STAR WARS"

// The frame rate
#define FRAMES_PER_SECOND  20
using namespace std ;
// The surfaces
SDL_Surface *pPlane = NULL;
SDL_Surface *pBullet= NULL;
SDL_Surface *pEnemy= NULL;
SDL_Surface *screen= NULL;
SDL_Surface *notes= NULL;
SDL_Surface *gameover= NULL; //les surfaces des élements utilisés

SDL_Event event;//event

SDL_Surface *load_image(std::string filename){//retourner les images optimisées
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_Load(filename.c_str());
	if (loadedImage != NULL){//si le dossier est NULL
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
		if (optimizedImage != NULL){
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF));
		}
	}
	return optimizedImage;
}

void apply_surface (int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL){
	SDL_Rect offset;//configurer les décalages sur l'écran
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface (source, clip, destination, &offset);//apliquer la fénêtre de source sur la destination
}

bool init()
{
	// Initializer les trucs de SDL
	if (SDL_Init (SDL_INIT_EVERYTHING) == -1){
		return false;
	}
	screen = SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);//créer l'écran
	if (screen == NULL){//si l'écran est vide
		return false;
	}
	SDL_WM_SetCaption(CAPTION, NULL);// mettre la titre de la fenêtre
	return true;
}

void clean_up()
{
	// Free the surface
	SDL_FreeSurface(pPlane);
	SDL_FreeSurface(pBullet);
	SDL_FreeSurface(pEnemy);
	SDL_FreeSurface(notes);
	SDL_FreeSurface(screen);
	SDL_Quit();// Quit SDL
}

// Main function
int main(int argc, char* args[])
{
	Timer fps;// The frame rate regulator
	bool quit = false;// Quit flag
	Ciel monciel;
	if (init() == false){
		return 1;
	}// Initialisation 
	pPlane = load_image("myplane.png");
	pBullet = load_image("Player's Bullet.bmp");
	pEnemy = load_image("enemy.bmp");
	gameover = load_image("gameover.jpg");// Load the files
	Fond_du_jeu *background = new Fond_du_jeu(0,0,"background.bmp");//le font du jeu
	while (quit == false)// quand user n'est pas quitté
	{
		fps.start();// Start the frame timer
		while(SDL_PollEvent(&monciel.myplane.event))// quand il y a des events
		{
			monciel.myplane.handle_input();//réagir selon les events
			monciel.myplane_fire();//attaquer s'il y a des events
			if (monciel.myplane.event.type == SDL_QUIT){
				quit = true;// Quitté le programme
			}
		}
		monciel.myplane.move();//le movement de myplane
		if(monciel.enemy_planes.size()<=2)
		{
			monciel.creer_enemy();//au maximum,il y a 2 adversaire en mếme temps sur l'écran
		}
		
		if(monciel.enemybullets.size()<=8)
		{
			monciel.enemy_fire();//si le nombre du enemybullets est inférieur de 8, les adversaires vont attaquer 
		}
	
		monciel.bullet_enemy_move();//le movement de balle et d'adversaire
		monciel.mise_a_jour();
		
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
		background->move();
		background->voir_le_fond(screen);
		
		for(monciel.it_enemy = monciel.enemy_planes.begin();monciel.it_enemy!=monciel.enemy_planes.end();monciel.it_enemy++){
			apply_surface(monciel.it_enemy->x, monciel.it_enemy->y, pEnemy, screen);
		}
	 	for(monciel.it_bullet = monciel.myplanebullets.begin();monciel.it_bullet!=monciel.myplanebullets.end();monciel.it_bullet++){
			apply_surface(monciel.it_bullet->x, monciel.it_bullet->y, pBullet, screen);
		} 
		for(monciel.it_bullet = monciel.enemybullets.begin();monciel.it_bullet!=monciel.enemybullets.end();monciel.it_bullet++){
			apply_surface(monciel.it_bullet->x, monciel.it_bullet->y, pBullet, screen);
		}//afficher tous les elements sur l'écran
		
		apply_surface(monciel.myplane.x, monciel.myplane.y, pPlane, screen);
		
		if (monciel.myplane.mort())//si myplane est mort,game over
		{
			apply_surface(0, 0, gameover, screen);//afficher l'image de gameover
			apply_surface(20, 300, monciel.notes, screen);//afficher "myplane est mort"
		} 
		
		// Cap the frame rate
		if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
		{
			SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
		}

		std::stringstream NOTE;
		TTF_Init();
		NOTE <<"Notes obtenues:"<<SDL_GetTicks();
		TTF_Font* font = TTF_OpenFont("Lazy.ttf",25);
		
		SDL_Color textcolor = {200,25,25};//le couleur des notes qui est affiché sur l'écran
		notes = TTF_RenderText_Solid( font,NOTE.str().c_str(), textcolor );
		apply_surface(0, 10, notes, screen);//mettre les notes obtenues sur l'écran
		
		// actualiser l'écran
		if (SDL_Flip(screen) == -1)
		{
			return 1;
		}
	}
	// Clean up
	clean_up();
}
