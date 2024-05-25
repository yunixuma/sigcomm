/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_printer_ok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/05 21:44:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

int	cl_printer_ok(pid_t pid, const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	ft_printf(STR_SUCCESS, len);
	if (len > 1)
		prf_putstr(FD_STDOUT, STR_BYTES);
	else
		prf_putstr(FD_STDOUT, STR_BYTE);
	ft_printf(STR_INFO_DEST, pid);
	return (ERR_NOERR);
}
