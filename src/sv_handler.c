/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/06 01:03:43 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

static volatile sig_atomic_t	g_signum = SIG_NONE;

void	sv_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	usleep(US_SEND);
	if (g_signum == SIG_EOT && signum == SIGUSR1)
		kill(info->si_pid, SIGUSR2);
	else
		kill(info->si_pid, SIGUSR1);
	g_signum = signum;
}

int	sv_getbyte(void)
{
	int	byteval;
	int	i_digit;

	byteval = 0x00;
	i_digit = 0;
	while (i_digit < BITS_BYTE)
	{
		pause();
		if (g_signum == SIGUSR1 || g_signum == SIGUSR2)
		{
			byteval <<= 1;
			if (g_signum == SIGUSR2)
				byteval += 1;
			g_signum = SIG_NONE;
			i_digit += 1;
		}
		if (i_digit == BITS_BYTE - 1 && byteval == (CHAR_EOT >> 1))
			g_signum = SIG_EOT;
	}
	return (byteval);
}
