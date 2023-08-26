/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:36:40 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/26 02:01:14 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_error_fd(void)
{
	write(2, "Error\n", 6);
	write(2, "failed open fd\n", 15);
	exit(1);
}

void	print_error_malloc(void)
{
	write(2, "Error\n", 6);
	write(2, "failed malloc\n", 15);
	exit(1);
}