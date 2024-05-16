/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strchr.c                                                              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:19:51 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 17:21:29 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == (char)c)
			return ((char *)(str + i));
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}