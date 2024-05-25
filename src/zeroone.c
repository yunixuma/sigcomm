/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeroone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/08/09 01:39:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
/*
__attribute__((destructor))
	static void destructor()
{
		system("leaks -q push_swap");
}
*/

volatile sig_atomic_t received_signal = -1;

void zero(int sig, siginfo_t *info, void *ctx)
{
        received_signal = 0;
}

void one(int sig, siginfo_t *info, void *ctx)
{
        received_signal = 1;
}

int     main(void)
{
        struct                  sigaction sa_zero;
        struct                  sigaction sa_one;
        unsigned char   c;
        size_t                  count;

        c = 0b00000000;
        count = 0;
        printf("%u\n", getpid());
        memset(&sa_one, 0, sizeof(sa_one));
        memset(&sa_zero, 0, sizeof(sa_zero));
        sa_zero.sa_sigaction = zero;
        sa_zero.sa_flags = SA_SIGINFO;
        sa_one.sa_sigaction = one;
        sa_one.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &sa_zero, NULL);
        sigaction(SIGUSR2, &sa_one, NULL);
        while (1)
        {
                if (received_signal == 0)
                {
                        c = c | (0b10000000 >> count);
                        count++;
                        received_signal = -1;
                }
                else if (received_signal == 1)
                {
                        count++;
                        received_signal = -1;
                }
                if (count == 7)
                {
                        write(1, &c, 1);
                        count = 0;
                }
                sleep (1);
        }
}
