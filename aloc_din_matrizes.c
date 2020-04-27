/***************************************************************************
 *   aloc_din_matrizes.c                      Version 20200427.000927      *
 *                                                                         *
 *   Alocacao Dinamica de Memoria para Matrizes                            *
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
 * $gcc aloc_din_matrizes.c -o aloc_din_matrizes.x -Wall -Wextra -g -O0
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* ---------------------------------------------------------------------- */
/* Este programa aloca a memória, de forma dinâmica, para uma matriz de
 * tamanho definido pelo usuário;
 * 
 * Recebe inteiros - linhas, colunas e elementos da matriz;
 *
 * Retorna EXIT_SUCCESS;
 */
/* ---------------------------------------------------------------------- */
int main(void)
{
    /* Definindo variáveis */
    int linhas, colunas, i, j;
    int **matriz; /* Ponteiro de ponteiro (linhas e colunas) */

    /* Imprimindo instruções para o usuário */
    printf("\n---------------------------------------------------------\n");
    printf("\tAlocacao Dinamica de Memoria para Matrizes...");
    printf("\n---------------------------------------------------------\n\n");

    /* Lendo o tamanho da matriz pelo usuário */
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    
    /* Alocando memoria para as linhas */
    matriz = (int **) malloc(linhas * sizeof(int *));

    /* Alocando memoria para as colunas */
    for(i = 0; i < linhas; i++)
    {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
    }

    /* Preenchendo a matriz */
    printf("\n---------------------------------------------------------\n");
    printf("Informe os valores da matriz...\n\n");

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("Digite matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    /* imprimindo a matriz */
    printf("\n---------------------------------------------------------\n");
    printf("Imprimindo a Matriz...\n\n");

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nPrograma executado com sucesso!!!");
    printf("\n---------------------------------------------------------\n\n");

    /* Liberando a memória alocada */
    free(matriz);

    /* Retorno da função main */
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

