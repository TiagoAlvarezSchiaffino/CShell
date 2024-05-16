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
/*   Updated: 2024/05/16 17:24:58 by Tiago                  /_____/ U         */
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
	copy = malloc((counter * 1) + 1);
	if (copy == NULL)
		return (0);
	index = -1;
	while (src[++index] != '\0')
		copy[index] = src[index];
	copy[index] = '\0';
	return (copy);
}