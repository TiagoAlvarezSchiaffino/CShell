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
/*   Updated: 2024/05/25 06:41:12 by Tiago                  /_____/ U         */
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
int	main(int ac, char **av, char **envp)
{
	t_main	main;
	char	**command;
	char	*input;

	init_signal();
	init_main(&main, envp);
	while (1)
	{
		input = readline("$> ");
		command = parse_input(input);
		if (ft_getwc(input, ' ') < 1)
			continue ;
		check_cd_command(command[0], command[1]);
		free_ftsplit(command);
		free(input);
	}
	return (0);
	(void)ac;
	(void)av;
}

/*
child_pid = fork();
if (child_pid < 0)
	perror_and_exit("Fork failed");
if (child_pid == 0 && execve(command[0], command, envp) < 0)
	perror_and_exit(command[0]);
else
	waitpid(child_pid, 0, WUNTRACED);

char	cmd[] = "/bin/ls";
char	*av[] = {"ls", "-l", NULL};
char	*envp[] = {NULL};

execve(cmd, av, envp);
*/