/*
   ------------------------------------------------------------------
   Curso:   Tecnico em Informatica
   Colegio: Santa Familia
   Exercicios de Estudo
   ------------------------------------------------------------------
   Bibliografia Sugerida:
   + Introducao a Linguagem C
     Centro de Computacao
     Universidade Estadual de Campinas
   + Como Programar em C
     Paul J. Deitel e Harvey M. Deitel
   ------------------------------------------------------------------
   Enunciado:
   Escreva um programa que compare dois arquivos texto e imprime a
   primeira linha onde eles se diferem.
   ------------------------------------------------------------------
*/

/* Codigo: */

/* inclusao de biblioteca */
#include <stdio.h>
#include <string.h>
/* definicao de constantes */
#define LINHA_LEN 80

/* programa principal */
void main()
{
  /* declaracao de variaveis */
  char narq1[30], narq2[30], linha1[LINHA_LEN], linha2[LINHA_LEN];
  FILE *arq1, *arq2;
  int count, sai;

  printf("\n\n### Programa que compara dois arquivos texto ###\n\n");
  /* le nome do primeiro arquivo com os dados de entrada */
  printf("\nPrimeiro arquivo (Ex.: ativ14a.txt): ");
  gets(narq1);
  /* Tenta abrir o arquivo: */
  if ((arq1 = fopen(narq1, "r")) == NULL)
  {
    printf("\n Erro: Nao e possivel abrir %s!!", narq1);
    /* encerra programa ao encontrar erro na abertura do arquivo */
    exit(1);
  }

  /* le nome do segundo arquivo com os dados de entrada */
  printf("\nSegundo arquivo (Ex.: ativ14b.txt): ");
  gets(narq2);
  /* Tenta abrir o arquivo: */
  if ((arq2 = fopen(narq2, "r")) == NULL) /*20*/
  {
    printf("\n Erro: Nao e possivel abrir %s!!", narq2);
    /* encerra programa ao encontrar erro na abertura do arquivo */
    exit(1);
  }

  /* inicia a comparacao de conteudo entre os arquivos */
  printf("\nComparando o conteudo de %s e %s:\n", narq1, narq2);
  /* zera variaveis */
  count = 0;
  sai = 0;

  /* loop de comparacao */
  while (!sai)
  {
    /* testa se linha dos arquivos sao iguais */
    if (feof(arq1) || feof(arq2))
      break;
    count++;
    fgets(linha1, LINHA_LEN - 1, arq1);
    fgets(linha2, LINHA_LEN - 1, arq2);
    /* funcao strcmp retorna zero se valores sao iguais */
    if (strcmp(linha1, linha2) == 0)
      /* exibe linhas iguais */
      printf("Linha %d ok!\n", count);
    else
    {
      /* exibe linhas diferentes */
      printf("Linhas diferentes!! Linha %d:\n%s\n%s\n", count, linha1, linha2);
      sai = 1;
    }
  }
  /* fecha arquivos */
  fclose(arq1);
  fclose(arq2);
}
