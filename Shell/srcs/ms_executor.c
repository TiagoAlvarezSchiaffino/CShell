/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_executor.c                                               	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:30:44 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 14:15:21 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Loops through the available builtins function and find a match based on args
** If found, executes the function, else write error and set errno to 127 */
void	executor(t_main *main, char **command)
{
	int	i;

	i = -1;
	while (++i < MS_MAX_BIFUNC)
	{
		if (command[0] == 0)
			return ;
		if (ft_strcmp(command[0], main->func_name[i]) == 0)
		{
			g_global.error_no = main->func[i](main, command);
			return ;
		}
	}
	write(2, command[0], ft_strlen(command[0]));
	write(2, ": command not found\n", 20);
	g_global.error_no = 127;
}