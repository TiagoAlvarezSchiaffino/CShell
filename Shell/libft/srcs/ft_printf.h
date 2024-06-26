/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf.h      	                                                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 15:36:30 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 15:40:11 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct s_flags
{
	int		num;
	int		neg;
	int		zero;
	int		dot;
	int		hash;
	int		spc;
	int		plus;
	int		width;
	int		prec;
	char	d;
}	t_flags;

void	default_flag(t_flags *flags);
void	get_flags(const char *str, int *i, t_flags *flags);
void	print_hf(unsigned int n, char *base, t_flags *flags, int *wc);
void	print_stonf(char *n, t_flags *flags, int *wc);
void	print_nf(int n, t_flags *flags, int *wc);
void	print_pf(unsigned long string_addr, t_flags *flags, int *wc);
int		print_dupe(char c, int count);
void	print_sf(char *str, t_flags *flags, int *wc);
void	print_cf(char c, t_flags *flags, int *wc);
void	print_unf(unsigned int n, t_flags *glags, int *wc);

#endif