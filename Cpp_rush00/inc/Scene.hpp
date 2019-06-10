
#ifndef SCENE_HPP
# define SCENE_HPP

# include <iostream>
# include "ft_retro.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Obstacle.hpp"
# include "Input.hpp"
# include "Missile.hpp"

# define ENEMY_RATE_DEC		10
# define OBSTACLE_RATE_DEC	10
# define ENEMY_RATE_MIN 	30
# define OBSTACLE_RATE_MIN 	50
# define DIFFICULTY_RATE	2000 //nombre de frame avant que la frequence d'apparition augmente

typedef	struct	s_popEntity {
	int			rate;
	int			count;
}				PopEntity;

class Scene {

    public:
	    Scene();
	    Scene(Scene const & src);
	    ~Scene();

   Scene & operator=(Scene const & rhs);

   void		printScene(void) const;
   void		nextScene(Input & input);
   void		insertNonPlayable(ANonPlayable *entity);
   void		outOfBound(void);
   void		collisions(void);

	private:
		Player			_player;
		ANonPlayable	*_entities;

		ANonPlayable *	_removeEntity(ANonPlayable * ptr);
		PopEntity		_popEnemy;
		PopEntity		_popObstacle;
		PopEntity		_popBoss;
		PopEntity		_popAsteroid;
		int				_difficultyCount;
    int       _score;

	    void	_popStep(void);
		void	_resetStep(void);
};

#endif
