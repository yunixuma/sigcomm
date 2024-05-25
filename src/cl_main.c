/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/06 03:03:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
/*
__attribute__((destructor))
	static void destructor()
{
		system("leaks -q push_swap");
}
*/

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	errno = 0;
	if ((INDEX_ARGPID < INDEX_ARGMSG && argc != INDEX_ARGMSG + OFFSET_ARG) \
		|| (INDEX_ARGPID > INDEX_ARGMSG && argc != INDEX_ARGPID + OFFSET_ARG))
		exit (cl_printer_err_usage());
	pid = ft_atoi(argv[INDEX_ARGPID]);
	if (pid < PID_MIN || pid > PID_MAX)
		exit (cl_printer_err_pid(pid));
	str = argv[INDEX_ARGMSG];
	cl_catcher();
	if (cl_sender_str(pid, str) != ERR_NOERR)
		return (cl_printer_err_sendstr(pid));
	return (cl_printer_ok(pid, str));
}
