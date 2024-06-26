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
/*   Updated: 2024/06/13 17:52:35 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Appends a character to the back of a string and returns the memmory
 * allocated resulting string, freeing the original one.
 * 
 * @param input String input to be appended
 * @param c Character to be appended to the back of a string
 * @return char* The result string after appending
 */
char	*append_char(char *input, char c)
{
	char	*output;
	int		size;
	int		i;

	size = 0;
	i = 0;
	if (input != NULL)
		size = ft_strlen(input);
	output = ft_calloc(size + 2, sizeof(char));
	if (input != NULL)
	{
		while (input[i] != '\0')
		{
			output[i] = input[i];
			i++;
		}
	}
	output[i] = c;
	output[i + 1] = '\0';
	free(input);
	return (output);
}

/**
 * @brief Connects the head node of the files linked list to the current node of
 * the argument and returns the next node of the argument linked list to be
 * expanded
 * 
 * @param current Current node of the argument linked list
 * @param files List of files
 * @param output Content that suppposingly will house the current node
 * @return t_list* Next node of the argument to be expanded (Excluding the files)
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
 * final output is NULL, replaces the current node's content with '\0' instead.
 * Else if the final output is not NULL and there is no dollar conversion,
 * replace the current node's content with output
 * 
 * @param current Current node of the argument linked list
 * @param output Content that will house the current node's content
 * @param dollar Whether a dollar conversion had taken place
 * @return t_list* Next node of the argument linked list to be expanded
 */
t_list	*check_output_dollar(t_list *current, char *output, int dollar)
{
	if (output == NULL)
	{
		free(current->content);
		current->content = ft_calloc(1, sizeof(char *));
		*(char **)current->content = NULL;
	}
	else if (dollar == 0)
		*(char **)current->content = output;
	return (current->next);
}

/**
 * @brief This is the main expander function that will loop through every
 * argument provided from the user input and expands it. The expander will
 * expand '', "", $, and * to their respective raw values. This is done
 * through expanding the arguments twice. The first expansion will make things
 * easier for the second expansion to read and expand
 * 
 * @param main Main struct containing the environement array
 * @param args Arguments linked list to be expanded
 */
void	expander(t_main *main, t_list **args)
{
	t_list		*arg_lst;
	t_expand	exp;

	arg_lst = *args;
	if (arg_lst == NULL)
		return ;
	while (arg_lst != NULL)
	{
		exp.arg = *(char **)arg_lst->content;
		arg_lst = expand_first_phase(main, &exp, arg_lst);
		free(exp.arg);
	}
	ms_expander_delete_null(args);
	arg_lst = *args;
	while (arg_lst != NULL)
	{
		exp.arg = *(char **)arg_lst->content;
		arg_lst = expand_second_phase(&exp, arg_lst);
		free(exp.arg);
	}
	ft_lstadd_back(args, ft_lstnew(ft_calloc(1, sizeof(char *))));
}