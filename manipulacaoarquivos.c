/***************************************************************************
 *   manipulacaoarquivos.c                    Version 20200327.003847      *
 *                                                                         *
 *   Estudando Manipulacao de Arquivos                                     *
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
 * $gcc manipulacaoarquivos.c -o manipulacaoarquivos.x -Wall -Wextra -g -O0 
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "manipulacaoarquivos.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */


/* ---------------------------------------------------------------------- */
/* prototypes */


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
    FILE *arquivo; /* Ponteiro apontando para o arquivo */
    
    /* Funcao de abertura de um arquivo:
     *      - fopen("caminho do arquivo", "modo de abertura"); 
     *          * wt --> gravação em arquivo de texto --> "write-txt" -->
     *                   Nesse modo se o arquivo não existir, ele é criado.
     *                   Mas sempre apaga o arquivo anterior e cria um novo
     *                   em branco.
     *          * rt --> Leitura de arquivo de texto --> "read-txt"
     */
    arquivo = fopen("/home/ldl/discreta/rascunhos/teste/teste.txt", "wt");
    
    if(arquivo == NULL) /* Caso algum erro o ponteiro aponta para NULL*/ 
    {
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(0); /* Encerra a execução do programa pelo sistema */
    }
    
    /* Funcao para gravar uma string num arquivo:
     *      - fprintf(ponteiro, "string a gravar"); 
     */
    fprintf(arquivo, "Ola, isso eh um teste!");  /* Grava no arquivo.  */

    fclose(arquivo); /* Fecha o arquivo */
    
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* add more functions here */

/* ---------------------------------------------------------------------- */
/* ---------------------------------------------------------------------- */
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

