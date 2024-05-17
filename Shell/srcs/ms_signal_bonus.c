/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_signal_bonus.c                                                                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:38:49 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 22:20:42 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sigint_handler(int signo)
{
	ft_printf("\n$>");
	(void)signo;
}