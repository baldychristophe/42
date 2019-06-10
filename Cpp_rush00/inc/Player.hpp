
#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include "AGameElement.hpp"
# include "Input.hpp"


class Player : public AGameElement {

    public:
	    Player();
	    Player(Player const & src);
	    ~Player();

		void	nextMove(Input & input);
		void	input();

   Player & operator=(Player const & rhs);

};

#endif
