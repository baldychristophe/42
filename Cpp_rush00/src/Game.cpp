
#include "Game.hpp"
#include "ncurses.h"
#include <unistd.h>

/*Constructor*/
Game::Game() {
	// pop enemy,
   return;
}

Game::Game(Game const & src) {
   *this = src;
   return;
}

/*Destructor*/
Game::~Game() {
   return;
}

Game&	Game::operator=(Game const & rhs) {
	(void)rhs;
	return *this;
}

void        Game::step(Input &input) {
	_scene.collisions();
	_scene.nextScene(input);
	_scene.outOfBound();
    return;
}


void        Game::update() {
	clear();
	_scene.printScene();
	refresh();
    return;
}
