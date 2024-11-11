/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:00:57 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/11 22:01:01 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// Carte (1 = mur, 0 = vide, P = position du joueur)
char *map[MAP_HEIGHT] = {
    "1111111",
    "100P001",
    "1000001",
    "1000001",
    "1000001",
    "1001001",
    "1111111"
};

// Fonction principale
int main()
{
    t_data data;

    // Initialisation de MinilibX
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Raycasting");

    // Initialiser l'image pour le rendu global
    data.win_tex.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
    data.win_tex.addr = mlx_get_data_addr(data.win_tex.img, &data.win_tex.bpp, &data.win_tex.line_length, &data.win_tex.endian);
    
    // Position initiale du joueur (trouver P dans la carte)
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map[y][x] == 'P') {
                data.player.x = x + 0.5; // Position centrale dans le carré
                data.player.y = y + 0.5;
                data.player.angle = M_PI / 2.0; // Joueur regardant vers le haut (Nord)
                break;
            }
        }
    }

    // Charger les textures (ici simplement des images .xpm pour le mur, sol et plafond)
    init_image(&data, &data.wall_tex, "wall.xpm");
    init_image(&data, &data.floor_tex, "floor.xpm");
    init_image(&data, &data.ceiling_tex, "ceiling.xpm");

    // Rendu initial
    render(&data);

    // Boucle principale
    mlx_loop(data.mlx);

    return 0;
}
