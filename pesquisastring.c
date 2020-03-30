/***************************************************************************
 *   pesquisastring.c                         Version 20200330.184557      *
 *                                                                         *
 *   Pesquisa uma palavra dentro de uma frase usando string                *
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
 * $gcc pesquisastring.c -o pesquisastring.x -Wall -Wextra -g -O0
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <string.h> /* Strings functions definitions */
#include <stdbool.h>

/* ---------------------------------------------------------------------- */
/* prototypes */

/* Função testar */
bool testar(int teste[], int tam);

/* Função existe */
bool existe(char palavra[], char frase[]);


/* ---------------------------------------------------------------------- */
/* This function does ...
 * 
 * It receives as input ... 
 *
 * It returns ...
 */
/* ---------------------------------------------------------------------- */

int main(void)
{
    char frase[100];
    char palavra[100];

    printf("\n\nDigite uma frase: ");
    gets(frase);

    printf("\n\nDigite uma palavra: ");
    gets(palavra);

    if( existe(palavra, frase) )
    {
        printf("\n\nA palavra <%s> existe na frase!!\n\n", palavra);
    }
    else
    {
        printf("\n\nA palavra <%s> NAO existe na frase!!\n\n", palavra);
    }

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* add more functions here */

/* Função testar */
bool testar(int teste[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(teste[i] == 0)
        {
            return false;
        }
    }
    return true;
}

/* Função existe */
bool existe(char palavra[], char frase[])
{
    int teste[ strlen(palavra) ];
    int i, j, k, aux;

    if( strlen(palavra) > strlen(frase) )
    {
        return false;
    }

    if( strcmp(palavra, frase) == 0 )
    {
        return true;
    }

    for(i = 0; i <= strlen(frase) - strlen(palavra); i++)
    {
        if(frase[i] == palavra[0])
        {
            for(k = 0; k < strlen(palavra); k++)
                teste[k] = 0;

            aux = i;
            for(j = 0; j < strlen(palavra); j++)
            {
                if(palavra[j] == frase[aux])
                {
                    teste[j] = 1;
                    aux++;
                }
            }
            if( testar(teste, strlen(palavra)) )
            {
                return true;
            }
        }
    }
    return false;
}


/* ---------------------------------------------------------------------- */
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

