/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strdup.c                                                              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:22:13 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 14:13:34 by Tiago                   /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		counter;
	int		index;

	counter = 0;
	while (src[counter] != '\0')
		counter++;
	copy = malloc(sizeof(char) * (counter + 1));
	if (copy == NULL)
		return (0);
	index = -1;
	while (src[++index] != '\0')
		copy[index] = src[index];
	copy[index] = '\0';
	return (copy);
}