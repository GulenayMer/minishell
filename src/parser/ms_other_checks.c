/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_other_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:48:10 by mgulenay          #+#    #+#             */
/*   Updated: 2022/09/02 14:49:23 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* finds  dollar sign in the string
 + if env comes after we need to get env variable
 + if ? comes after we need to get exit status of the previous command call
 + if '$ENV' prints $ENV but if "$ENV" , print env variable
 + same also for $?
 */
/* char	*check_d_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == DOLLAR)
			return (&str[i]);
		i++;	
	}
	return (0);
} */