/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/05 21:46:27 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

# include <sys/types.h>
# include <stdbool.h>
# include "minitalk_common.h"

# define MASK_CHAR	0xffff
# define SIZE_BUF	64
# define STR_INFO	"Server starts (PID: %d)\n"

typedef struct sigaction	t_sa;

int		main(void);
void	sv_inform(void);
int		sv_daemon(void);
int		sv_getbyte(void);
void	sv_catcher(void);
void	sv_handler(int signum, siginfo_t *info, void *context);
ssize_t	sv_printer(const char *str, ssize_t size);

#endif
