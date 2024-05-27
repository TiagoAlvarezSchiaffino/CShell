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
/*   Updated: 2024/05/27 14:22:26 by Tiago                  /_____/ U         */
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

# define MS_ECHO 0
# define MS_CD 1
# define MS_PWD 2
# define MS_EXPORT 3
# define MS_UNSET 4
# define MS_ENV 5
# define MS_EXIT 6
# define MS_MAX_BIFUNC 7

struct		s_main;
typedef int	(*t_func)(struct s_main *main, char **args);

/* Builtin functions struct */
typedef struct s_main
{
	char	**envp;
	char	**func_name;
	t_func	func[MS_MAX_BIFUNC];
}	t_main;

/* CD */
int		cd(t_main *main, char **args);

/* Error */
void	perror_and_exit(char *errormsg);

/* Signal */
void	sigint_handler(int signo);
void	init_signal(void);

/* Helper */
void	free_doublearray(char **split);
char	**dup_doublearray(char **src);

/* Parse Input */
char	**parse_input(t_main *main, char *input);

/* Bifunc */
void	init_main(t_main *main, char **envp);

/* Echo */
int		echo(t_main *main, char **args);

/* Pwd */
int		pwd(t_main *main, char **args);

/* Export */
int		export(t_main *main, char **args);

/* Unset */
int		unset(t_main *main, char **args);

/* Env */
int		env(t_main *main, char **args);

/* Exit */
int		ms_exit(t_main *main, char **args);

#endif