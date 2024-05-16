/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_isalnum.c  	                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 14:47:02 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 14:49:24 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}