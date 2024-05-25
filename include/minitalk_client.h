/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/06 03:01:01 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include "minitalk_common.h"

# define ERR_ARG			EINVAL
# define ERR_PID			ESRCH
# define ERR_SEND			ECONNABORTED
# define OFFSET_ARG			1
# define INDEX_ARGPID		1
# define INDEX_ARGMSG		2
# define PID_MAX			99999
# define PID_MIN			100
# define STR_SUCCESS		"Successfully sent %zu "
# define STR_BYTE			"Byte"
# define STR_BYTES			"Bytes"
# define STR_ERR_SEND		"Error occured during sending "
# define STR_SENDCHAR		"a byte string '%c'(%x) (%zu / %zu B)"
# define STR_SENDSTR		"the message"
# define STR_SENDNUL		"a End-of-Transmission character"
# define STR_INFO_DEST		" to the server running as PID %d\n"
# define STR_ERR_PID		"Invalid process ID: %d\n"
# define STR_USAGE_SYNTAX	"Usage: ./client <PID> [STRING]\n"
# define STR_USAGE_PID		"PID: %d - %d\n"
# define STR_TERM			"'\\0'"

int		main(int argc, char **argv);
void	cl_handler(int signum, siginfo_t *info, void *context);
void	cl_catcher(void);
int		cl_sender_str(pid_t pid, const char *str);
int		cl_sender_eot(pid_t pid);
int		cl_printer_err_usage(void);
int		cl_printer_err_pid(pid_t pid);
int		cl_printer_err_sendchar(pid_t pid, size_t len, size_t i, \
	unsigned char uc);
int		cl_printer_err_sendstr(pid_t pid);
int		cl_printer_err_sendeot(pid_t pid);
int		cl_printer_ok(pid_t pid, const char *str);

#endif
