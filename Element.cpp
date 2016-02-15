//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#include "Element.hpp"

Element::Element(){
	
}
Element::~Element(){
	
}

int Element::getposition_x()
{
	return this->x;
}

int Element::getposition_y()
{
	return this->y;
}

int Element::get_vie()
{
	return this->vie;
}

void Element::perdre_vie()	{
	this->vie --;
}
