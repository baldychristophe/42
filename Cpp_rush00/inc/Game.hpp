
#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <ncurses.h>
# include "Scene.hpp"
# include "Input.hpp"

class Game {

	public:
		Game();
		Game(Game const & src);
		~Game();

		void	init();
		void	step(Input & input);
		void	update();

	Game & operator=(Game const & rhs);

	private:
		Scene	_scene;

};

#endif
