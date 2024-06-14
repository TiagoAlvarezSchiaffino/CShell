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
/*   Updated: 2024/06/14 07:44:08 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>
#include <errno.h>

/**
 * @brief Checks string for uneven or dangling brackets
 * 
 * @param str String to check
 * @param open Open character
 * @param close Close character
 * @param ignore String to ignore
 * @return int 0 if no dangling brackets, >0 if more open than close, <0 if more
 * close than open
 */
static int	ms_has_dangling_bracket(char *str, char open, char close,
	char *ignore)
{
	int		i;
	char	ignore_char;

	i = 0;
	while (*str)
	{
		if (ft_strchr(ignore, *str) != 0)
		{
			if (ignore_char == *str)
				ignore_char = '\0';
			else if (ignore_char == '\0')
				ignore_char = *str;
		}
		if (!ignore_char)
			i += (*str == open) - (*str == close);
		str++;
	}
	return (i);
}

/**
 * @brief Checks string for uneven or dangling quotes
 * 
 * @param str String to check
 * @param c Character to check
 * @param ignore String to ignore
 * @return int 0 if no dangling quotes, 1 if there is a dangling quote
 */
static int	ms_has_dangling_quote(char *str, char c, char *ignore)
{
	int	i;
	int	ignore_flag;

	i = 0;
	ignore_flag = 0;
	while (*str)
	{
		if (ft_strchr(ignore, *str) != 0 && !i)
			ignore_flag = !ignore_flag;
		if (*str == c && !ignore_flag)
			i = !i;
		str++;
	}
	return (i);
}

/**
 * @brief Checks string for dangling single quotes ', dangling double quotes ",
 * and dangling parentheses (). Prints error if there are dangling chars.
 * 
 * @param str String to check
 * @return int 0 if there is no dangling characters, else 1
 */
int	ms_check_dangling(char *str)
{
	int	res;

	res = 0;
	if (ms_has_dangling_quote(str, '\'', "\""))
	{
		res = 1;
		ft_dprintf(2, "shell: syntax error dangling single quote\n");
	}
	else if (ms_has_dangling_quote(str, '"', "'"))
	{
		res = 1;
		ft_dprintf(2, "shell: syntax error dangling double quote\n");
	}
	else if (ms_has_dangling_bracket(str, '(', ')', "'\""))
	{
		res = 1;
		ft_dprintf(2, "shell: syntax error dangling bracket\n");
	}
	return (res);
}