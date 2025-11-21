/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:00:02 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/21 21:00:33 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init(t_data *data);

int	ft_printf(int fd, char const *fmt, ...)
{
	t_data	data;
	va_list	args;
	int		res;

	if (!fmt)
		return (-1);
	init(&data);
	data.fd = fd;
	va_start(args, fmt);
	res = ft_parse(&data, fmt, &args);
	va_end(args);
	return (res);
}

int	ft_calclen_write(t_data *data, const char *str)
{
	int	len;

	len = 0;
	if (data->is_writing_mode)
	{
		while (*str)
		{
			ft_write_buffer(data, *str++);
			len++;
		}
	}
	else
		while (*str++)
			len++;
	return (len);
}

void	ft_write_buffer(t_data *data, int c)
{
	if (data->buflen >= BUFFER_SIZE)
		ft_flush_buffer(data, data->buflen);
	(data->buf)[(data->buflen)++] = c;
	(data->count)++;
}

void	ft_flush_buffer(t_data *data, size_t len)
{
	write(data->fd, data->buf, len);
	data->buflen = 0;
}

static void	init(t_data *data)
{
	data->buf[0] = 0;
	data->tempbuf[0] = 0;
	data->buflen = 0;
	data->count = 0;
	data->rcode = 0;
	data->fd = 1;
	data->is_writing_mode = FALSE;
	data->has_flag = FALSE;
	data->flags.minus = 0;
	data->flags.zero = 0;
	data->flags.plus = 0;
	data->flags.space = 0;
	data->flags.hash = 0;
	data->flags.width = -1;
	data->flags.precision = -1;
	data->flags.specifier = 0;
	data->flags.sign = '\0';
	data->flags.prefix[0] = '\0';
	data->flags.prefix[1] = '\0';
	data->flags.prefixlen = 0;
	data->flags.padding = 0;
	data->flags.precisionlen = 0;
	data->flags.is_ptr_nil = FALSE;
}
