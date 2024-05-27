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
/*   Updated: 2024/05/27 14:16:03 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void init_main(t_main *main, char **envp)
{
	int	i;

	main->func_name = ft_split("echo cd pwd export unset env exit", ' ');
	main->func[MS_ECHO] = echo;
	main->func[MS_CD] = cd;
	main->func[MS_PWD] = pwd;
	main->func[MS_EXPORT] = export;
	main->func[MS_UNSET] = unset;
	main->func[MS_ENV] = env;
	main->func[MS_EXIT] = ms_exit;
	i = 0;
	while (envp[i] != 0)
		i++;
	main->envp = ft_calloc(i + 1, sizeof(char *));
	main->envp[i] = 0;
	while (--i >= 0)
		main->envp[i] = ft_strdup(envp[i]);
}