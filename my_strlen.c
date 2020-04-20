/***************************************************************************
 *   my_strlen.c                              Version 20200420.174826      *
 *                                                                         *
 *   FUNCAO PARA CONTAR O TAMANHO DE UMA STRING SEM USAR <string.h>        *
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
 *
 * $gcc my_strlen.c -o my_strlen.x -Wall -Wextra -g -O0 
 *
 */
/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* ---------------------------------------------------------------------- */
/* prototypes */

int my_strlen(char *str);

/* ---------------------------------------------------------------------- */
/* Esta função conta quantas letras possui uma string
 * 
 * Ela recebe uma string (vetor de caracteres)
 *
 * E retorna o número (inteiro) de letras que a string possui
 */
/* ---------------------------------------------------------------------- */

int main(void)
{
    char *nome[100];    /* Declarando a string (como um ponteiro) */
    int resultado;

    printf("Digite um nome: ");
    gets(nome);         /* Lendo a string fornecida pelo usuário */

    resultado = my_strlen(nome);
    printf("O nome digitado possui %d letras\n\n", resultado);

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Função my_strlen */

int my_strlen(char *str)
{
    int tam = 0;        /* Iniciando o tamanho da string */

    while(*str != '\0') /* Percorrendo a string para contagem de letras */
    {                   /* Contagem para quando acha o último caractere(\0) */
        str++;
        tam++;
    }
    return tam;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

