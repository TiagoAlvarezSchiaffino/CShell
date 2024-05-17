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
/*   Updated: 2024/05/16 22:14:06 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* If readline shows undefined when compiling, you need to install it
** For installation, can check how to at Available Functions
** Every while loop, readline will be called while showing "$> " prompt,
** readline will return user input in char * form, removing the '\n' behind
** ft_split the command by ' ', and check whether there is a cd command
** If check_cd_command returns 0, then fork out a child to run system program
** Parent will wait for the child before freeing and looping again */
int	main(void)
{
	pid_t	child_pid;
	char	**command;
	char	*input;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		input = readline("$> ");
		if (input == 0)
			break ;
		command = ft_split(input, ' ');
		if (ft_getwc(input, ' ') < 1)
			continue ;
		if (check_cd_command(command[0], command[1]) == 0)
		{
			child_pid = fork();
			if (child_pid < 0)
				perror_and_exit("Fork failed");
			if (child_pid == 0 && execvp(command[0], command) < 0)
				perror_and_exit(command[0]);
			else
				waitpid(child_pid, 0, WUNTRACED);
		}
		free_ftsplit(command);
		free(input);
	}
	return (0);
}