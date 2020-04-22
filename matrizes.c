/***************************************************************************
 *   matrizes.c                               Version 20200422.002450      *
 *                                                                         *
 *   Definir, Acessar, Percorrer e Ler Matrizes                            *
 *   Copyright (C) 2020         by Leandro Dantas Lima                     *
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

/*
 * Instrucoes para compilar:
 * $gcc matrizes.c -o matrizes.x -Wall -Wextra -g -O0
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* ---------------------------------------------------------------------- */

int main(void)
{
    int i, j, tam_i, tam_j;
    
    printf("Quantas Linhas: ");
    scanf("%d", &tam_i);
    printf("Quantas Colunas: ");
    scanf("%d", &tam_j);

    int matriz[tam_i][tam_j]; /* definindo as propriedades da matriz */
    /* Lendo valores para a matriz */
    for(i = 0; i < tam_i; i++)
    {
        for(j = 0; j < tam_j; j++)
        {
            printf("Digite o valor do termo [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    /* Imprimindo a matriz */
    for(i = 0; i < tam_i; i++)
    {
        for(j = 0; j < tam_j; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    return EXIT_SUCCESS;
}


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

