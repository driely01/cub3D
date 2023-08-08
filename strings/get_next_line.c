/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:29:04 by del-yvbg          #+#    #+#             */
/*   Updated: 2023/08/06 16:49:52 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_read(char **leftover, char *line, size_t i)
{
	size_t	j;
	char	*temp;
	size_t	lent;

	j = 0;
	temp = NULL;
	lent = ft_strlen(*leftover);
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (free(*leftover),*leftover = NULL, NULL);
	while (j <= i)
	{
		line[j] = (*leftover)[j];
		j++;
	}
	temp = ft_calloc((lent - i) + 1, sizeof(char));
	if (!temp)
		return (free(*leftover),*leftover = NULL
			, free(line), line = NULL, NULL);
	j = 0;
	while (++i <= lent)
		temp[j++] = (*leftover)[i];
	free(*leftover);
	*leftover = temp;
	return (line);
}

int	stc(t_collecion *vb)
{
	vb->r = 1;
	vb->i = -1;
	vb->bf = NULL;
	vb->ln = NULL;
	return (1);
}

char	*get_next_line(int fd)
{
	t_collecion	vb;
	static char	*left;

	while (!(stc(&vb) && (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)))
	{
		vb.bf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!vb.bf)
			return (NULL);
		vb.r = read(fd, vb.bf, BUFFER_SIZE);
		if (vb.r < 0 || (!vb.r && !left))
			return (free(left), left = 0, free(vb.bf), vb.bf = NULL, NULL);
		vb.bf[vb.r] = 0;
		left = ft_append(left, vb.bf);
		while (left[++vb.i])
			if (left[vb.i] == '\n')
				return (free(vb.bf), vb.bf = NULL, ft_read(&left, vb.ln, vb.i));
		vb.i--;
		free(vb.bf);
		vb.bf = NULL;
		if (vb.r == 0 && left[0])
			return (vb.ln = left, left = 0, vb.ln);
		if (vb.r == 0)
			return (free(left), left = 0, NULL);
	}
	return (free(left), left = 0, NULL);
}
