/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memset.c      	                                                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 15:26:39 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 15:27:46 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(unsigned char *)(str + i) = c;
	return (str);
}