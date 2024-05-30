/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_calloc.c  	                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 14:46:23 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 13:45:11 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*output;
	size_t	i;

	i = 0;
	output = malloc(nitems * size);
	if (output == NULL || size == SIZE_MAX)
		return (NULL);
	while (i < (nitems * size))
	{
		output[i] = 0;
		i++;
	}
	return ((void *)output);
}