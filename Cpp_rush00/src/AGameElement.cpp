
#include "AGameElement.hpp"
#include "ncurses.h"

extern int g_cols;
extern int g_lines;

AGameElement::AGameElement(int x, int y, int life, char sprite)
	: _x(x), _y(y), _life(life), _sprite(sprite){
   return;
}

AGameElement::AGameElement(AGameElement const & src) {
   *this = src;
   return;
}

AGameElement::~AGameElement() {
   return;
}

AGameElement&	AGameElement::operator=(AGameElement const & rhs) {
	(void)rhs;
	return *this;
}

void	AGameElement::print(void) const {
	mvprintw(this->_y, this->_x, "%c", this->_sprite);
}

// GETTERS
int		AGameElement::getX(void) const {
	return (this->_x);
}

int		AGameElement::getY(void) const {
	return (this->_y);
}

int		AGameElement::getLife(void) const {
	return (this->_life);
}

char	AGameElement::getSprite(void) const {
	return (this->_sprite);
}

// SETTERS
int		AGameElement::setX(int newX) {
	this->_x = newX;
	return (this->_x);
}

int		AGameElement::setY(int newY) {
	this->_y = newY;
	return (this->_y);
}

int		AGameElement::setLife(int newLife) {
	this->_life = newLife;
	return (this->_life);
}

char	AGameElement::setSprite(char c) {
	this->_sprite = c;
	return (this->_sprite);
}

void	AGameElement::takeDamage(int damage) {
	setLife(getLife() - damage);
}
