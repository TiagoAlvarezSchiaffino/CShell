/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_uitoa.c                                                               */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 18:09:58 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 18:18:11 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_uilen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*output;
	int		len;

	len = get_uilen(n);
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	if (n == 0)
		output[0] = '0';
	while (n != 0)
	{
		output[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (output);
}