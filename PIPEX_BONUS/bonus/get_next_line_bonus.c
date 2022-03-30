/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:02:04 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/21 11:30:23 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	get_next_line(char **line)
{
	char	*buffer;
	int		index;
	int		read_byte;
	char	character;

	index = 0;
	read_byte = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	read_byte = read(STDIN_FILENO, &character, 1);
	while (read_byte && character != '\n' && character != '\0')
	{
		if (character != '\n' && character != '\0')
			buffer[index] = character;
		index++;
		read_byte = read(STDIN_FILENO, &character, 1);
	}
	buffer[index] = '\n';
	buffer[++index] = '\0';
	*line = buffer;
	free(buffer);
	return (read_byte);
}
