#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int
	ft_error(FILE *file, char *map)
{
	if (file)
		fclose(file);
	if (map)
		free(map);
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}

int
	main(int argc, char **argv)
{
	FILE	*file = NULL;
	char	*map = NULL;
	int		count, map_width, map_height, width, height;
	char	type, bg, ch;
	float	r, x, y, dist;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
		return (ft_error(file, map));
	count = fscanf(file, "%d %d %c\n", &map_width, &map_height, &bg);
	if (count != 3 || map_width <= 0 || map_width > 300 || map_height <= 0 || map_height > 300)
		return (ft_error(file, map));
	map = calloc(map_width, map_height);
	memset(map, bg, map_width * map_height);
	while (1)
	{
		count = fscanf(file, "%c %f %f %f %c\n", &type, &x, &y, &r, &ch);
		if (count == -1)
			break;
		if (count != 5 || r <= 0.0f || (type != 'c' && type != 'C'))
			return (ft_error(file, map));
		height = 0;
		while (height < map_height)
		{
			width = 0;
			while (width < map_width)
			{
				dist = sqrtf((x - width) * (x - width) + (y - height) * (y - height));
				if (dist <= r)
					if (type == 'C' || dist > r - 1)
						map[height * map_width + width] = ch;
				width++;
			}
			height++;
		}
	}
	height = 0;
	while (height < map_height)
	{
		write(1, &map[height * map_width], map_width);
		write(1, "\n", 1);
		height++;
	}
	free(map);
	fclose(file);
	return (0);
}
