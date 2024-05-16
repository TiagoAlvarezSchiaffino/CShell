/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memcpy.c      	                                                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 15:25:18 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 15:26:27 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dst == src)
		return (NULL);
	while (++i < n)
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	return (dst);
}