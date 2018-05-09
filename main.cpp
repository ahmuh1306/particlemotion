#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

int main(int argc, char *argv[]) {

	srand(time(NULL));

	mynamespace::Screen screen;

	if (screen.init() == false) {
		std::cout << "Error initialising SDL." << std::endl;
	}

	mynamespace::Swarm swarm;

	while (true) {
		// Update particles
		// Draw particles

		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char green =
				(unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		const mynamespace::Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < mynamespace::Swarm::NPARTICLES; i++) {
			mynamespace::Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * mynamespace::Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * mynamespace::Screen::SCREEN_WIDTH / 2 + mynamespace::Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
