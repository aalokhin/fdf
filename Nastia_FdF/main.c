#include "fdf.h"








int				main(int argc, char **argv)
{
	int			fd;
	t_input 	input;
	char		*line;

	if (argc != 2)
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);


	while((input.read = get_next_line(fd, &line)) > 0)
	{
		if (line)
		{
			add_line_to_list(&input.lines, line);
			ft_strdel(&line);
		}
	}
	if (get_next_line(fd, &line) != 0)
	{
		ft_putendl("Non-valid file");
		return (0);
	}

	count_lines(&input);
	// printf("~~~~~~~~~~%d\n", input.len);

	t_lines *head;
	head = input.lines;

	while(head)
	{
		printf("%s     <======= %d \n", head->save, head->length);
		head = head->next;
	}
	delete_lines_list(&input.lines);

	// mlx_pixel_put(2, 2, 4, 6, 0x00F0F0F0);


	return (0);
}