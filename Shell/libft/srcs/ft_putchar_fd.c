/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putchar_fd.c                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 16:48:52 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 16:49:45 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}