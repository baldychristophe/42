
#include "ANonPlayable.hpp"
#include "ft_retro.hpp"

extern int g_cols;
extern int g_lines;

ANonPlayable::ANonPlayable(int x, int y, int life, int frameSpeed, char sprite, std::string const & type, int fireRate)
  : AGameElement(x, y, life, sprite), _type(type)  {
  this->_frameSpeed = frameSpeed;
  this->_frameMove = 0;
  this->_fireRate = fireRate;
  this->_fireIndex = 0;
  this->_next = NULL;
  this->_prev = NULL;
}

ANonPlayable::ANonPlayable(ANonPlayable const & src)
  : AGameElement(src.getX(), src.getY(), src.getLife(), src.getSprite()) {
  *this = src;
   return;
}

ANonPlayable::~ANonPlayable() {
   return;
}

ANonPlayable&	ANonPlayable::operator=(ANonPlayable const & rhs) {
	(void)rhs;
	return *this;
}

void	ANonPlayable::nextStep(void) {
	int		dir = 1;
	if (this->_frameSpeed < 0)
		dir = - 1;
	this->_frameMove += dir;
	if (_frameMove == this->_frameSpeed)
	{
		this->setY(this->getY() + dir);
		this->_frameMove = 0;
	}
	if (getLife() <= 0)
		setSprite('-');
}

bool	ANonPlayable::outOfBound(void) const {
	if (this->getY() > (g_lines - 1) || this->getY() < 1)
		return (true);
	else if (this->getX() > (g_cols - 1) || this->getX() < 1)
		return (true);
	else
		return (false);
}

int   ANonPlayable::getFireRate(void) const {
  return (this->_fireRate);
}

int   ANonPlayable::getFireIndex(void) const {
  return (this->_fireIndex);
}

int  ANonPlayable::setFireIndex(int fire) {
  this->_fireIndex = fire;
  return (this->_fireIndex);
}

bool  ANonPlayable::fire(void) {
  if (this->getFireRate() == 0)
    return (false);
  this->setFireIndex(this->getFireIndex() + 1);
  if (this->getFireIndex() >= this->getFireRate()) {
    this->setFireIndex(0);
    return (true);
  }
  return (false);
}

// GETTERS
int		ANonPlayable::getFrameSpeed(void) const {
	return (this->_frameSpeed);
}

int		ANonPlayable::getFrameMove(void) const {
	return (this->_frameMove);
}

ANonPlayable *  ANonPlayable::getNext(void) const {
  return (this->_next);
}

ANonPlayable *  ANonPlayable::getPrev(void) const {
  return (this->_prev);
}

std::string const &	ANonPlayable::getType() const {
	return (this->_type);
}

// SETTERS
int		ANonPlayable::setFrameMove(int inc) {
	this->_frameMove = inc;
	return (this->_frameMove);
}

ANonPlayable *  ANonPlayable::setNext(ANonPlayable * next) {
  this->_next = next;
  return (this->_next);
}

ANonPlayable *  ANonPlayable::setPrev(ANonPlayable * prev) {
  this->_prev = prev;
  return (this->_prev);
}
