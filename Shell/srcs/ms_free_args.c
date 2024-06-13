/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_free_args.c              	                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 17:51:58 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 05:35:42 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ms_free_args(void *content)
{
	if (*(char **)content)
		free(*(char **)content);
	free(content);
}