/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   get_next_line.h                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 18:58:57 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 20:27:08 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft.h"

char	*ft_strcomb(char *dst, char *src);
int		checkend(char c);

#endif