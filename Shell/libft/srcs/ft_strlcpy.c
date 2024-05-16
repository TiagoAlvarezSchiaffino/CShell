/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlcpy.c                                                             */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:42:04 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 17:44:31 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size > 0)
	{
		while (++i < (size - 1) && src[i] != '\0')
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}