#include <ncurses.h>
#include <signal.h>
#include <unistd.h>
#include "catt.h"


int	main(void) 
{
	init_screen();
	run_animation(); 
	close_screen();
	return(0);
}

void	init_screen(void)
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
	int	frame;

	y = LINES / 2 - CAT_HEIGHT / 2;

	for (x = COLS - 1; ; x--)
	{
		frame = ((COLS - x) / 2) % CAT_FRAMES;
		clear();
		if (draw_cat(y, x, frame) ==ERR)
			break;
		getch();
		refresh();
		usleep(40000);
	}
}

int	draw_cat(int y, int x, int frame)
{
	int i;
	static const char *cat[CAT_FRAMES][CAT_HEIGHT] =
	{
{
		" |\\____/|          // ",
		" \\_=w=_/__________// ",
		" |                /    ",
		" \\  __ ____   ___\\    ",
		" //  \\\\    \\\\  // ",
	},
	{
		" |\\____/|          //  ",
		" \\_=w=_/__________// ",
		" |                /    ",
		" \\  __ ____   ___\\    ",
		" ||  ||    ||  || ",
	},
	{
		" |\\____/|         ||   ",
		" \\_=w=_/__________|| ",
		" |                /    ",
		" \\  __ ____   ___\\    ",
		" \\\\  //    //  \\\\ ",
	},
	{
		" |\\____/|         ||   ",
		" \\_=w=_/__________|| ",
		" |                /    ",
		" \\  __ ____   ___\\    ",
		" ||  ||    ||  || ",
	}
	};

	if (x < -CAT_LENGTH)
		return (ERR);
	i = 0;
	while (i < CAT_HEIGHT)
	{
		draw_text_safe(y + i, x, cat[frame][i]);
		i++;
	}

	return (OK);
}

int	draw_text_safe(int y, int x, const char *str)
{
	int	i;

	if (str == NULL)
		return (ERR);

	i = 0;
	while (str[i] != '\0')
	{
		if (x + i >= 0 && x + i < COLS && y >= 0 && y < LINES)
			mvaddch(y, x + i, str[i]);
		i++;
	}
	return (OK);
}

