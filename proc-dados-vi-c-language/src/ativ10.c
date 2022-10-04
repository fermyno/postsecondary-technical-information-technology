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
   Escreva um programa que faca uso dos parametros argc e argv.
   O programa devera receber a partir da linha de comando o dia, mes
   e ano correntes, e imprimir a data em formato apropriado.
   Atencao:
   Este programa deve ser executado no console de comandos, de modo a
   permitir a passagem dos argumentos.
   Ex.: ativ10.exe 30 10 22
   ------------------------------------------------------------------
*/

/* Codigo: */

/* inclusao de bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* programa principal
   argv[0] é o nome do programa executavel
   argv[1] é o primeiro parâmetro
   e assim sucessivamente ...
*/
void main(int argc, char *argv[])
{
  /* declaracao de variaveis */
  int mes;
  char nomemes[12][15] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio",
                          "Junho", "Julho", "Agosto", "Setembro", "Outubro",
                          "Novembro", "Dezembro"};

  printf("\n\n### Programa que utiliza os parametros argc e argv (dia/mes/ano) ###\n\n");
  /* carrega valor dos parametros */
  mes = atoi(argv[2]);
  /* testa validade dos valores passados por parametros */
  if (mes < 1 || mes > 12)
    printf("Erro!");
  else
    /* apresenta resultado na tela */
    printf("\n%s de %s de 19%s", argv[1], nomemes[mes - 1], argv[3]);
}
