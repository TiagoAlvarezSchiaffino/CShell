/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_expand_dlr.c                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 18:41:10 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 17:35:59 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Expands the $ symbol by finding its value. Gets the key from the arg
 * and use the key to loop through every environment variable from main to find a
 * matching key
 * 
 * @param main Main struct containing the environement array
 * @param arg Argument containing the key
 * @return char* value if a matching key is found, else returns NULL 
 */
char	*dlr_val(t_main *main, char *arg)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	while (arg[i] != '\0' && arg[i] != '\''
		&& arg[i] != '\"' && arg[i] != '$' && arg[i] != '*')
		i++;
	key = ft_calloc(i, sizeof(char));
	key[--i] = '\0';
	while (--i >= 0)
		key[i] = arg[i + 1];
	value = get_envp_value(main->envp, key);
	free(key);
	return (value);
}

/**
 * @brief Checks whether there is anything inside the ""
 * 
 * @param exp Expansion struct containing the argument, i position and
 * output string
 * @return int 1 if there is, else 0
 */
int	val_in_quote(t_expand *exp)
{
	int	wc;
	int	i;

	i = exp->i;
	wc = 0;
	while (exp->arg[i + 1] != '\0' && exp->arg[i + 1] != '\"')
	{
		wc++;
		i++;
	}
	return (wc > 0);
}