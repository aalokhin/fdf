#include "fdf.h"

t_lines			*backup_line(char *line)
{
	t_lines		*new;
	// int	 		len;
	char		**parse;
	int i = 0;

	if (!line)
		return (NULL);
	// len = ft_strlen(line);
	// printf(">>>> %d\n", len);
	printf("Line is %s\n", line);
	parse = ft_strsplit(line, ' ');
	new = ft_memalloc(sizeof(t_lines));
	new->save = ft_strdup(line);
	printf("%s\n", parse[i]);
	while(parse[i])
	{
		//printf("%s\n", parse[i]);
		i++;
	}
	new->length = i;
	new->next = NULL;
	ft_clean_parse(parse);
	// printf(">>>>>>>>>>>%d\n", new->length);
	return (new);
}

void			add_line_to_list(t_lines **head, char *line)
{
	t_lines		*new;
	t_lines		*last;

	new = backup_line(line);
	if (!head || !new)
		return ;
	last = *head;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void				count_lines(t_input *input)
{
	t_lines *head;

	head = input->lines;

	input->len = 0;	

	while(head)
	{
		head = head->next;
		input->len++;
	}

}

void			ft_clean_parse(char **parse)
{
	int i;

	i = 0;
	while (parse[i])
		ft_strdel(&parse[i++]);
	free(parse);
}

void			delete_lines_list(t_lines **head)
{
	t_lines		*next;

	if (!head || !*head)
		return ;
	while ((*head) != NULL)
	{
		next = (*head)->next;
		ft_strdel(&(*head)->save);
		free((*head));
		(*head) = next;
	}
}
