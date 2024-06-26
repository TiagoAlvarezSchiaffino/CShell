/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_echo.c                   	                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 07:42:32 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Iterates through the args and finds the first '-' character. Check
 * whether it is a valid flag and only 'n' flag exists in the user input. Loops
 * through again for cases where the input is (echo -nn -nn Hi)
 * 
 * @param args Arguments that will be checked for flags
 * @return int flag count
 */
static int	get_flag(char **args)
{
	int	i;
	int	j;
	int	flag_count;

	i = 0;
	flag_count = 0;
	while (args[++i] != 0)
	{
		j = 1;
		if (args[i][0] == '-')
			while (args[i][j] == 'n')
				j++;
		if (args[i][j - 1] == 'n' && args[i][j] == '\0')
			flag_count++;
		else
			break ;
	}
	return (flag_count);
}

/**
 * @brief Gets the "-n" flag count from args. Using i starting from flag count,
 * iterate through the rest of args and print out all the variable. If flag_count
 * is 0 (no -n flag), prints out a "\n"
 * 
 * @param main Main struct (Can be NULL)
 * @param args Arguments that will be printed out
 * @return int 0 on success
 */
int	ms_echo(t_main *main, char **args)
{
	int	i;
	int	flag_count;

	if (args[1] == 0)
		return (ft_printf("\n") - 1);
	flag_count = get_flag(args);
	i = flag_count;
	while (args[++i] != 0)
	{
		ft_printf(args[i]);
		if (args[i + 1] != 0)
			ft_printf(" ");
	}
	if (flag_count == 0)
		ft_printf("\n");
	return (0);
	(void)main;
}