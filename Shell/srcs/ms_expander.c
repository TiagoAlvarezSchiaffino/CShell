/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_expander.c                                               	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 13:32:13 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 19:05:58 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Connects the current node of the argument with the list of files
 * 
 * @param current The current node of the argument
 * @param files The list of files
 * @param output The content that suppposingly will house the current node
 * @return t_list* Next node of the argument (Excluding the files)
 */
t_list	*connect_cur_with_cur(t_list *current, t_list *files, char *output)
{
	t_list	*end;

	end = current->next;
	ft_lstlast(files)->next = current->next;
	free(current->content);
	current->content = files->content;
	current->next = files->next;
	free(output);
	free(files);
	return (end);
}

/**
 * @brief Checks the final output and whether there was a conversion for $. If
 * final output is NULL, replaces it 
 * 
 * @param current The current node of the argument
 * @param output The content that will house the current node's content
 * @param dollar Whether a dollar conversion had taken place
 * @return t_list* next node of the argument
 */
t_list	*check_output_dollar(t_list *current, char **output, int dollar)
{
	if (*output == NULL)
	{
		free(current->content);
		current->content = ft_calloc(1, sizeof(char *));
		*(char **)current->content = NULL;
	}
	else if (dollar == 0)
		*(char **)current->content = *output;
	return (current->next);
}

/**
 * @brief Checks and expands the mandatory characters: '', "" and $, calling
 * their respective functions to do its respective expansion. If non of these
 * special characters are found, append the character to the output instead
 * 
 * @param main The main struct containing the environment list
 * @param cur_in The current node of the argument linked list
 * @param exp The expansion struct containing the argument, i position and
 * output string
 * @return int 1 if expansion of $ is done, else 0
 */
int	expand_mandatory(t_main *main, t_list **cur_in, t_expand *exp)
{
	t_list	*current;
	int		dollar;

	dollar = 0;
	current = *cur_in;
	if (*(exp->arg + exp->i) == '\'')
		expand_squote(exp);
	else if (*(exp->arg + exp->i) == '\"')
		expand_dquote(main, exp);
	else if (*(exp->arg + exp->i) == '$')
	{
		dollar = expand_dlr(&current, exp, dlr_val(main, exp->arg + exp->i));
		while (exp->arg[exp->i + 1] != '\0' && exp->arg[exp->i + 1] != '\''
			&& exp->arg[exp->i + 1] != '\"' && exp->arg[exp->i + 1] != '$')
				exp->i++;
	}
	else
		exp->output = append_char(exp->output, *(exp->arg + exp->i));
	exp->i++;
	*cur_in = current;
	return (dollar);
}

/**
 * @brief The main expanding function, looks for special characters like: '',
 * "", $ and *. If any of these are found they are expanded to their values.
 * Expansion is done by creating linked lists and replacing its head to the
 * current node, taking its place
 * 
 * @param main The main struct containing the environment list
 * @param exp The expansion struct containing the argument, i position and
 * output string
 * @param current The current node of the argument linked list
 * @return t_list* Next argument node that will be expanded
 */
t_list	*expand(t_main *main, t_expand *exp, t_list *current)
{
	t_list	*files;
	int		dollar;

	exp->i = 0;
	exp->output = NULL;
	while (*(exp->arg + exp->i) != '\0')
	{
		dollar = 0;
		if (*(exp->arg + exp->i) == '*' && check_star(exp->arg))
		{
			files = get_files_from_dir(exp->arg);
			if (files == NULL)
			{
				ft_lstclear(&files, &free);
				exp->output = append_char(exp->output, *(exp->arg + exp->i));
			}
			else
				return (connect_cur_with_cur(current, files, exp->output));
		}
		dollar = expand_mandatory(main, &current, exp);
	}
	return (check_output_dollar(current, &exp->output, dollar));
}

/**
 * @brief The main expander function, loops through every argument provided and
 * expand it. The expanders expands the following: '', "", $KEY, $?, * into their
 * respective raw values
 * 
 * @param main The main struct containing the environment list
 * @param args The arguments from user input
 */
void	expander(t_main *main, t_list **args)
{
	t_list		*arg_lst;
	t_expand	exp;

	arg_lst = *args;
	if (arg_lst == NULL)
	{
		*args = ft_lstnew(ft_calloc(1, sizeof(char *)));
		return ;
	}
	while (arg_lst != NULL)
	{
		exp.arg = *(char **)arg_lst->content;
		arg_lst = expand(main, &exp, arg_lst);
	}
	ft_lstadd_back(args, ft_lstnew(ft_calloc(1, sizeof(char *))));
}