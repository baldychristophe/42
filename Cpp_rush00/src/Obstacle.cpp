
#include "Obstacle.hpp"

/*Constructor*/
Obstacle::Obstacle(int x, int y) : ANonPlayable(x, y, 1, 20, 'O', "Obstacle", 0) {
   return;
}

Obstacle::Obstacle(Obstacle const & src)
	: ANonPlayable(src.getX(), src.getY(), 1, 10, 0, "Obstacle", 0) {
   *this = src;
   return;
}

/*Destructor*/
Obstacle::~Obstacle() {
   return;
}

Obstacle&	Obstacle::operator=(Obstacle const & rhs) {
	(void)rhs;
	return *this;
}
