/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentprinter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:50:38 by jrocha            #+#    #+#             */
/*   Updated: 2022/03/18 13:00:30 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	percentprinter(char *flags)
{
	int	i;

	i = 0;
	while (flags[i] == '%')
		i++;
	i = i / 2;
	while (i != 0)
	{
		ft_putchar_fd('%', 1);
		i--;
	}
	return (ft_strlen(flags) / 2);
}
