/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_cd.c                          		                                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 15:41:02 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Checks whether there is a cd command
** If no, return 0
** If yes, then will change current directory and return 1
** If changing directory fails, throw error and exit with status 1
** Line 26 -> 29 can be removed (not needed if function is used correctly) */
int	cd(t_main *main, char **args)
{
	char	*path;

	if (args[0] == 0)
		return (0);
	if (ft_strncmp(args[0], "cd", 3) != 0)
		return (0);
	if (args[1] == 0)
	{
		path = ft_strjoin("/Users/", getenv("USER"));
		if (chdir(path) < 0)
		{
			free(path);
			perror(path);
		}
		free(path);
	}
	else if (chdir(args[1]) < 0)
		perror(args[1]);
	return (1);
	(void)main;
}