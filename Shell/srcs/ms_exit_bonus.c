/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_exit_bonus.c                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/25 06:33:51 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ms_exit(char **args, t_main *main)
{
	ft_printf("From EXIT!");
	(void)args;
	(void)main;
	return (0);
}