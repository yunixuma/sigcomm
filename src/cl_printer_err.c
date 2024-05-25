/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_printer_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/06 01:03:30 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

int	cl_printer_err_usage(void)
{
	prf_putstr(FD_STDERR, STR_USAGE_SYNTAX);
	ft_dprintf(FD_STDERR, STR_USAGE_PID, PID_MIN, PID_MAX);
	return (ERR_ARG);
}

int	cl_printer_err_pid(pid_t pid)
{
	ft_dprintf(FD_STDERR, STR_ERR_PID, pid);
	ft_dprintf(FD_STDERR, STR_USAGE_PID, PID_MIN, PID_MAX);
	return (ERR_PID);
}

int	cl_printer_err_sendchar(pid_t pid, size_t len, size_t i, unsigned char uc)
{
	prf_putstr(FD_STDERR, STR_ERR_SEND);
	ft_dprintf(FD_STDERR, STR_SENDSTR, uc, uc, i, len);
	ft_dprintf(FD_STDERR, STR_INFO_DEST, pid);
	return (ERR_SEND);
}

int	cl_printer_err_sendstr(pid_t pid)
{
	prf_putstr(FD_STDERR, STR_ERR_SEND);
	prf_putstr(FD_STDERR, STR_SENDSTR);
	ft_dprintf(FD_STDERR, STR_INFO_DEST, pid);
	return (ERR_SEND);
}

int	cl_printer_err_sendeot(pid_t pid)
{
	prf_putstr(FD_STDERR, STR_ERR_SEND);
	prf_putstr(FD_STDERR, STR_SENDNUL);
	ft_dprintf(FD_STDERR, STR_INFO_DEST, pid);
	return (ERR_SEND);
}
