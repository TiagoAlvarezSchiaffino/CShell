/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_export_bonus.c                                                        */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 14:48:36 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Duplicates and returns a copy of envp and sorts it in alphabatical order */
static char	**sort_envp(char **envp)
{
	int		i;
	int		j;
	int		max;
	char	**output;
	char	*temp;

	output = dup_doublearray(envp);
	max = 0;
	while (envp[max] != 0)
		max++;
	i = -1;
	while (++i < max - 1)
	{
		j = i + 1;
		while (++j < max)
		{
			if (ft_strcmp(output[i], output[j]) > 0)
			{
				temp = output[i];
				output[i] = output[j];
				output[j] = temp;
			}
		}
	}
	return (output);
}

/* Prints the sorted envp with the "declare -x" suffix
** and the value of the variable covered with "" */
static void	print_envp(char **envp)
{
	char	**split;
	int		i;

	i = -1;
	while (envp[++i] != 0)
	{
		split = ft_split(envp[i], '=');
		ft_printf("declare -x %s=\"%s\"\n", split[0], split[1]);
		free_doublearray(split);
	}
	free_doublearray(envp);
}

/* Checks whether default export is called or not */
int	export(t_main *main, char **args)
{
	char	**dup;

	if (args[1] == 0)
	{
		dup = sort_envp(main->envp);
		print_envp(dup);
	}
	return (0);
}