
#include "Player.hpp"
#include "ft_retro.hpp"

extern int g_cols;
extern int g_lines;

extern time_t	g_startTime;

/*Constructor*/
Player::Player() : AGameElement(g_cols / 2, g_lines - 1, 3, '^') {
	g_startTime = time(NULL);
   return;
}

Player::Player(Player const & src) : AGameElement(g_cols / 2, g_lines - 1, 1, '^') {
   *this = src;
   return;
}

/*Destructor*/
Player::~Player() {
   return;
}

/*Give me a name*/
void        Player::nextMove(Input & input) {
	if (input.getUp() == true && (this->getY() > g_lines / 2))
		this->setY(this->getY() - 1);
	if (input.getDown() == true && (this->getY() < g_lines - 1))
		this->setY(this->getY() + 1);
	if (input.getRight() == true && (this->getX() < g_cols - 1))
		this->setX(this->getX() + 1);
	if (input.getLeft() == true && (this->getX() > 0))
		this->setX(this->getX() - 1);
    return;
}

void        Player::input() {
    return;
}

/*Assignation operator*/
Player &     Player::operator=( Player const & rhs) {
	this->setX(rhs.getX());
	this->setY(rhs.getY());
	this->setLife(rhs.getLife());
	this->setSprite(rhs.getSprite());
	return *this;
 }
