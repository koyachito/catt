#ifndef CATT_H
# define CATT_H

# define CAT_HEIGHT 5
# define CAT_LENGTH 25
# define CAT_FRAMES 4

void	init_screen(void);
void	close_screen(void);
void	run_animation(void);
int		draw_cat(int y, int x, int frame);
int		draw_text_safe(int y, int x, const char *str);

#endif
