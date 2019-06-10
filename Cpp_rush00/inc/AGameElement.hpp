
#ifndef A_GAME_ELEMENT_HPP
# define A_GAME_ELEMENT_HPP

class AGameElement {

public:
	AGameElement(int x, int y, int life, char sprite);
	AGameElement(AGameElement const & src);
	virtual ~AGameElement();

	AGameElement &        operator=(AGameElement const & rhs);

	void	print(void) const;

	int		getX(void) const;
	int		getY(void) const;
	int		getLife(void) const;
	char	getSprite(void) const;

	int		setX(int newX);
	int		setY(int newY);
	int		setLife(int newLife);
	char	setSprite(char c);

	void	takeDamage(int damage);

private:
	int		_x;
	int		_y;
	int		_life;
	char	_sprite;

	AGameElement(void);
};

#endif
