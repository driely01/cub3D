/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/10 20:36:41 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int main(int argc, char **argv)
// {
//     t_cub   img;

//     if (argc == 2)
//     {
//         if (!check_file_name(argv[1]))
//             return (printf("invalid file\n"), 1);
//         fill_map_array(&img, argv[1]);
//         img.cordt.width = find_tall_line(&img) * UNIT;
//         img.cordt.height = count_lines_map(argv[1]) * UNIT;
//         init_win_put_img(&img, 1);
//         if (!draw_mini_map(&img))
//         {
//             printf("there is no map\n");
//             return (1);
//         }
//         init_win_put_img(&img, 2);
//     }
//     else
//         printf("no file entered\n");
//     return (0);
// }

int main(void)
{
    t_cub   img;
    init_win_put_img(&img, 1);
    img.rot.px = 300;
    img.rot.py = 300;
    img.rot.pa = 3 * PI / 2;
    img.rot.pdx = cos(img.rot.pa) * 5;
    img.rot.pdy = sin(img.rot.pa) * 5;
    printf("pa = %f\n", img.rot.pa);
    img.color = 0xffffff;
    check_before_draw(&img, img.rot.px, img.rot.py, img.rot.px + img.rot.pdx * 50, img.rot.py + img.rot.pdy * 50);
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
    init_win_put_img(&img, 2);
    return (0);
}