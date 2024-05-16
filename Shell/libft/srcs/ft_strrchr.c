/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strrchr.c                                                             */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:58:01 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 17:59:49 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str) + 1;
	while (--i >= 0)
		if (str[i] == (char)c)
			return ((char *)(str + i));
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}