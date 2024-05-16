/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlcat.c                                                             */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:38:08 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 17:41:36 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	index;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	dest_length = ft_strlen(dest);
	index = 0;
	while ((dest_length < size - 1) && src[index] != '\0')
		dest[dest_length++] = src[index++];
	dest[dest_length] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[index]));
}