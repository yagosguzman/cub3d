/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:10:07 by ysanchez          #+#    #+#             */
/*   Updated: 2024/07/18 19:32:15 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size + 1, sizeof(char));
	if (!ptr)
		return (ft_exit_error);
	return (ptr);
}

void	*safe_free(void **ptr)
{
	if (ptr)
	{
		free(ptr[0]);
		ptr[0] = NULL;
	}
	return (NULL);
}

void	safe_write(t_game *game, int fd, char c)
{
	if (write(fd, &c, sizeof(c)) < 0)
		ft_error(&game, 3, NULL);
}

void	ft_exit_error(void)
{
	perror(NULL);
	exit(errno);
}
