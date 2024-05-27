/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_helper_bonus.c                                                        */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 14:50:54 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Frees double array (ie. output from ft_split) */
void	free_doublearray(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != NULL)
		free(split[i]);
	free(split);
}

/* Creates a duplicate of a double array */
char	**dup_doublearray(char **src)
{
	char	**output;
	int		i;

	i = 0;
	while (src[i] != 0)
		i++;
	output = ft_calloc(i + 1, sizeof(char *));
	output[i] = 0;
	while (--i >= 0)
		output[i] = ft_strdup(src[i]);
	return (output);
}