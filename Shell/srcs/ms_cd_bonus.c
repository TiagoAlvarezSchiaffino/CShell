/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_cd_bonus.c                                                            */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 21:31:29 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	cd(char *path)
{
	return (chdir(path));
}