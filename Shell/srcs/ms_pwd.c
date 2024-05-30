/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_pwd.c                           	                                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 14:45:39 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Gets and prints out the current directory of the program
 * 
 * @param main The main struct (Can be NULL)
 * @param args The arguments (Can be NULL)
 * @return int 0 on success
 */
int	pwd(t_main *main, char **args)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_printf("%s\n", path);
	free(path);
	return (0);
	(void)args;
	(void)main;
}