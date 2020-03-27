/***************************************************************************
 *   agendateste.c                            Version 20200327.030804      *
 *                                                                         *
 *   Agenda teste utilizando manipulação de arquivos                       *
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
 * $gcc agendateste.c -o agendateste.x -Wall -Wextra -g -O0 
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* ---------------------------------------------------------------------- */
/* prototypes */

/* Função AbreArquivo */
FILE *AbreArquivo(char modo, char caminho[100]);

/* Função FecharArquivo */
void FecharArquivo(FILE *arquivo);

/* Função Cadastra */
void Cadastra(char nome[30], int telefone);

/* Função Listar */
void Listar();

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
    int opcao;
    char nome[30];
    int telefone;

    do
    {
        system("cls");  /* Limpa a tela para não ficar muito grande */

        printf("\n\n\n\t\tBem Vindo ao Programa AGENDA TESTE\n");
        printf("\nMENU");
        printf("\n 1 - Cadastrar Nome e Telefone");
        printf("\n 2 - Listar todos os Nomes e Telefones");
        printf("\n 3 - Sair");

        printf("\n\nDigite uma opcao: ");

        scanf("%d", &opcao);
        system("cls");  /* Limpa a tela para não ficar muito grande */

        switch(opcao)
        {
            case 1:
                printf("\nDigite o nome: ");
                setbuf(stdin, NULL);    /* Limpar o buff do teclado */
                gets(nome);
                printf("\nDigite o telefone: ");
                scanf("%d", &telefone);

                Cadastra(nome, telefone);               
                system("pause");
                break;

            case 2:
                Listar();
                system("pause");
                break;

            case 3:
                printf("\n\nFinalizando...\n\n");
                system("pause");
                exit(0);
                break;

            default:
                printf("\n\nOpcao Invalida! Tente Novamente!\n\n");
                system("pause");

        }
    }while(opcao != 3);


    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Função AbreArquivo*/
FILE *AbreArquivo(char modo, char caminho[100]) /* o retorno da função é um ponteiro FILE */
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


/* Função Cadastra */
void Cadastra(char nome[30], int telefone)
{
    FILE *arquivo;

    arquivo = AbreArquivo('a', "/home/ldl/discreta/rascunhos/teste/agenda.txt");
    fprintf(arquivo, "%s %d\n", nome, telefone);
    FecharArquivo(arquivo);
}


/* Função Listar */
void Listar()
{
    FILE *arquivo;
    char nome[30];
    int telefone;

    arquivo = AbreArquivo('l', "/home/ldl/discreta/rascunhos/teste/agenda.txt");

    while(!feof(arquivo))   /* Enquanto não for o fim do arquivo */
    {
        fscanf(arquivo, "%s %d ", &nome, &telefone);
        printf("Nome: %s - Telefone: %d\n", nome, telefone);
    }
    FecharArquivo(arquivo);
}
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

