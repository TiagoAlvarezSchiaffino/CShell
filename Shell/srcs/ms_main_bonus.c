/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_main_bonus.c                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 21:36:12 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* If readline shows undefined when compiling, you need to install it 
** For installation, can check how to at Available Functions */
int	main(void)
{
	pid_t	child_pid;
	char	**command;
	char	*input;
	int		stat_loc;

	while (1)
	{
		input = readline("$> ");
		command = ft_split(input, ' ');
		if (ft_strncmp(command[0], "cd", 3) == 0)
		{
			if (cd(command[1]) < 0)
				perror(command[1]);
			continue ;
		}
		child_pid = fork();
		if (child_pid < 0)
			perror_and_exit("Fork failed");
		if (child_pid == 0 && execvp(command[0], command) < 0)
			perror_and_exit(command[0]);
		else
			waitpid(child_pid, &stat_loc, WUNTRACED);
	}
	return (0);
}