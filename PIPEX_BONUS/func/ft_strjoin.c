/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:04:56 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/21 11:31:53 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sjoin;
	size_t	size;
	size_t	i;
	size_t	d;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	sjoin = malloc(size * sizeof(char));
	if (sjoin == 0)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		sjoin[i] = s1[i];
		i++;
	}
	d = 0;
	while (d < ft_strlen(s2))
	{
		sjoin[i + d] = s2[d];
		d++;
	}
	sjoin[i + d] = '\0';
	return (sjoin);
}
