/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcmp.c                                                               */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 17:12:26 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 14:44:09 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
		index++;
	return (s1[index] - s2[index]);
}