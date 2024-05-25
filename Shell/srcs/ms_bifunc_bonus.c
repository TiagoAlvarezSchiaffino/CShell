/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_bifunc_bonus.c                                                        */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:38:49 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/25 06:26:19 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void init_main(t_main *main, char **envp)
{
	int	i;

	main->func_name = ft_split("echo cd pwd export unset env exit", ' ');
	main->func[0] = echo;
	main->func[1] = cd;
	main->func[2] = pwd;
	main->func[3] = export;
	main->func[4] = unset;
	main->func[5] = env;
	main->func[6] = ms_exit;
	i = 0;
	while (envp[i] != 0)
		i++;
	main->envp = ft_calloc(i + 1, sizeof(char *));
	main->envp[i] = 0;
	while (--i >= 0)
		main->envp[i] = ft_strdup(envp[i]);
}