/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_check_dangling.c                                                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 16:14:45 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 16:21:57 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>
#include <errno.h>

/**
 * @brief Checks string for uneven / dangling brackets
 * 
 * @param str String to check
 * @param open Open char
 * @param close Close char
 * @return int 0 if no dangling brackets, >0 if more open than close, <0 if more
 * 			close than open
 */
static int	ms_has_dangling_bracket(char *str, char open, char close)
{
	int	i;

	i = 0;
	while (*str)
	{
		i += (*str == open) - (*str == close);
		str++;
	}
	return (i);
}

/**
 * @brief Checks string for uneven / dangling quotes
 * 
 * @param str String to check
 * @param c Char to check
 * @return int 0 if no dangling quotes, 1 if there is a dangling quote
 */
static int	ms_has_dangling_quote(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i = !i;
		str++;
	}
	return (i);
}

/**
 * @brief 	Checks string for dangling single quotes ',
 * 			dangling double quotes ", and
 * 			dangling parentheses ()\
 * @brief	Prints error if there are dangling chars.
 * 
 * @param str String to check
 * @return int 0 if there is no dangling characters, 1 if there are.
 */
int	ms_check_dangling(char *str)
{
	int	res;

	res = 0;
	if (ms_has_dangling_quote(str, '\''))
	{
		res = 1;
		ft_dprintf(2, "minishell: syntax error dangling single quote\n");
	}
	else if (ms_has_dangling_quote(str, '"'))
	{
		res = 1;
		ft_dprintf(2, "minishell: syntax error dangling double quote\n");
	}
	else if (ms_has_dangling_bracket(str, '(', ')'))
	{
		res = 1;
		ft_dprintf(2, "minishell: syntax error dangling bracket\n");
	}
	return (res);
}