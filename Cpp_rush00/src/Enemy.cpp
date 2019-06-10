
#include "Enemy.hpp"

/*Constructor*/
Enemy::Enemy(int x, int y) : ANonPlayable(x, y, 4, 25, 'V', "Enemy", 80) {
   return;
}

Enemy::Enemy(Enemy const & src) : ANonPlayable(src.getX(), src.getY(), 1, 200, 'V', "Enemy", 3) {
   *this = src;
   return;
}

/*Destructor*/
Enemy::~Enemy() {
   return;
}

Enemy&	Enemy::operator=(Enemy const & rhs) {
	(void)rhs;
	return *this;
}


/*Next Step*/
void	Enemy::nextStep(void) {
	this->setFrameMove(this->getFrameMove() + 1);
	if (this->getFrameMove() >= this->getFrameSpeed())
	{
    int rndm = rand();
    if (rndm % 5 == 0 && this->getSprite() == 'V')
		  this->setX(this->getX() + 1);
    else if (rndm % 5 == 1 && this->getSprite() == 'V')
    	this->setX(this->getX() - 1);
    else
      this->setY(this->getY() + 1);
		this->setFrameMove(0);
	}
}
