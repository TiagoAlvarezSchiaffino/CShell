/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncmp.c                                                             */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:50:55 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 17:54:06 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		diff;

	index = -1;
	diff = 0;
	if (n == 0)
		return (0);
	while (++index < n && diff == 0 && s1[index] != '\0' && s2[index] != '\0')
		diff = (unsigned char)s1[index] - (unsigned char)s2[index];
	if (index < n && diff == 0 && (s1[index] == '\0' || s2[index] == '\0'))
			diff = (unsigned char)s1[index] - (unsigned char)s2[index];
	return (diff);
}