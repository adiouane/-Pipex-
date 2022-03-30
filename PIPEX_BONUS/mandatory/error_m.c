/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:27:39 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/27 18:35:06 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error(char *s, int status_code)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(status_code);
}

void	error3(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
}

void	error2(int status_code)
{
	perror("pipex");
	exit(status_code);
}
