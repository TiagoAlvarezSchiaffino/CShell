/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_signal_bonus.c                                                        */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:38:49 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/24 22:43:21 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Prints out a new line and clears readline buffer */
void	sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/* Initializes the signals: CTRL-C and CTRL-\
** Termios is get and set to not print ^C or ^D
** This is done by turning the ECHO flag off
** When CTRL-\ (SIGQUIT) signal is received, it is ignored */
void	init_signal(void)
{
	struct termios	termios_current;

	if (tcgetattr(STDIN_FILENO, &termios_current) == -1)
	{
		perror("Tcgetattr failed\n");
		exit(errno);
	}
	termios_current.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termios_current) == -1)
	{
		perror("Tcsetattr failed\n");
		exit(errno);
	}
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	return ;
}