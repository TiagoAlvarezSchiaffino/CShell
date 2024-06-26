/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_dprintf.c                                                             */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 14:32:08 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 14:39:58 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ftdpf_print_args(int fd, va_list args, t_ftdpf_flags *flags)
{
	int	count;

	count = 0;
	if (flags->sr == 'c')
		count += ftdpf_char(fd, va_arg(args, int), flags);
	else if (flags->sr == 's')
		count += ftdpf_str(fd, va_arg(args, char *), flags);
	else if (flags->sr == 'i' || flags->sr == 'd')
		count += ftdpf_int(fd, va_arg(args, int), flags);
	else if (flags->sr == 'u')
		count += ftdpf_int(fd, va_arg(args, unsigned int), flags);
	else if (flags->sr == 'x')
		count += ftdpf_hex(fd, va_arg(args, unsigned int), flags,
				"0x0123456789abcdef");
	else if (flags->sr == 'X')
		count += ftdpf_hex(fd, va_arg(args, unsigned int), flags,
				"0X0123456789ABCDEF");
	else if (flags->sr == 'p')
		count += ftdpf_ptr(fd, va_arg(args, unsigned long), flags,
				"0x0123456789abcdef");
	else if (flags->sr == '%')
		count += write(fd, "%", 1);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list			args;
	t_ftdpf_flags	*flags;
	int				i;
	int				count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			flags = ftdpf_get_flags((char *)format, &i);
			if (!flags)
				return (0);
			count += ftdpf_print_args(fd, args, flags);
			free(flags);
		}
		else
			count += write(fd, format + i, 1);
		i++;
	}
	va_end(args);
	return (count);
}