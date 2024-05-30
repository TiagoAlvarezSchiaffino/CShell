/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_expanderhelper.c                                          	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 14:10:52 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 14:12:14 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*append_char(char *input, char c)
{
	char	*output;
	int		size;

	size = 0;
	if (input != NULL)
		size = ft_strlen(input);
	output = ft_calloc(size + 2, sizeof(char));
	if (input != NULL)
		output = ft_strdup(input);
	output[size] = c;
	free(input);
	return (output);
}