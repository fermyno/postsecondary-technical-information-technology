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
   Faca um programa de conversao de base numerica.
   O programa devera apresentar uma tela de entrada com as seguintes
   opcoes:
   < Conversao de base >
   1: decimal para hexadecimal
   2: hexadecimal para decimal
   3: decimal para octal
   4: octal para decimal
   5: Encerra
   Informe sua opcao:
   A partir da opcao escolhida, o programa devera pedir o numero na
   base escolhida, ler e apresentar o numero na base desejada.
   Em seguida, o programa deve perguntar ao usuario se ele deseja
   retornar ao menu principal ou finalizar o programa.
   ------------------------------------------------------------------
*/

/* Codigo: */

#include <stdio.h>
main()
{
  /* declaracao de variaveis */
  int entrada, opcao = 0;
  char opcao_c;

  printf("\n\n### Programa para conversao de base numerica ###\n\n");
  /* Loop do menu de opcoes */
  while (opcao != 5)
  {
    printf("\n\n");
    /* Imprime a tela de menu */
    printf("\n\n\t< Conversao de base >");
    printf("\n  1: decimal para hexadecimal");
    printf("\n  2: hexadecimal para decimal");
    printf("\n  3: decimal para octal");
    printf("\n  4: octal para decimal");
    printf("\n  5: Encerra");
    printf("\n\n\t\tOpcao: ");
    /* le a opcao digitada no teclado */
    scanf("%d", &opcao);

    /* somente sai do loop quando e digitado
       uma opcao valida: entre 1 e 4 */
    if ((opcao > 4) || (opcao < 1))
      continue;
    /* execucao da conversao */
    printf("\nEntre com o numero: ");
    switch (opcao)
    {
    case 1:
	  /* le numero digitado no teclado */
      scanf("%d", &entrada);
      /* escreve na tela o numero convertido */
      printf("Numero convertido: %x", entrada);
      break;
    case 2:
      /* le numero digitado no teclado */
      scanf("%x", &entrada);
      /* escreve na tela o numero convertido */
      printf("Numero convertido: %d", entrada);
      break;
    case 3:
      /* le numero digitado no teclado */
      scanf("%d", &entrada);
      /* escreve na tela o numero convertido */
      printf("Numero convertido: %o", entrada);
      break;
    case 4:
      /* le numero digitado no teclado */
      scanf("%o", &entrada);
      /* escreve na tela o numero convertido */
      printf("Numero convertido: %d", entrada);
      break;
    }
    do
    {
      printf("\n\n(F) Finaliza e (M) Retorna ao Menu. Opcao: ");
      fflush(NULL);
      /* confirmacao de saida do programa */
      scanf("%c", &opcao_c);
    } while ((opcao_c != 'F') && (opcao_c != 'f') && (opcao_c != 'm') && (opcao_c != 'M'));
    if ((opcao_c == 'F') || (opcao_c == 'f'))
      opcao = 5;
  }
}
