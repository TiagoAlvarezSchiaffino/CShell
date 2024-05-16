/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_striteri.c                                                            */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:25:23 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 17:31:07 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i] != '\0')
		(*f)(i, &s[i]);
}