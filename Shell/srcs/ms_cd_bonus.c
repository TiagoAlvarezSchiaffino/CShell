/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_cd_bonus.c                                                            */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 14:15:19 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Checks whether there is a cd command
** If no, return 0
** If yes, then will change current directory and return 1
** If changing directory fails, throw error and exit with status 1
** The directory is changed in the parent instead of in the child */
int	check_cd_command(int count, char **input)
{
	char	*command;
	char	*path;

	if (count <= 1)
		return (0);
	command = input[0];
	path = input[1];
	if (ft_strncmp(command, "cd", 3) != 0)
		return (0);
	if (path == NULL)
	{
		path = ft_strjoin("/Users/", getenv("USER"));
		if (chdir(path) < 0)
		{
			free(path);
			perror(path);
		}
		free(path);
	}
	else if (chdir(path) < 0)
		perror(path);
	return (1);
}

int	cd(t_main *main, char **args)
{
	(void)args;
	(void)main;
	return (0);
}