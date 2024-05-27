/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*    ms_parseinput.c                         		                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 15:41:57 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* ft_split the input by ' '
** If no input (ie. Ctrl-D), print exit and exit with status 0
** If command is exit, print exit and exit with status 0 (can be improved) */
char	**parse_input(t_main *main, char *input)
{
	char	**command;
	int		i;

	if (input == 0)
		main->func[MS_EXIT](main, NULL);
	command = ft_split(input, ' ');
	i = -1;
	while (command[++i] != 0)
	{
		if (ft_strncmp(command[i], "exit", 5) == 0)
			main->func[MS_EXIT](main, NULL);
	}
	return (command);
}