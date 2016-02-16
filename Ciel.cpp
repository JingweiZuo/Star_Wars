//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "Ciel.hpp"
#include <SDL/SDL_ttf.h>
#include <sstream>

using namespace std;

Ciel::Ciel(){
}
Ciel::~Ciel(){
	
}


void Ciel::creer_enemy(){
	//creer les enemis, et les mettre dans la liste "enemy_planes"
	enemy_plane *enemy = new enemy_plane() ;
	enemy->setposition(rand() % SCREEN_WIDTH,0);
	this->enemy_planes.push_back(*enemy);
}
void Ciel::enemy_fire(){
	//les enelis lancent les balles,et les mettre dans la liste "enemybullets"
	for (this->it_enemy = this->enemy_planes.begin();this->it_enemy!=this->enemy_planes.end();this->it_enemy++){
		Bullet* bullet =new Bullet() ;
		bullet->x=this->it_enemy->x+(plane_WIDTH)/2;
		bullet->y=this->it_enemy->y+plane_HEIGTH;
		this->enemybullets.push_back(*bullet);
	}	
}

void Ciel::myplane_fire(){
	//myplane lance les balles,et les mettre dans la liste "myplanebullets"
	Bullet* bullet =new Bullet() ;
	bullet->x=this->myplane.x+(plane_WIDTH)/2;
	bullet->y=this->myplane.y-plane_HEIGTH;
	this->myplanebullets.push_back(*bullet);
}


void Ciel::bullet_enemy_move(){//le mouvement du myplane, d'enemis et des balles
	
	for (it_bullet = myplanebullets.begin();it_bullet!=myplanebullets.end();it_bullet++){
		it_bullet->x = it_bullet->x;//changer la position de la balle
		it_bullet->y-=it_bullet->getvitesse();
		if(it_bullet->y <= 0)//si la balle aborde le bord de l'écran, on l'enlève
			it_bullet = myplanebullets.erase(it_bullet);
	}
	for (it_bullet = enemybullets.begin();it_bullet!=enemybullets.end();it_bullet++){
		it_bullet->x = it_bullet->x;
		it_bullet->y += it_bullet->getvitesse();//changer la position de la balle
		if(it_bullet->y >= SCREEN_HEIGHT)//si la balle aborde le bord de l'écran, on l'enlève
			it_bullet = enemybullets.erase(it_bullet);
	}
	for(it_enemy = enemy_planes.begin();it_enemy!=enemy_planes.end();it_enemy++){
		//changer la position des enemis
		it_enemy->setposition(it_enemy->x,it_enemy->y+it_enemy->vitesse);
		//si les enemis abordent le bord de l'écran, on l'enlève
		if(it_enemy->y >= SCREEN_HEIGHT)
			it_enemy = enemy_planes.erase(it_enemy);
	}
}

void Ciel::mise_a_jour(){//actualiser les elements sur l'écran
	for(it_enemy = enemy_planes.begin();it_enemy!=enemy_planes.end();it_enemy++){
		if(it_enemy->collision_avec_plane(myplane)){
			Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
			Mix_Music *music = NULL;//quand il y a d'une collision,play music
			music = Mix_LoadMUS( "attaquer.wav" );
			Mix_PlayMusic( music, 1);//passe une fois de la musique
			it_enemy = enemy_planes.erase(it_enemy);
			this->myplane.perdre_vie();
			cout<<this->myplane.get_vie()<<endl;
		}//la colision entre myplane et enemy
		for (it_bullet = myplanebullets.begin();it_bullet!=myplanebullets.end();it_bullet++){
			if(it_bullet->collision_avec_plane(*it_enemy)){
				Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
				Mix_Music *music = NULL;//quand il y a d'une collision,play music
				music = Mix_LoadMUS( "attaquer.wav" );
				Mix_PlayMusic( music, 1);
				it_enemy = enemy_planes.erase(it_enemy);
				it_bullet = myplanebullets.erase(it_bullet);
			}
		}//la colision entre myplane_bullets et enemy
	}
	for (it_bullet = enemybullets.begin();it_bullet!=enemybullets.end();it_bullet++){
		if(it_bullet->collision_avec_plane(myplane)){
			Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
			Mix_Music *music = NULL;//quand il y a d'une collision,play music
			music = Mix_LoadMUS( "attaquer.wav" );
			Mix_PlayMusic( music, 1);
			it_bullet = enemybullets.erase(it_bullet);
			if(this->myplane.get_vie()){
				this->myplane.perdre_vie();
			}
			cout<<this->myplane.get_vie()<<endl;
		std::stringstream NOTE;
		TTF_Init();
		NOTE <<"Myplane est mort";
		TTF_Font* font = TTF_OpenFont("Lazy.ttf",30);
		SDL_Color textcolor = {200,25,25};//le couleur de rough
		notes = TTF_RenderText_Solid( font,NOTE.str().c_str(), textcolor );//affiche les notes obtenues sue l'écran
		}
	}//la colision entre myplane et enemy_bullets
}
