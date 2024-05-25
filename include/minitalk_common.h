/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_common.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/06 00:53:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_COMMON_H
# define MINITALK_COMMON_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../lib/include/libfts.h"

# define FD_STDERR		2
# define RETURN_FAIL	-1
# define BITS_BYTE		8
# define ERR_NOERR 		0
# define SIG_NONE		-118
# define SIG_EOT		-116
# define US_PAUSE		10
# define US_SEND		50
# define CHAR_EOT		0x04U

typedef struct sigaction	t_sa;

#endif
