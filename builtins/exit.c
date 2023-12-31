/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <slampine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:39:51 by aotsala           #+#    #+#             */
/*   Updated: 2023/09/25 14:31:59 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_exit_num(char *arg)
{
	long long	num;

	num = ft_atoll(arg);
	if (check_long_long(arg))
		return (0);
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg)
	{
		if (ft_isdigit(*arg))
			arg++;
		else
			return (0);
	}
	return (1);
}

// If n is specified, but its value is not between 0
// and 255 inclusively, the exit status is undefined.
int	exit_mini(char **args)
{
	int	stat;

	stat = 0;
	ft_putendl_fd("exit\n", 2);
	if (args[1])
	{
		if (!is_valid_exit_num(args[1]))
		{
			n_errors(3, "exit: ", args[1], ": numeric argument required");
			stat = 255;
		}
		else if (args[2])
		{
			n_errors(2, "exit: ", "too many arguments");
			return (1);
		}
		else
			stat = (unsigned char)ft_atoll(args[1]);
	}
	exit(stat);
}
