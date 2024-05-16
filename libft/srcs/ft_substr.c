/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_substr.c                                                              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 18:02:44 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 18:06:07 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*output;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		output = malloc(1);
	else if (len >= ft_strlen(s) - start)
		output = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	while (i < start)
		i++;
	while (j < len && i < ft_strlen(s))
		output[j++] = s[i++];
	output[j] = '\0';
	return (output);
}