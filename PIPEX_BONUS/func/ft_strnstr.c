/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:02:44 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/21 22:02:45 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	h;
	unsigned int	n;

	h = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[h] && len > h)
	{
		if (haystack[h] == needle[0])
		{
			n = 0;
			while (haystack[h + n] == needle[n] && (h + n) < len)
			{
				if (needle [n + 1] == '\0')
					return ((char *)&haystack[h]);
				n++;
			}
		}
		h++;
	}
	return (0);
}
