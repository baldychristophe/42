
#ifndef A_NON_PLAYABLE_HPP
# define A_NON_PLAYABLE_HPP

# include "AGameElement.hpp"
# include "ft_retro.hpp"

class ANonPlayable : public AGameElement
{
public:
  ANonPlayable(int x, int y, int life, int frameSpeed, char sprite, std::string const & type, int fireRate);
  ANonPlayable(ANonPlayable const & src);
  ~ANonPlayable(void);

  ANonPlayable &        operator=(ANonPlayable const & rhs);

	virtual void	nextStep(void);

  int             getFrameSpeed(void) const;
  int             getFrameMove(void) const;
  ANonPlayable *  getNext(void) const;
  ANonPlayable *  getPrev(void) const;

  std::string const &	getType() const;

  int             setFrameMove(int inc);
  ANonPlayable *  setNext(ANonPlayable * next);
  ANonPlayable *  setPrev(ANonPlayable * prev);
  bool  		  outOfBound(void) const;

  int           getFireRate(void) const;
  int           getFireIndex(void) const;
  int           setFireIndex(int fire);
  bool          fire(void);

private:
  int             _frameSpeed;
  int				      _frameMove;
  int             _fireRate;
  int             _fireIndex;
  ANonPlayable *	_next;
  ANonPlayable *	_prev;

  std::string	_type;

  ANonPlayable(void);
};

#endif
