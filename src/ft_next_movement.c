/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:55:40 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/06 13:55:43 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* ************************************************************************** */
/*                                                                            */
/* Dans cette fichier, nous avons la version commentee de ceux s'adapte avec  */
/* la taille variable et juste en bas celles qui ont de mouvement de taille   */
/* fixe avec un bloc de 60 x 60                                               */
/*                                                                            */
/* ************************************************************************** */

// void	let_mov_south(t_data *data, t_forb *forb, t_forb *tmp)
// {
// 	int		limw;
// 	int		limh;
// 	int		inith;
// 	int		initw;

// 	tmp = forb;
// 	while (forb && forb->next)
// 	{
// 		initw = forb->width * data->dim->wb;
// 		limw = (forb->width + 1) * data->dim->wb;
// 		inith = forb->height * data->dim->hb;
// 		limh = (forb->height + 1) * data->dim->hb;
// 		if (data->player->posw > initw && data->player->posw < limw &&
// 			data->player->posh + 4 >= inith && data->player->posh < limh)
// 		{
// 			forb = tmp;
// 			return ;
// 		}
// 		forb = forb->next;
// 	}
// 	forb = tmp;
// 	data->player->posh += 2;
// }

// void	let_mov_north(t_data *data, t_forb *forb, t_forb *tmp)
// {
// 	int		limw;
// 	int		limh;
// 	int		inith;
// 	int		initw;

// 	tmp = forb;
// 	while (forb && forb->next)
// 	{
// 		initw = forb->width * data->dim->wb;
// 		limw = (forb->width + 1) * data->dim->wb;
// 		inith = forb->height * data->dim->hb;
// 		limh = (forb->height + 1) * data->dim->hb;
// 		if (data->player->posw > initw && data->player->posw < limw &&
// 			data->player->posh - 4 <= limh && data->player->posh > inith)
// 		{
// 			forb = tmp;
// 			return ;
// 		}
// 		forb = forb->next;
// 	}
// 	forb = tmp;
// 	data->player->posh -= 2;
// }

// void	let_mov_east(t_data *data, t_forb *forb, t_forb *tmp)
// {
// 	int		limw;
// 	int		limh;
// 	int		inith;
// 	int		initw;

// 	tmp = forb;
// 	while (forb && forb->next)
// 	{
// 		initw = forb->width * data->dim->wb;
// 		limw = (forb->width + 1) * data->dim->wb;
// 		inith = forb->height * data->dim->hb;
// 		limh = (forb->height + 1) * data->dim->hb;
// 		if (data->player->posh > inith && data->player->posh < limh &&
// 			data->player->posw +4 >= initw && data->player->posw < limw)
// 		{
// 			forb = tmp;
// 			return ;
// 		}
// 		forb = forb->next;
// 	}
// 	forb = tmp;
// 	data->player->posw += 2;
// }

// void	let_mov_west(t_data *data, t_forb *forb, t_forb *tmp)
// {
// 	int		limw;
// 	int		limh;
// 	int		inith;
// 	int		initw;

// 	tmp = forb;
// 	while (forb && forb->next)
// 	{
// 		initw = forb->width * data->dim->wb;
// 		limw = (forb->width + 1) * data->dim->wb;
// 		inith = forb->height * data->dim->hb;
// 		limh = (forb->height + 1) * data->dim->hb;
// 		if (data->player->posh > inith && data->player->posh < limh &&
// 			data->player->posw -4 <= limw && data->player->posw > initw)
// 		{
// 			forb = tmp;
// 			return ;
// 		}
// 		forb = forb->next;
// 	}
// 	forb = tmp;
// 	data->player->posw -= 2;
// }

void	let_mov_south(t_data *data, t_forb *forb, t_forb *tmp)
{
	int		limw;
	int		limh;
	int		inith;
	int		initw;

	tmp = forb;
	while (forb && forb->next)
	{
		initw = forb->width * CUB_BWIDTH;
		limw = (forb->width + 1) * CUB_BWIDTH;
		inith = forb->height * CUB_BHEIGHT;
		limh = (forb->height + 1) * CUB_BHEIGHT;
		if (data->player->posw > initw && data->player->posw < limw
			&& data->player->posh + 4 >= inith && data->player->posh < limh)
		{
			forb = tmp;
			return ;
		}
		forb = forb->next;
	}
	forb = tmp;
	data->player->posh += 2;
}

void	let_mov_north(t_data *data, t_forb *forb, t_forb *tmp)
{
	int		limw;
	int		limh;
	int		inith;
	int		initw;

	tmp = forb;
	while (forb && forb->next)
	{
		initw = forb->width * CUB_BWIDTH;
		limw = (forb->width + 1) * CUB_BWIDTH;
		inith = forb->height * CUB_BHEIGHT;
		limh = (forb->height + 1) * CUB_BHEIGHT;
		if (data->player->posw > initw && data->player->posw < limw
			&& data->player->posh - 4 <= limh && data->player->posh > inith)
		{
			forb = tmp;
			return ;
		}
		forb = forb->next;
	}
	forb = tmp;
	data->player->posh -= 2;
}

void	let_mov_east(t_data *data, t_forb *forb, t_forb *tmp)
{
	int		limw;
	int		limh;
	int		inith;
	int		initw;

	tmp = forb;
	while (forb && forb->next)
	{
		initw = forb->width * CUB_BWIDTH;
		limw = (forb->width + 1) * CUB_BWIDTH;
		inith = forb->height * CUB_BHEIGHT;
		limh = (forb->height + 1) * CUB_BHEIGHT;
		if (data->player->posh > inith && data->player->posh < limh
			&& data->player->posw + 4 >= initw && data->player->posw < limw)
		{
			forb = tmp;
			return ;
		}
		forb = forb->next;
	}
	forb = tmp;
	data->player->posw += 2;
}

void	let_mov_west(t_data *data, t_forb *forb, t_forb *tmp)
{
	int		limw;
	int		limh;
	int		inith;
	int		initw;

	tmp = forb;
	while (forb && forb->next)
	{
		initw = forb->width * CUB_BWIDTH;
		limw = (forb->width + 1) * CUB_BWIDTH;
		inith = forb->height * CUB_BHEIGHT;
		limh = (forb->height + 1) * CUB_BHEIGHT;
		if (data->player->posh > inith && data->player->posh < limh
			&& data->player->posw - 4 <= limw && data->player->posw > initw)
		{
			forb = tmp;
			return ;
		}
		forb = forb->next;
	}
	forb = tmp;
	data->player->posw -= 2;
}
