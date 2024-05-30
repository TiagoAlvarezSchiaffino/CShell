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
/*   Updated: 2024/05/30 14:44:33 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief ft_split the input by ' '. If no input (ie. Ctrl-D), print exit and
 * exit with status 0. If command is exit, print exit and exit with status 0
 * 
 * @param main The main struct containing the exit builtin function
 * @param input The input from readline
 * @return char** string array that are null terminated by 0
 */
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