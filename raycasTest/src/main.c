#include "../include/cube3d.h"
#include <math.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define FOV 60.0 // Champ de vision de 60°

#define MAP_WIDTH 5
#define MAP_HEIGHT 7

// Carte (1 = mur, 0 = vide, P = position du joueur)
char *map[MAP_HEIGHT] = {
    "11111",
    "10101",
    "10001",
    "10P01",
    "10001",
    "10101",
    "11111"
};

// Structures pour gérer l'image
typedef struct s_image {
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
    int width;
    int height;
} t_image;

typedef struct s_player {
    double x;
    double y;
    double angle; // Direction de vue du joueur
} t_player;

typedef struct s_data {
    void *mlx;
    void *win;
    t_player player;
    t_image win_tex;     // Image pour le rendu de la fenêtre
    t_image wall_tex;    // Texture des murs
    t_image floor_tex;   // Texture du sol
    t_image ceiling_tex; // Texture du plafond
} t_data;

// Fonction pour initialiser l'image
void init_image(t_data *data, t_image *img, char *filename) {
    img->img = mlx_xpm_file_to_image(data->mlx, filename, &img->width, &img->height);
    if (!img->img) {
        printf("Erreur de chargement de l'image: %s\n", filename);
        exit(1);
    }
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
}

// Fonction pour dessiner un pixel sur l'image
void my_mlx_pixel_put(t_image *img, int x, int y, int color) {
    int pixel_index;

    if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT) {
        pixel_index = (y * img->line_length + x * (img->bpp / 8));
        *(unsigned int *)(img->addr + pixel_index) = color;
    }
}

// Fonction pour obtenir la couleur d'un pixel dans une texture
int get_texture_pixel(t_image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return 0; // Retourner noir si on sort des limites
    int pixel_index = (y * img->line_length + x * (img->bpp / 8));
    return *(unsigned int *)(img->addr + pixel_index);
}

// Fonction de raycasting (calcul de la distance et projection)
void cast_ray(t_data *data, double ray_angle, int column) {
    double ray_x = data->player.x;
    double ray_y = data->player.y;
    double ray_dx = cos(ray_angle);
    double ray_dy = sin(ray_angle);
    double distance = 0;
    int hit = 0;

    // Lancer le rayon jusqu'à rencontrer un mur
    while (!hit) {
        ray_x += ray_dx * 0.1;
        ray_y += ray_dy * 0.1;
        distance += 0.1;

        // Vérifier si on touche un mur
        int map_x = (int)ray_x;
        int map_y = (int)ray_y;
        if (map_y >= 0 && map_y < MAP_HEIGHT && map_x >= 0 && map_x < MAP_WIDTH) {
            if (map[map_y][map_x] == '1') {
                hit = 1;
            }
        }
    }

    // Projeter l'image en fonction de la distance
    int line_height = (int)(WIN_HEIGHT / distance);
    int line_start = (WIN_HEIGHT - line_height) / 2;
    int line_end = line_start + line_height;

    // Calculer le point sur la texture à afficher en fonction de la distance
    int texture_x = (int)(ray_x * 64) % data->wall_tex.width; // Calcul de la position sur la texture
    for (int y = line_start; y < line_end; y++) {
        int texture_y = (int)((y - line_start) / (double)line_height * data->wall_tex.height);
        int color = get_texture_pixel(&data->wall_tex, texture_x, texture_y);
        my_mlx_pixel_put(&data->win_tex, column, y, color);  // Utiliser `win_tex` pour afficher la scène
    }
}

// Fonction pour gérer l'affichage global
void render(t_data *data) {
    // Remplir l'écran avec le plafond et le sol
    for (int y = 0; y < WIN_HEIGHT / 2; y++) {
        for (int x = 0; x < WIN_WIDTH; x++) {
            my_mlx_pixel_put(&data->win_tex, x, y, 0x87CEEB); // Plafond bleu clair
            my_mlx_pixel_put(&data->win_tex, x, WIN_HEIGHT - y - 1, 0x2E8B57); // Sol vert
        }
    }

    // Lancer le raycasting pour chaque colonne
    for (int column = 0; column < WIN_WIDTH; column++) {
        double ray_angle = data->player.angle - FOV / 2.0 + (column / (double)WIN_WIDTH) * FOV;
        cast_ray(data, ray_angle, column);
    }

    // Afficher l'image de la scène dans la fenêtre
    mlx_put_image_to_window(data->mlx, data->win, data->win_tex.img, 0, 0);
}

// Fonction principale
int main() {
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
