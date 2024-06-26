/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_isprint.c  	                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 14:52:29 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 14:53:37 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}