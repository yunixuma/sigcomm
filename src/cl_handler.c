/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/06 01:02:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

static volatile sig_atomic_t	g_signum = SIG_NONE;

void	cl_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	g_signum = signum;
}

int	cl_sender_str(pid_t pid, const char *str)
{
	unsigned char	uc;
	size_t			len;
	size_t			i_char;
	int				bitval;
	int				i_digit;

	len = ft_strlen(str);
	i_char = 0;
	while (i_char < len)
	{
		uc = (unsigned char)str[i_char++];
		i_digit = 0;
		while (i_digit < BITS_BYTE)
		{
			g_signum = SIG_NONE;
			bitval = (uc >> (BITS_BYTE - 1 - i_digit)) & 0x01;
			if (kill(pid, SIGUSR1 + bitval * (SIGUSR2 - SIGUSR1)) \
				== RETURN_FAIL)
				exit(cl_printer_err_sendchar(pid, len, i_char, uc));
			pause();
			usleep(US_SEND);
			i_digit++;
		}
	}
	return (cl_sender_eot(pid));
}

int	cl_sender_eot(pid_t pid)
{
	unsigned char	uc;
	int				bitval;
	int				i_digit;

	uc = CHAR_EOT;
	i_digit = 0;
	while (i_digit < BITS_BYTE)
	{
		g_signum = SIG_NONE;
		bitval = (uc >> (BITS_BYTE - 1 - i_digit)) & 0x01;
		if (kill(pid, SIGUSR1 + bitval * (SIGUSR2 - SIGUSR1)) \
			== RETURN_FAIL)
			exit(cl_printer_err_sendeot(pid));
		pause();
		usleep(US_SEND);
		i_digit++;
	}
	return (SIGUSR2 - g_signum);
}
