/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_daemon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/06 01:04:42 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

int	sv_daemon(void)
{
	char	str[SIZE_BUF];
	int		byteval;
	ssize_t	i_char;

	i_char = 0;
	while (true)
	{
		byteval = sv_getbyte();
		str[i_char] = byteval;
		i_char++;
		if (byteval == CHAR_EOT || i_char == SIZE_BUF)
		{
			sv_printer(str, i_char);
			i_char = 0;
		}
	}
	return (0);
}
