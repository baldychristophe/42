
#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "ANonPlayable.hpp"

class Enemy : public ANonPlayable {

   public:
		Enemy(int x, int y);
	  Enemy(Enemy const & src);
	  ~Enemy();

		void	nextStep(void);

		Enemy & operator=(Enemy const & rhs);

	private:
    int   _fireRate;

    Enemy();
};

#endif
