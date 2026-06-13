#include <ncurses.h>
#include <signal.h>
#include <unistd.h>
// #include "catt.h"

#define CAT_HEIGHT 3
#define CAT_LENGTH 7

void	init_screen(void);
void	close_screen(void);
void	run_animation(void);
int		draw_cat(int y, int x);
int		draw_text_safe(int y, int x, char *str);

/*
typedef struct s_options
{
	int meow;
	int dog;
	int count;
} t_options;
*/

int	main() //後でコマンドライン引数入れる.
{
	// t_options opt;

	// opt = parse_options(argc, argv);
	init_screen();
	run_animation(); //引数optに変更する.
	close_screen();
	return(0);
}

void	init_screen()
{
	initscr();
	signal(SIGINT, SIG_IGN);
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	leaveok(stdscr, TRUE);
	scrollok(stdscr, FALSE);
}

void	close_screen(void)
{
	mvcur(0, COLS - 1, LINES - 1, 0);
	endwin();
}

void	run_animation(void)
{
	int x;
	int	y;

	y = LINES / 2;

	for (x = COLS - 1; ; x--)
	{
		clear();
		if (draw_cat(y, x) ==ERR)
			break;
		getch();
		refresh();
		usleep(40000);
	}
}

int	draw_cat(int y, int x)
{
	static char *cat[CAT_HEIGHT + 1] =
	{
		" /\\_/\\ ",
		"( o.o )",
		" > ^ < ",
		"       "
	};

	if (x < -CAT_LENGTH)
		return (ERR);
	
	for (int i = 0; i <= CAT_HEIGHT; ++i)
		draw_text_safe(y + i, x, cat[i]);

	return (OK);
}

int	draw_text_safe(int y, int x, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (x + i >= 0 && x + i < COLS && y >= 0 && y < LINES)
			mvaddch(y, x + i, str[i]);
		i++;
	}
	return (OK);
}

