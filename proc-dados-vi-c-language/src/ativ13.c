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
   Escreva um programa que leia um arquivo do tipo base de dados em
   <.txt>, retire e apresente informacoes importantes na tela.
   Voce pode criar o arquivo no EDIT do DOS, ou no NOTEPAD do
   Windows, ou no PICO, no UNIX.
   O arquivo pode ser do tipo:
   Nome:     Joao da Silva             Telefone: +55 00 000-0000
   Endereco: Rua do Joao, 168
   $
   Nome:     Maria da Silva            Telefone: +55 99 999-9999
   Endereco: Rua da Vila, 093
   $
   Obs.: O simbolo <$> (dolar) entre os dados serve para informar que
   acabou uma sequencia de dados, e pode ser usado para restabelecer
   o sincronismo, caso o programa se perca em algum ponto.
   Voce pode usar um flag para encerrar, mas recomenda-se a
   utilizacao do feof() por questoes de elegancia.
   ------------------------------------------------------------------
*/

/* Codigo: */

/* inclusao de biblioteca */
#include <stdio.h>

/* definicao de constantes */
#define NOME_TAM 26
#define ENDER_TAM 30
#define TELE_TAM 20

/* programa principal */
void main()
{
  /* declaraca de variaveis */
  FILE *arq;
  char nome[NOME_TAM + 1], ender[ENDER_TAM + 1], tele[TELE_TAM + 1], arq_nome[30];
  char c;

  printf("\n\n### Programa que le um arquivo <Ex.: ativ13.txt> ###\n\n");
  /* le nome do arquivo com os dados de entrada */
  printf("\n\nArquivo de entrada: ");
  gets(arq_nome);

  /* testa abertura do arquivo */
  if ((arq = fopen(arq_nome, "r")) == NULL)
  {
    printf("\nErro ao abrir o arquivo %s!", arq_nome);
    /* encerra programa ao encontrar erro na abertura do arquivo */
    exit(1);
  }

  /* inicia impressao de dados do arquivo */
  printf("\n\nImprimindo dados do arquivo: %s\n", arq_nome);
  /* loop de leitura do arquivo de dados */
  while (!feof(arq))
  {
    /* zera vaviavel */
    c = 0;
    /* realiza Leitura sincronizada dos dados */
    /* ignora a palavra: 'Nome:' */
    fscanf(arq, "%s", nome); 
    fgets(nome, NOME_TAM, arq);
    /* ignora a palavra: 'Telefone:' */
    fscanf(arq, "%s", tele); 
    fgets(tele, TELE_TAM, arq);
    /* ignora a palavra: 'Endereco:' */
    fscanf(arq, "\n%s", ender); 
    fgets(ender, ENDER_TAM, arq);
    /* apresenta os dados na tela */
    printf("\nNome: %s\nEndereco: %sTelefone: %s", nome, ender, tele);

    /* Caso alguma parte se perca, e o ponteiro do arquivo fique 
       parado em alguma parte do registro, esta rotina realizara
       a sincronizacao dos dados, refazendo a leitura, com o preco
       de se perder um registro. 
    */
    while (c != '$')
    {
      c = getc(arq);
      if (feof(arq))
        break;
    }
  }
  fclose(arq);
}

/*
OBS: listagem do arquivo usado para o teste: 
Nome:     Jose Manuel Silva         
Telefone: +51 55 555-5555
Endereco: Rua do Lar, 1050
$
Nome:     Mariana Silva So        
Telefone: +52 66 666-6666
Endereco: Av. do Forte, 48
$
Nome:     Fermyno Gutierrez       
Telefone: +53 77 777-7777
Endereco: Rua do Barco, s/n
*/