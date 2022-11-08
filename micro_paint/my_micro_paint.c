#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
	float	lx, ly, rx, ry;

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
	memset(map, bg, map_height * map_width);
	while (1)
	{
		count = fscanf(file, "%c %f %f %f %f %c\n", &type, &lx, &ly, &rx, &ry, &ch);
		if (count == -1)
			break;
		if (count != 6 || (type != 'r' && type != 'R') || rx <= 0.0f || ry <= 0.0f)
			return (ft_error(file, map));
		rx += lx;
		ry += ly;
		height = 0;
		while (height < map_height)
		{
			width = 0;
			while (width < map_width)
			{
				if (width <= rx && width >= lx && height <= ry && height >= ly)
					if (type == 'R' || width > rx - 1 || width < lx + 1 || height > ry - 1 || height < ly + 1)
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
