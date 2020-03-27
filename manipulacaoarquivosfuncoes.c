/***************************************************************************
 *   manipulacaoarquivosfuncoes.c             Version 20200327.003847      *
 *                                                                         *
 *   Estudando Manipulacao de Arquivos com Funcoes                         *
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
 * $gcc manipulacaoarquivosfuncoes.c -o manipulacaoarquivosfuncoes.x -Wall
 *  -Wextra -g -O0 
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* ---------------------------------------------------------------------- */
/* prototypes */

/* Função AbreArquivo*/
FILE *AbreArquivo(char modo, char caminho[50]);

/* Função FecharArquivo*/
void FecharArquivo(FILE *arquivo);

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
    char vetor[6];
    int valor;
    FILE *arquivo; /* Ponteiro apontando para o arquivo */
    
    /* Funcao de abertura de um arquivo:
     *      - fopen("caminho do arquivo", "modo de abertura"); 
     *          * wt --> gravação em arquivo de texto --> "write-txt" -->
     *                   Nesse modo se o arquivo não existir, ele é criado.
     *                   Mas sempre apaga o arquivo anterior e cria um novo
     *                   em branco.
     *          * rt --> Leitura de arquivo de texto --> "read-txt"
     */
    arquivo = AbreArquivo('g',"/home/ldl/discreta/rascunhos/teste/teste.txt");
    
    
    /* Funcao para gravar uma string num arquivo:
     *      - fprintf(ponteiro, "string a gravar"); 
     */
    fprintf(arquivo, "Teste 123");  /* Grava no arquivo.  */

    FecharArquivo(arquivo); /* Fecha o arquivo */

    arquivo = AbreArquivo('l',"/home/ldl/discreta/rascunhos/teste/teste.txt");
    
    
    fscanf(arquivo, "%s %d", &vetor, &valor);  /* receber as informações */
    printf("\n\n%s %d\n\n", vetor, valor);

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Função AbreArquivo*/
FILE *AbreArquivo(char modo, char caminho[50]) /* o retorno da função é um
                                                  ponteiro FILE */
{
    FILE *arquivo;
    switch(modo)
    {
        case 'g':       /* Modo gravação */
            arquivo = fopen(caminho, "wt");
            break;
        case 'l':       /* Modo leitura */
            arquivo = fopen(caminho, "rt");
            break;
        case 'a':       /* Modo append */
            arquivo = fopen(caminho, "a");
            break;
    }
    if(arquivo == NULL) /* Caso de erro na abertura do arquivo */
    {
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(0);        /* encerra a execução do programa */
    }
    return arquivo;     /* caso esteja tudo certinho */
}


/* Função FecharArquivo*/
void FecharArquivo(FILE *arquivo)
{
    fclose(arquivo);
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

