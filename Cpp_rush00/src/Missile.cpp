
#include "Missile.hpp"

Missile::Missile(int x, int y, int dir) : ANonPlayable(x, y, 1, dir * 2, '|', "Missile", 0) {
	return;
}

Missile::Missile(Missile const & src)
	: ANonPlayable(src.getX(), src.getY(), 1, src.getFrameSpeed(), '|', "Missile", 0) {
	*this = src;
	return;
}

Missile::~Missile(void) {}

Missile &	Missile::operator=(Missile const & rhs) {
	if (this != &rhs)
	{
		this->setX(rhs.getX());
		this->setY(rhs.getY());
	}
	return (*this);
}
