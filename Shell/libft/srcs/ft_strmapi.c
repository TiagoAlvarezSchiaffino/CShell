/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strmapi.c                                                             */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:47:01 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 17:50:38 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*output;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	output = malloc(sizeof(char) * (i + 1));
	if (output == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		output[i] = (*f)(i, s[i]);
	output[i] = '\0';
	return (output);
}