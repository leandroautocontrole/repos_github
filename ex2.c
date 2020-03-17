/***************************************************************************
 *   ex2.c                                        Version 20200314.113714  *
 *                                                                         *
 *   TEORIA DO CAOS, GERAR 10 PENDULOS EM ANIMACAO GRAFICA COM ALLEGRO     *
 *                                                                         *
 *   Copyright (C) 2020                            by Leandro Dantas Lima  *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Leandro Dantas Lima                                                   *
 *   Email: leandroautocontrole@gmail.com                                  *
 *   Webpage: http://beco.poli.br/leandroautocontrole@gmail.com            *
 *   Phone: (81) 98861-9469                                                *
 ***************************************************************************/

/* ----------------------------------------------------------------------- */
/* Instrucoes para compilar:
 *
 *    $gcc ex2.c -o ex2.x -Wall -lm `allegro-config --cflags --libs`
 *                                                                         */
/* ----------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <math.h>  /* Mathematics functions */
#include <allegro.h> /* Biblioteca para animacao grafica em C */

/* ---------------------------------------------------------------------- */
/* definitions */

#define PI 3.1415

/* ---------------------------------------------------------------------- */
/* Esta funcao simula o movimento de 10 pendulos duplos independentes, 
 * mostrando duas trajetorias numa abordagem caotica, a partir de animacoes
 * graficas utilizando a biblioteca <allegro.h>.
 * 
 * Ela recebe argumentos (normalmente inteiros) para definicao de formas,
 * cores, posicoes e argumentos de funcoes matematicas.
 *
 * E retorna EXIT_SUCCESS. */
/* ---------------------------------------------------------------------- */

int main(void)
{
    /* Inicialização da biblioteca allebro.h */
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);

    BITMAP *buffer = create_bitmap(800, 600);

    float fio1 = 100, fio2 = 100;       /* Comprimentos dos pêndulos */
    float m1 = 4, m2 = 4;               /* Massas dos pêndulos */
    double fi1 = 3*PI/5, fi2 = 3*PI/5;  /* Ângulos iniciais dos pêndulos */
    float fi1_v = 0, fi2_v = 0;         /* Velocidades iniciais dos pêndulos */
    float g = 9.81;                     /* Aceleração da gravidade local */
    int x0 = 400, y0 = 200;             /* Posição base do pêndulo */


    while(!key[KEY_ESC])                /* A simulação funciona enquanto a tecla <ESC> não for pressionada */
    {
        /* Particionando as equações do movimento do pêndulo baseadas no formalismo Lagrangeano */
        float part1 = -g*(2*m1 + m2)*sin(fi1);
        float part2 = -m2*g*sin(fi1 - (2*fi2));
        float part3 = -2*sin(fi1 - fi2)*m2;
        float part4 = (fi2_v)*(fi2_v)*fio2 + (fi1_v)*fio1*cos(fi1 - fi2);
        float denom = fio1*(2*m1 + m2 - m2*cos(2*fi1 - 2*fi2));
        float fi1_a = (part1 + part2 + part3*part4)/denom;

        float part1_2 = 2*sin(fi1 - fi2);
        float part2_2 = ((fi1_v)*(fi1_v)*fio1*(m1 + m2));
        float part3_2 = g*(m1 + m2)*cos(fi1);
        float part4_2 = (fi2_v)*(fi2_v)*fio2*m2*cos(fi1 - fi2);
        float denom_2 = fio2*(2*m2 + m2 - m2*cos(2*fi1 - 2*fi2));
        float fi2_a = ((part1_2)*((part2_2) + (part3_2) + (part4_2)))/denom_2;

        /* Posições dos pêndulos */
        float x1 = x0 + fio1*sin(fi1);
        float y1 = y0 + fio1*cos(fi1);
                
        float x2 = x1 + fio2*sin(fi2);
        float y2 = y1 + fio2*cos(fi2);
        
        /* Velocidades e Acelerações dos pêndulos */
        fi1_v += fi1_a/4;
        fi1_v += fi2_a/4;

        fi1 += fi1_v;
        fi2 += fi2_v;

        /* Fios dos pêndulos */
        line(buffer, x0, y0, x1, y1, makecol(255, 245, 200));
        line(buffer, x1, y1, x2, y2, makecol(255, 245, 200));

        /* Bolas dos pêndulos */
        circlefill(buffer, x1, y1, m1, makecol(0, 255, 255));
        circlefill(buffer, x2, y2, m2, makecol(255, 0, 150));

        draw_sprite(screen, buffer, 0, 0);
        rest(50); /* controla a velocidade de execução */
        clear(buffer); /* Limpando o buffer */
    }
    destroy_bitmap(buffer);

    return EXIT_SUCCESS;
}
END_OF_MAIN()

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

