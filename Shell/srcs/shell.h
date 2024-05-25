/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   shell.h                                                                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:38:49 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/24 22:52:49 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/srcs/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <termios.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <term.h>

/* CD */
int		check_cd_command(char *command, char *path);

/* Error */
void	perror_and_exit(char *errormsg);

/* Signal */
void	sigint_handler(int signo);
void	init_signal(void);

/* Helper */
void	free_ftsplit(char **split);

/* Parse Input */
char	**parse_input(char *input);

#endif