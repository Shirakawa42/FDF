#include "fdf.h"

int		keyboard_input(int keycode, void *truc)
{
	ft_putnbr(keycode);
	if (keycode == 65307)
		exit(1);
	return (0);
}
