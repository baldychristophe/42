
#ifndef OBSTACLE_HPP
# define OBSTACLE_HPP

# include <iostream>
# include "ANonPlayable.hpp"


class Obstacle : public ANonPlayable {

	public:
		Obstacle(int x, int y);
		Obstacle(Obstacle const & src);
		~Obstacle();

		Obstacle & operator=(Obstacle const & rhs);

	private:

		Obstacle();
};

#endif
