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
/*   Updated: 2024/05/30 14:31:39 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Loops through the available builtins function and find a match based
 * on args. If found, it will executes the functio. Else write error and set
 * errno to 127
 * 
 * @param main The main struct containing the builtin functions and
 * their respective names
 * @param command The command that will be executed
 */
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
	ft_dprintf(STDERR_FILENO, "%s: command not found\n", command[0]);
	g_global.error_no = 127;
}