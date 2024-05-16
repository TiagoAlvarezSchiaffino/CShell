/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_ultoa_base.c                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 18:24:42 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 18:32:00 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long n)
{
	unsigned long	temp;
	char			*output;
	int				count;

	count = 3;
	temp = n;
	while (temp >= 16 && (temp / 16) && ++count)
		temp /= 16;
	temp = n;
	output = malloc(sizeof(char) * (count + 1));
	if (output == NULL)
		return (NULL);
	output[count] = '\0';
	output[0] = '0';
	output[1] = 'x';
	while (temp >= 16)
	{
		--count;
		output[count] = "0123456789abcdef"[temp % 16];
		temp /= 16;
	}
	output[--count] = "0123456789abcdef"[temp % 16];
	return (output);
}