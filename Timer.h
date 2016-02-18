//  Created by Jingwei ZUO on 30/12/2015.
//  Copyright (c) 2015 Jingwei ZUO. All rights reserved.

#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

// The timer
class Timer
{
private:
	// The clock time when the timer started
	int startTicks;

	// The ticks stored when the timer was paused
	int pausedTicks;

	// The timer status
	bool paused;
	bool started;

public:
	// Initializes variables
	Timer();

	// The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	// Get the timer's time
	int get_ticks();

	// Checks the status of the timer
	bool is_started();
	bool is_paused();
};
