/***************************************************************************
 *   aloc_din_vet.c                           Version 20200426.224443      *
 *                                                                         *
 *   Alocacao Dinamica de Memoria para Vetores                             *
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
 * $gcc aloc_din_vet.c -o aloc_din_vet.x -Wall -Wextra -g -O0
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* ---------------------------------------------------------------------- */
/* Função para alocar a memória para um vetor */

int* alocaVetor(int tamanho);

/* ---------------------------------------------------------------------- */
/* Esta programa aloca memória, de forma dinâmica, para guardar um vetor de 
 * tamanho qualquer;
 * 
 * Ele recebe o tamanho do vetor e seus respectivos elementos;
 *
 * Retorna EXIT_SUCCESS.
 */
/* ---------------------------------------------------------------------- */
/* Função Principal */

int main(void)
{
    /* Definindo variáveis */
    int *vetor, tamanho, cont;

    /* Mensagem de instrução */
    printf("\n--------------------------------------------------------\n");
    printf("\tAlocacao Dinamica de Memoria com Vetores ");
    printf("\n--------------------------------------------------------\n");

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    printf("\n");

    /* Ponteiro recebe o endereço de memória que foi alocado para o vetor */
    vetor = alocaVetor(tamanho);

    /* Alimentando o vetor com os valores */
    for(cont = 0; cont < tamanho; cont++)
    {
        printf("Entre com vetor[%d]: ", cont);
        scanf("%d", &vetor[cont]);
    }

    /* Imprimindo o vetor */
    printf("\n--------------------------------------------------------\n");
    printf("\nImprimindo vetor...\n\n");
    
    for(cont = 0; cont < tamanho; cont++)
    {
        printf("vetor[%d] = %d\n", cont, vetor[cont]);
    }
    printf("\n--------------------------------------------------------\n");

    /* Limpando o vetor criado para liberar memória */
    free(vetor);

    /* Retorno da função main */
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Função para alocar a memória para um vetor */

int* alocaVetor(int tamanho)
{
    int *aux; /* Ponteiro auxiliar */
    
    /* Alocação dinâmica de memória */
    aux = (int*) malloc( tamanho * sizeof(int) ); /* forçando aux ser um
    ponteiro de inteiro, alocando memória suficiente para guardar o vetor */

    return aux; /* Retorna o ponteiro que aponta para a primeira posição
                   de memória do vetor alocado */
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

