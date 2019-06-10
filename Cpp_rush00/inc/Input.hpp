#ifndef INPUT_HPP
# define INPUT_HPP

# include "ft_retro.hpp"

/*#define KEY_DOWN	0402		 down-arrow key */
/*#define KEY_UP		0403		 up-arrow key */
/*#define KEY_LEFT	0404		 left-arrow key */
/*#define KEY_RIGHT	0405		 right-arrow key */
#define KEY_SPACE	32			/* space key */
#define KEY_ESCAPE	27			/* escape key */

class Input {
public:
	Input();
	Input(Input const & input);
	~Input();

	Input&		operator=(Input const & input);

	void	get();
	bool	getUp();
	bool	getDown();
	bool	getLeft();
	bool	getRight();
	bool	getSpace();
	bool	getEscape();

private:
	bool	_up;
	bool	_down;
	bool	_left;
	bool	_right;
	bool	_space;
	bool	_escape;

	void	_reset();
};

#endif
