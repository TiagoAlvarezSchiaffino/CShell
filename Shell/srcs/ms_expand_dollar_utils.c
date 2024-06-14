/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_expand_dollar_utils.c                                                 */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 18:41:10 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 07:33:04 by Tiago                  /_____/ U         */
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
char	*ms_dlr_val(t_main *main, char *arg)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	while (ft_isalnum(arg[i]) || arg[i] == '?')
		i++;
	key = ft_calloc(i, sizeof(char));
	key[--i] = '\0';
	while (--i >= 0)
		key[i] = arg[i + 1];
	value = ms_get_envp_value(main->envp, key);
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
int	ms_val_in_quote(t_expand *exp)
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

/**
 * @brief Strjoins the value of $ to the current output
 * 
 * @param exp Expansion struct containing the argument, i position and
 * output string
 * @param d_value Value of $ expanded
 * @return int 0
 */
int	ms_strjoin_n_return(t_expand *exp, char *d_value)
{
	exp->output = ft_strjoin_free(exp->output, d_value);
	free(d_value);
	return (0);
}