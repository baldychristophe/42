
#include "ft_retro.hpp"
#include "Game.hpp"
#include "Input.hpp"

int g_cols;
int g_lines;

time_t	g_startTime;

void	init_ncurses() {
	WINDOW *win = initscr();
	noecho();
	timeout(0);
	clear();
	refresh();
	curs_set(0);
    nodelay(stdscr, TRUE);
	keypad(win, TRUE);
	g_cols = COLS;
	g_lines = LINES - 5;
}

int		exitOnEscape(void)
{
	endwin();
	return (0);
}

int	main() {
	srand(time(NULL));
	init_ncurses();

	Game	game;
	Input	input;
	while (1) {
		input.get();

		// EXIT IF ESC IS PRESSED
		if (input.getEscape())
			return (exitOnEscape());

		game.step(input);
		game.update();

		usleep (FRAME_TIME);
	}
	return (0);
}
