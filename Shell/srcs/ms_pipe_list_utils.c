/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_pipe_list_utils.c                                                     */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 17:51:58 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 17:52:31 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ms_pipe_list_free_args(void *content)
{
	free(*(char **)content);
	free(content);
}