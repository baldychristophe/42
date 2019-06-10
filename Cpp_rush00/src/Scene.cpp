
#include "Scene.hpp"
#include "ft_retro.hpp"

extern int g_cols;
extern int g_lines;

extern time_t	g_startTime;

/*Constructor*/
Scene::Scene() : _entities(NULL), _difficultyCount(0), _score(0) {
	_popEnemy.rate = FPS * 5;
	_popEnemy.count = _popEnemy.rate;
	_popObstacle.rate = FPS * 2;
	_popObstacle.count = _popObstacle.rate;
	_popBoss.rate = FPS * 15;
	_popBoss.count = _popBoss.rate;
	_popAsteroid.rate = FPS * 5;
	_popAsteroid.count = _popAsteroid.rate;
	return;
}

Scene::Scene(Scene const & src) {
	*this = src;
	return;
}

/*Destructor*/
Scene::~Scene() {
	return;
}

Scene&	Scene::operator=(Scene const & rhs) {
	(void)rhs;
	return *this;
}

// Print Scene
void		Scene::printScene(void) const {
	_player.print();

	ANonPlayable *	tmp;
	tmp = _entities;
	while (tmp != NULL) {
		tmp->print();
		tmp = tmp->getNext();
	}
	int i = 0;
	while(i < COLS)
	{
		mvprintw(LINES - 5, i, "_");
		i++;
	}
	mvprintw(LINES - 2, 2, "life: %5d  |  score: %5d  |  time: %d", _player.getLife(), _score, time(NULL) - g_startTime);
	return;
}

void		Scene::nextScene(Input & input) {
	static int	shootFrame = 0, canShoot = (FPS / 4);

	_popStep();
	_player.nextMove(input);
	if (input.getSpace() == true && shootFrame >= canShoot) {
		this->insertNonPlayable(new Missile(_player.getX(), _player.getY() - 1, -1));
		shootFrame = 0;
	}
	if (shootFrame < canShoot)
		shootFrame++;

	ANonPlayable *	tmp = _entities;
	while (tmp != NULL) {
		if (tmp->getLife() <= 0) {
			if (tmp->getType() == "Obstacle")
				_score++;
			else if (tmp->getType() == "Enemy")
				_score += 10;
			tmp = _removeEntity(tmp);
		}
		else {
			tmp->nextStep();
			if(tmp->fire()) {
				this->insertNonPlayable(new Missile(tmp->getX(), tmp->getY() + 1, 1));
			}
			tmp = tmp->getNext();
		}
	}
	if (_player.getLife() <= 0)
		_resetStep();

	return;
}

void 		Scene::insertNonPlayable(ANonPlayable *entity) {
	ANonPlayable *	tmp;
	tmp = _entities;
	while (tmp != NULL && tmp->getNext() != NULL)
		tmp = tmp->getNext();
	if (tmp)
	{
		tmp->setNext(entity);
		entity->setPrev(tmp);
	}
	else
		_entities = entity;
	return;
}

void		Scene::outOfBound(void) {
	ANonPlayable *	tmp;

	tmp = _entities;
	while (tmp != NULL)
	{
		if (tmp->outOfBound() == true)
			tmp = this->_removeEntity(tmp);
		else
			tmp = tmp->getNext();
	}
}

void		Scene::collisions(void) {
	int				x, y;
	ANonPlayable *	board[g_cols][g_lines];
	memset(board, 0, sizeof(ANonPlayable *) * g_cols * g_lines);

	for (ANonPlayable *tmp = _entities; tmp != NULL; tmp = tmp->getNext()) {
		x = tmp->getX();
		y = tmp->getY();
		if (board[x][y] != NULL) {
			if ((board[x][y]->getType() == "Missile" && board[x][y]->getFrameSpeed() < 0) ||
			(tmp->getType() == "Missile" && tmp->getFrameSpeed() < 0)) {
				board[x][y]->takeDamage(1);
				tmp->takeDamage(1);
			}
		} else {
			board[x][y] = tmp;
		}
	}
	if (board[_player.getX()][_player.getY()]) {
		board[_player.getX()][_player.getY()]->takeDamage(99);
		_player.takeDamage(1);
	}
}

ANonPlayable *	Scene::_removeEntity(ANonPlayable * ptr)
{
	ANonPlayable *	prev = ptr->getPrev();
	ANonPlayable *	next = ptr->getNext();

	if (prev != NULL)
		prev->setNext(next);
	else
		_entities = next;
	if (next != NULL)
		next->setPrev(prev);
	delete (ptr);
	return (next);
}

void		Scene::_popStep() {
	int randomX;
	char const c[] = {'<', '-', '+', '-', '>', '+'};
	ANonPlayable * newPart = NULL;
	int	i = 0;

	if (_popEnemy.count >= _popEnemy.rate) {
		randomX = rand() % (g_cols - 1);
		this->insertNonPlayable(new Enemy(randomX, 2));
		_popEnemy.count = 1;
	}
	if (_popObstacle.count >= _popObstacle.rate) {
		randomX = rand() % (g_cols - 1);
		this->insertNonPlayable(new Obstacle(randomX, 2));
		_popObstacle.count = 1;
	}
	if (_popBoss.count >= _popBoss.rate) {
		randomX = rand() % (g_cols - 1);
		while (i <= 5)
    	{
			newPart = new Enemy(randomX + (i % 5) + (i / 5 * 2), 2 + (i / 5));
			newPart->setSprite(c[i]);
			this->insertNonPlayable(newPart);
			i++;
    	}
		_popBoss.count = 0;
	}
	if (_popAsteroid.count >= _popAsteroid.rate) {
		i = 0;
		randomX = rand() % (g_cols - 1);
		while (i <= (3 + (randomX % 3)))
    	{
			newPart = new Obstacle(randomX + (i % 3)  + (i / 3 * 2), 2 + (i / 3));
			this->insertNonPlayable(newPart);
			i++;
    	}
		_popAsteroid.count = 0;
	}
	if (_difficultyCount >= DIFFICULTY_RATE) {
		_difficultyCount = 0;
		if (_popEnemy.rate > ENEMY_RATE_MIN)
			_popEnemy.rate -= ENEMY_RATE_DEC;
		if (_popObstacle.rate > OBSTACLE_RATE_MIN)
			_popObstacle.rate -= OBSTACLE_RATE_DEC;
	}
	_popEnemy.count++;
	_popObstacle.count++;
	_popBoss.count++;
	_popAsteroid.count++;
	_difficultyCount++;
}

void		Scene::_resetStep() {
	ANonPlayable *	tmp = _entities;

	while (tmp != NULL) {
		tmp = _removeEntity(tmp);
	}
	_player = Player();
	_score = 0;
	return;
}
