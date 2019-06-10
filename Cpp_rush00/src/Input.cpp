#include "Input.hpp"

/*Constructor*/
Input::Input() {
	this->_up = false;
	this->_down = false;
	this->_left = false;
	this->_right = false;
	this->_space = false;
	this->_escape = false;
	return;
}

Input::Input(Input const & src) {
   *this = src;
   return;
}

/*Destructor*/
Input::~Input() {
   return;
}

Input&	Input::operator=(Input const & rhs) {
	(void)rhs;
	return *this;
}

/*Guetters*/
bool	Input::getUp() {
	return this->_up;
}

bool	Input::getDown() {
	return this->_down;
}

bool	Input::getLeft() {
	return this->_left;
}

bool	Input::getRight() {
	return this->_right;
}

bool	Input::getSpace() {
	return this->_space;
}

bool	Input::getEscape() {
	return this->_escape;
}

void	Input::get() {
	int		ch;

	this->_reset();
	while ((ch = getch()) != -1)
	{
		switch (ch) {
		case KEY_ESCAPE:
			this->_escape = true;
			break;
		case KEY_SPACE:
			this->_space = true;
			break;
		case KEY_DOWN:
			this->_down = true;
			break;
		case KEY_UP:
			this->_up = true;
			break;
		case KEY_RIGHT:
			this->_right = true;
			break;
		case KEY_LEFT:
			this->_left = true;
			break;
		}
	}
	return;
}

/*Private function*/
void	Input::_reset() {
	this->_up = false;
	this->_down = false;
	this->_left = false;
	this->_right = false;
	this->_space = false;
	this->_escape = false;
	return;
}
