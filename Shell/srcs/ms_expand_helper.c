/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_expand_helper.c                                          	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 14:10:52 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 18:16:34 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*append_char(char *input, char c)
{
	char	*output;
	int		size;
    int     i;

	size = 0;
    i = 0;
	if (input != NULL)
		size = ft_strlen(input);
	output = ft_calloc(size + 2, sizeof(char));
	if (input != NULL)
	{
		while (input[i] != '\0')
		{
			output[i] = input[i];
			i++;
		}
	}
	output[i] = c;
	output[i + 1] = '\0';
	free(input);
	return (output);
    }