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
/*   Updated: 2024/05/30 18:23:34 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Appends a character to the back of a string
 * 
 * @param input The string input
 * @param c The character to be appended to the back of a string
 * @return char* The result string after appending
 */
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