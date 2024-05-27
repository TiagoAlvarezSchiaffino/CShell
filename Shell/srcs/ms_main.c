/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_main.c                                                                */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 15:28:27 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Signal will be initialised: Ctrl-\ and Ctrl-C
** Every while loop, readline will be called while showing "$> " prompt,
** and returns user input in char * form, removing the '\n' behind
** Parses the user input from readline into commands
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
		command = parse_input(&main, input);
		if (input[0] != '\0')
			add_history(input);
		free_doublearray(command);
		free(input);
	}
	return (EXIT_SUCCESS);
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