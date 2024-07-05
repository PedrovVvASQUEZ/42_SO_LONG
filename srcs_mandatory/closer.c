/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:09:14 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/17 16:15:58 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_jeu *jeu)
{
	destroy_images(jeu);
	destroy_hero(jeu);
	destroy_bad_guy(jeu);
	destroy_spawn(jeu);
	destroy_collectible(jeu);
	if (jeu->win != NULL)
		mlx_destroy_window(jeu->mlx, jeu->win);
	mlx_destroy_display(jeu->mlx);
	ft_free_tab(jeu->map);
	free(jeu->mlx);
	free(jeu);
	exit (0);
}

int	close_partial(t_jeu *jeu, char *s)
{
	ft_putstr_fd(s, 2);
	mlx_destroy_display(jeu->mlx);
	ft_free_tab(jeu->map);
	free(jeu->mlx);
	free(jeu);
	exit(0);
}
