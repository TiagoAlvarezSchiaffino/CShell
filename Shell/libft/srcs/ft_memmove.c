/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memmove.c      	                                                      */
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

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;

	i = -1;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		i = (int)n;
		while (--i >= 0)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		return (dst);
	}
	else
	{
		while (++i < (int)n)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	}
	return (dst);
}