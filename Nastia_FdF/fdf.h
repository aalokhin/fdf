#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>


# include <errno.h>
# include <mlx.h>

typedef struct			s_lines
{
	char				*save;
	struct s_lines		*next;
	int 				length;
}						t_lines;


typedef struct s_input
{
	t_lines 	*lines;
	int 		len; // how long are lines
	int 		read;

	int 		x_start;
	int			y_start;
	int 		x_end;
	int			y_end;

}				t_input;

typedef struct 		s_point
{
	float			x;
	float			y;
	float			z;
	unsigned int	color;
	t_point			*next

}					t_point;



t_lines			*backup_line(char *line);
void			add_line_to_list(t_lines **head, char *line);
void			ft_clean_parse(char **parse);

void				count_lines(t_input *input);
void			delete_lines_list(t_lines **head);


#endif