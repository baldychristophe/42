
#ifndef MISSILE_HPP
# define MISSILE_HPP

# include "ANonplayable.hpp"
# include "ft_retro.hpp"

class Missile : public ANonPlayable {

	public:
		Missile(int x, int y, int dir);
		Missile(Missile const & src);
		~Missile(void);

		Missile &	operator=(Missile const & rhs);

	private:
		Missile(void);
};

#endif
