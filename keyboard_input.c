#include "fdf.h"

int		keyboard_input(int keycode, void *truc)
{
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
		exit(1);
	if (keycode == 69 || keycode == 78)
	{
		(keycode == 69) ? (((t_param*)truc)->zoom += 0.05) : (((t_param*)truc)->zoom -= 0.05);
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 83)
	{
		((t_param*)truc)->color = 0x00FF0000;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 84)
	{
		((t_param*)truc)->color = 0x00FFFF00;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 85)
	{
		((t_param*)truc)->color = 0x0000FFFF;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 86)
	{
		((t_param*)truc)->color = 0x00FFFFFF;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 87)
	{
		((t_param*)truc)->color = 0x00F00FF0;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 88)
	{
		((t_param*)truc)->color = 0x0000FF00;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 126)
	{
		((t_param*)truc)->xrotate += 5;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 125)
	{
		((t_param*)truc)->xrotate -= 5;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 124)
	{
		((t_param*)truc)->yrotate += 5;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 123)
	{
		((t_param*)truc)->yrotate -= 5;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 89)
	{
		((t_param*)truc)->zrotate += 5;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	if (keycode == 91)
	{
		((t_param*)truc)->zrotate -= 5;
		mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
		((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
		((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img, &((t_param*)truc)->bpx,
			&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
		pixel_puter((t_param*)truc);
	}
	return (0);
}
