/*
   ----------------------------------------------------------------------------
   Curso:   Tecnico em Informatica
   Colegio: Santa Familia
   Aluno:   Fermyno Braga Gutierrez
   ----------------------------------------------------------------------------
   
   ATIVIDADE FINAL - ENUNCIADO
   ============================
   
   O Departamento de Recursos Humanos da Empresa XYZ enfrenta um problema com 
   o excessivo tempo gasto no processamento da folha de pagamentos.
   Atualmente, todo o cálculo dos salários é realizado de forma manual, 
   ocasionando erros de cálculos e demora na execucao do serviço.
   Você será o responsável pelo desenvolvimento de um programa que deverá 
   emitir um relatório com o cálculo do processamento de salários.

   Utilizando os conceitos abordados durante o curso, você deverá criar um 
   programa que faça a leitura de três arquivos diferentes 
   (funcionarios.txt, horas-extras.txt, e faltas.txt), e processar o 
   resultado final em um arquivo chamado calculo-de-salarios.txt.

   O programa deverá calcular o adicional por horas-extras usando como 
   parâmetro: valorHorasExtras = horasExtras * (salarioBase / 80)
   O programa deverá calcular o desconto por dias de faltas usando como 
   parâmetro: DescontoDeFaltas = salarioBase / 24
   O Salário Liquido deverá ser calculado respeitando a seguinte ordem: 
   Salario Liquido = Salário Bruto - imposto de renda - seguranca social
   Salario Bruto   = Salario Base + adicional horas-extras + adicional dependentes - faltas 

   O programa deverá fazer uso de estrutura para manipular os dados informados, 
   e deverá apresentar um código limpo e organizado.
   O arquivo de cálculo de salários (calculo-de-salarios.txt) deverá ter uma 
   largura máxima de 132 colunas, permitindo sua impressão nos equipamentos 
   da empresa.

   Os arquivos utilizados para a Atividade Final serão fornecidos pelo professor 
   e apresentam as seguintes características:

   <funcionarios.txt>
   Arquivo texto em formato de largura fixa com os seguintes campos:
   ==================================================================
   111111 2222222222222222222222222222222 3333333333 44
   ==================================================================
   1 int    matriculaFuncionario; 
   2 char   nomeFuncionario[30];
   3 float salarioBase;
   4 int    dependentes;

   <horas-extras.txt>
   Arquivo texto em formato de largura fixa com os seguintes campos:
   ==================================================================
   111111 222
   ==================================================================
   1 int    matriculaFuncionario;
   2 int    horasExtras;

   <faltas.txt>
   Arquivo texto em formato de largura fixa com os seguintes campos:
   ==================================================================
   111111 22
   ==================================================================
   1 int    matriculaFuncionario;
   2 int    diasDeFaltas;

   <calculo-de-salarios.txt>
   Arquivo texto em formato de largura fixa com a seguintes aparencia:
   ====================================================================================================================================

   ************************************************************************************************************************************
   ** EMPRESA XYZ ** CALCULO DE PROCESSAMENTO DE SALARIOS **                                                           ** 01/10/2005 **
   ************************************************************************************************************************************
   ** MATRIC FUNCIONARIO                    SAL.BASE   HS.EXTRAS  ADIC.DEP.  DESC.FALTA SAL.BRUTO  IMP.RENDA  SEG.SOCIAL SAL.LIQUIDO **
   ************************************************************************************************************************************
   ** 222222 333333333333333333333333333333 4444444444 5555555555 6666666666 7777777777 8888888888 9999999999 0000000000 1111111111  **
   ************************************************************************************************************************************
   
*/




#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// estruturas
typedef struct tFuncionarios
{
   char matriculaFuncionario[7];
   char nomeFuncionario[30];
   float salarioBase;
   int quantidadeDeHorasExtras;
   float adicionalHorasExtras;
   int quantidadeDeDependentes;
   float adicionalDependentes;
   int quantidadeDeFaltas;
   float descontoPorFaltas;
   float salarioBruto;
   float percentualImpostoDeRenda;
   float descontoImpostoDeRenda;
   float percentualSegurancaSocial;
   float descontoSegurancaSocial;
   float salarioLiquido;
} tFuncionarios;

// inicializacao da matriz
struct tFuncionarios funcionarios[100];

// variaveis globais
char dataDeCalculo[12];

/*
   ************************************************
   FUNCOES DO PROGRAMA
   ************************************************
*/

/*
   FUNCAO QUE INICIALIZA A ESTRUTURA COM VALORES ZERADOS
*/
void limpaConteudoDaEstrutura(void)
{
   int i;
   // percorre toda a estrutura
   for (i = 1; i <= 100; ++i)
   {
      // zera valores
      strcpy(funcionarios[i].matriculaFuncionario, "");
      strcpy(funcionarios[i].nomeFuncionario, "");
      funcionarios[i].salarioBase = 0.00;
      funcionarios[i].quantidadeDeHorasExtras = 0;
      funcionarios[i].adicionalHorasExtras = 0.00;
      funcionarios[i].quantidadeDeDependentes = 0;
      funcionarios[i].adicionalDependentes = 0.00;
      funcionarios[i].quantidadeDeFaltas = 0;
      funcionarios[i].descontoPorFaltas = 0.00;
      funcionarios[i].salarioBruto = 0.00;
      funcionarios[i].percentualImpostoDeRenda = 0.00;
      funcionarios[i].descontoImpostoDeRenda = 0.00;
      funcionarios[i].percentualSegurancaSocial = 0.00;
      funcionarios[i].descontoSegurancaSocial = 0.00;
      funcionarios[i].salarioLiquido = 0.00;
   }
}

/*
   FUNCAO QUE ENCERRA DO PROGRAMA
*/
void telaEncerramento(void)
{
   // mensagem de encerramento
   printf("\n");
   printf("\n  PROGRAMA FINALIZADO COM SUCESSO ");
   printf("\n  TECLE < ENTER > PARA SAIR");
   printf("\n ");

   // aguarda o pressionamento de alguma tecla
   getchar();
}

/*
   FUNCAO QUE CONVERTE STRING EM DOUBLE
*/
float converteStringEmFloat(char *stringNaoConvertida)
{
   // declaracao de variaveis
   float stringEmFloat;

   // converte string em float
   stringEmFloat = atof(stringNaoConvertida);

   return stringEmFloat;
}

/*
   FUNCAO QUE SUBSTITUI VIRGULAS POR PONTOS EM UMA STRING
*/
char *substituiVirgulaPorPonto(char *stringComVirgula)
{
   // variaveis locais
   int tamanhoDaString;
   int i;
   char *stringComPonto = NULL;

   // aloca memoria para nova string com o tamanho da string original
   tamanhoDaString = strlen(stringComVirgula);
   stringComPonto = (char *)malloc((sizeof(char) * tamanhoDaString) + 1);

   // percorre todos os caracteres da string
   for (i = 0; i <= tamanhoDaString; ++i)
   {
      if (stringComVirgula[i] == ',')
      {
         // quando caracter igual a virgula, substitui por ponto
         stringComPonto[i] = '.';
      }
      else
      {
         // quando o caracter nao eh vigula, copia caracter para nova string
         stringComPonto[i] = stringComVirgula[i];
      }
   }

   // retorna string com ponto no lugar de virgual
   return stringComPonto;
}

/*
   FUNCAO QUE REMOVE ESPACOS EM BRANCO NO INICIO E FIM DA STRING
*/
char *trimString(char *stringNaoFormatada)
{
   // declaracao de variaveis
   int i;

   // percorre a string da esquerda para a direita
   while (isspace(*stringNaoFormatada))
   {
      // remove espacos em branco do lado esquerdo da string
      stringNaoFormatada++;
   }
   // percorre a string da direita para a esquerda
   for (i = strlen(stringNaoFormatada) - 1; (isspace(stringNaoFormatada[i])); i--)
      ;
   {
      // remove espacos em branco do lado direito da string
      stringNaoFormatada[i + 1] = '\0';
   }

   // printf (">%s<\n", stringNaoFormatada);
   return stringNaoFormatada;
}

/*
   FUNCAO QUE RECEBE LINHA DO ARQUIVO DE FUNCIONARIOS
   E PREPARA PARA A INSERCAO DOS DADOS NA ESTRUTURA
*/
void preparaLinhaDoArquivoDeFuncionarios(int posicao, char *linhaDoArquivo)
{
   // variaveis locais
   char linha[70];
   // campos do arquivo
   char campoMatricula[6];
   char campoNome[30];
   char campoSalario[11];
   char campoDependentes[3];
   float campoSalarioFloat;

   // carrega na variavel linha o conteudo recebido
   strcpy(linha, linhaDoArquivo);
   // separa os campos de acordo com a posicao na linha
   // le dados da matricula
   memcpy(campoMatricula, &linha, 6);
   campoMatricula[6] = '\0';
   strcpy(campoMatricula, trimString(campoMatricula));
   strcpy(funcionarios[posicao].matriculaFuncionario, campoMatricula);
   // le dados do nome
   memcpy(campoNome, &linha[7], 30);
   campoNome[30] = '\0';
   strcpy(campoNome, trimString(campoNome));
   strcpy(funcionarios[posicao].nomeFuncionario, campoNome);
   // le dados do salario
   memcpy(campoSalario, &linha[38], 10);
   campoSalario[10] = '\0';
   strcpy(campoSalario, trimString(campoSalario));
   strcpy(campoSalario, substituiVirgulaPorPonto(campoSalario));
   campoSalarioFloat = converteStringEmFloat(campoSalario);
   funcionarios[posicao].salarioBase = campoSalarioFloat;
   // le dados dos dependentes
   memcpy(campoDependentes, &linha[49], 2);
   campoDependentes[2] = '\0';
   strcpy(campoDependentes, trimString(campoDependentes));
   funcionarios[posicao].quantidadeDeDependentes = atoi(campoDependentes);
}

/*
   FUNCAO QUE RECEBE LINHA DO ARQUIVO DE FALTAS
   E PREPARA PARA A INSERCAO DOS DADOS NA ESTRUTURA
*/
void preparaLinhaDoArquivoDeFaltas(char *linhaDoArquivo)
{
   // variaveis locais
   int i;
   int retorno;
   char linha[20];
   // campos do arquivo
   char campoMatricula[6];
   char campoFaltas[2];

   // carrega na variavel linha o conteudo recebido
   strcpy(linha, linhaDoArquivo);
   linha[9] = '\0';
   // separa os campos de acordo com a posicao na linha
   // le dados da matricula
   memcpy(campoMatricula, &linha, 6);
   campoMatricula[6] = '\0';
   strcpy(campoMatricula, trimString(campoMatricula));
   // le dados das faltas
   memcpy(campoFaltas, &linha[7], 2);

   // realiza loop no arquivo de funcionarios para localizar registro com a mesma matricula
   for (i = 1; i <= 100; ++i)
   {
      retorno = strcmp(campoMatricula, funcionarios[i].matriculaFuncionario);
      if ((retorno == 0) && (strlen(campoMatricula) > 0))
      {
         campoFaltas[2] = '\0';
         funcionarios[i].quantidadeDeFaltas = atoi(campoFaltas);
      }
   }
}

/*
   FUNCAO QUE RECEBE LINHA DO ARQUIVO DE HORAS EXTRAS
   E PREPARA PARA A INSERCAO DOS DADOS NA ESTRUTURA
*/
void preparaLinhaDoArquivoDeHorasExtras(char *linhaDoArquivo)
{
   // variaveis locais
   int i;
   int retorno;
   char linha[20];
   // campos do arquivo
   char campoMatricula[6];
   char campoHorasExtras[3];

   // carrega na variavel linha o conteudo recebido
   strcpy(linha, linhaDoArquivo);
   linha[10] = '\0';
   // separa os campos de acordo com a posicao na linha
   // le dados da matricula
   memcpy(campoMatricula, &linha, 6);
   campoMatricula[6] = '\0';
   strcpy(campoMatricula, trimString(campoMatricula));
   // le dados das campoHorasExtras
   memcpy(campoHorasExtras, &linha[7], 3);

   // realiza loop no arquivo de funcionarios para localizar registro com a mesma matricula
   for (i = 1; i <= 100; ++i)
   {
      retorno = strcmp(campoMatricula, funcionarios[i].matriculaFuncionario);
      if ((retorno == 0) && (strlen(campoMatricula) > 0))
      {
         campoHorasExtras[3] = '\0';
         funcionarios[i].quantidadeDeHorasExtras = atoi(campoHorasExtras);
      }
   }
}

/*
   FUNCAO QUE LE ARQUIVO DE FUNCIONARIOS
*/
void carregaArquivoDeFuncionarios(void)
{
   // variaveis locais
   FILE *fp;
   char arquivo[20] = "funcionarios.txt";
   char linha[70];
   int i;

   // abertura do arquivo
   fp = fopen(arquivo, "r");

   if (fp == NULL)
   {
      perror("Erro na abertura do arquivo de Funcionarios! ");
      // return 1;
   }
   else
   {
      // zera contador de registro de funcionarios
      i = 0;
      // loop de leitura do arquivo
      while (fgets(linha, 70, fp))
      {
         i++;
         // chama funcao que prepara a insercao dos dados na estrutura
         preparaLinhaDoArquivoDeFuncionarios(i, linha);
      }
      // fecha o arquivo
      fclose(fp);
   }
}

/*
   FUNCAO QUE LE ARQUIVO DE FALTAS
*/
void carregaArquivoDeFaltas(void)
{
   // variaveis locais
   FILE *fp;
   char arquivo[20] = "faltas.txt";
   char linha[20];

   // abertura do arquivo
   fp = fopen(arquivo, "r");

   if (fp == NULL)
   {
      perror("Erro na abertura do arquivo de Faltas! ");
      // return 1;
   }
   else
   {
      // loop de leitura do arquivo
      while (fgets(linha, 20, fp))
      {
         // chama funcao que prepara a insercao dos dados na estrutura
         preparaLinhaDoArquivoDeFaltas(linha);
      }
      // fecha o arquivo
      fclose(fp);
   }
}

/*
   FUNCAO QUE LE ARQUIVO DE HORAS EXTRAS
*/
void carregaArquivoDeHorasExtras(void)
{
   // variaveis locais
   FILE *fp;
   char arquivo[20] = "horas-extras.txt";
   char linha[20];

   // abertura do arquivo
   fp = fopen(arquivo, "r");

   if (fp == NULL)
   {
      perror("Erro na abertura do arquivo de Horas Extras! ");
      // return 1;
   }
   else
   {
      // loop de leitura do arquivo
      while (fgets(linha, 20, fp))
      {
         // chama funcao que prepara a insercao dos dados na estrutura
         preparaLinhaDoArquivoDeHorasExtras(linha);
      }
      // fecha o arquivo
      fclose(fp);
   }
}

/*
   FUNCAO QUE RETORNA O VALOR DO ADICIONAL POR DEPENDENTE
*/
float retornaAdicionalPorDependente(int escalao)
{
   // variaveis locais
   // adicional por dependentes
   float adicionalDependentes = 98.13;

   // o valor eh fixo, independente do salario e escalao
   return adicionalDependentes;
}

/*
   FUNCAO QUE RETORNA O ESCALAO DE ACORDO COM O SALARIO
*/
int retornaEscalao(float salarioBase)
{
   // variaveis locais
   int escalao = 0;
   // escaloes do Imposto de Renda
   float valorIREscalao1inicio = 0.00;
   float valorIREscalao1Fim = 1002.00;
   float valorIREscalao2inicio = 1002.01;
   float valorIREscalao2Fim = 2080.56;
   float valorIREscalao3inicio = 2080.57;
   float valorIREscalao3Fim = 4032.44;
   float valorIREscalao4inicio = 4032.45;
   float valorIREscalao4Fim = 6725.58;
   float valorIREscalao5inicio = 6725.59;

   // verifica o escalao do Imposto de Renda
   if (salarioBase <= valorIREscalao1Fim)
   {
      escalao = 1;
   }
   if ((salarioBase >= valorIREscalao2inicio) && (salarioBase <= valorIREscalao2Fim))
   {
      escalao = 2;
   }
   if ((salarioBase >= valorIREscalao3inicio) && (salarioBase <= valorIREscalao3Fim))
   {
      escalao = 3;
   }
   if ((salarioBase >= valorIREscalao4inicio) && (salarioBase <= valorIREscalao4Fim))
   {
      escalao = 4;
   }
   if (salarioBase >= valorIREscalao5inicio)
   {
      escalao = 5;
   }

   // retorna valor do escalao, de acordo com o salario
   return escalao;
}

/*
   FUNCAO QUE RETORNA O DESCONTO DO IMPOSTO DE RENDA ACORDO COM O ESCALAO
*/
float retornaDescontoImpostoDeRenda(int escalao)
{
   // variaveis locais
   float descontoImpostoDeRenda = 0.00;
   // descontos do Imposto de Renda de acordo com o Escalao
   float descontoImpostoDeRendaEscalao1 = 2.0;
   float descontoImpostoDeRendaEscalao2 = 8.0;
   float descontoImpostoDeRendaEscalao3 = 11.0;
   float descontoImpostoDeRendaEscalao4 = 15.0;
   float descontoImpostoDeRendaEscalao5 = 24.0;

   // verifica o desconto do Imposto de Renda
   if (escalao == 1)
   {
      descontoImpostoDeRenda = descontoImpostoDeRendaEscalao1;
   }
   if (escalao == 2)
   {
      descontoImpostoDeRenda = descontoImpostoDeRendaEscalao2;
   }
   if (escalao == 3)
   {
      descontoImpostoDeRenda = descontoImpostoDeRendaEscalao3;
   }
   if (escalao == 4)
   {
      descontoImpostoDeRenda = descontoImpostoDeRendaEscalao4;
   }
   if (escalao == 5)
   {
      descontoImpostoDeRenda = descontoImpostoDeRendaEscalao5;
   }

   // retorna valor do desconto
   return descontoImpostoDeRenda;
}

/*
   FUNCAO QUE RETORNA O DESCONTO DA SEGURANCA SOCIAL ACORDO COM O ESCALAO
*/
float retornaDescontoSegurancaSocial(int escalao)
{
   // variaveis locais
   float descontoSegurancaSocial = 0.00;
   // descontos da Segurancao Social de acordo com o Escalao
   float descontoSegurancaSocialEscalao1 = 3.0;
   float descontoSegurancaSocialEscalao2 = 9.0;
   float descontoSegurancaSocialEscalao3 = 12.00;
   float descontoSegurancaSocialEscalao4 = 17.00;
   float descontoSegurancaSocialEscalao5 = 19.00;

   // verifica o desconto do Imposto de Renda
   if (escalao == 1)
   {
      descontoSegurancaSocial = descontoSegurancaSocialEscalao1;
   }
   if (escalao == 2)
   {
      descontoSegurancaSocial = descontoSegurancaSocialEscalao2;
   }
   if (escalao == 3)
   {
      descontoSegurancaSocial = descontoSegurancaSocialEscalao3;
   }
   if (escalao == 4)
   {
      descontoSegurancaSocial = descontoSegurancaSocialEscalao4;
   }
   if (escalao == 5)
   {
      descontoSegurancaSocial = descontoSegurancaSocialEscalao5;
   }

   // retorna valor do desconto
   return descontoSegurancaSocial;
}

/*
   FUNCAO QUE LE TODA A ESTRUTURA E ATUALIZA OS SALARIOS
*/
void atualizaSalarios(void)
{
   // declaracao de variaveis
   int i;
   int escalao;

   // le todo o conteudo da estrutura
   for (i = 1; i <= 100; ++i)
   {
      if (strlen(funcionarios[i].matriculaFuncionario) > 0)
      {
         // mostra apenas registros validos
         // calcula o Adicional de Horas Extras
         funcionarios[i].adicionalHorasExtras = funcionarios[i].quantidadeDeHorasExtras * (funcionarios[i].salarioBase / 80);
         // calcula o Adicional de Dependentes
         funcionarios[i].adicionalDependentes = funcionarios[i].quantidadeDeDependentes * (retornaAdicionalPorDependente(0));
         // calcula o desconto por faltas
         funcionarios[i].descontoPorFaltas = (funcionarios[i].salarioBase / 24) * funcionarios[i].quantidadeDeFaltas;
         // calcula o Salario Bruto
         funcionarios[i].salarioBruto = funcionarios[i].salarioBase + funcionarios[i].adicionalHorasExtras + funcionarios[i].adicionalDependentes - funcionarios[i].descontoPorFaltas;
         // verifica o escalao do salario
         escalao = retornaEscalao(funcionarios[i].salarioBruto);
         // calcula o percentual do imposto de renda
         funcionarios[i].percentualImpostoDeRenda = retornaDescontoImpostoDeRenda(escalao);
         // calcula o desconto do imposto de renda
         funcionarios[i].descontoImpostoDeRenda = funcionarios[i].salarioBruto / 100 * funcionarios[i].percentualImpostoDeRenda;
         // calcula o percentual da seguranca social
         funcionarios[i].percentualSegurancaSocial = retornaDescontoSegurancaSocial(escalao);
         // calcula o desconto da seguranca social
         funcionarios[i].descontoSegurancaSocial = funcionarios[i].salarioBruto / 100 * funcionarios[i].percentualSegurancaSocial;
         // calcula o salario liquido
         funcionarios[i].salarioLiquido = funcionarios[i].salarioBruto - funcionarios[i].descontoImpostoDeRenda - funcionarios[i].descontoSegurancaSocial;
         // fim do calculo dos salarios
      }
   }
}

/*
   	FUNCAO QUE LIMPA A TELA
*/
void limpaATela(void)
{
   // limpa a tela
   #ifdef LINUX
      // comando para linux
      system("clear");
   #elif defined WIN32
      // comando para windows
      system("cls");
   #endif    
}

/*
   	FUNCAO QUE ACRESCENTA ESPACOS EM BRANCO NO NOME
*/
const char * espacoEmBrancoNome(char texto[30], int tamanhoTotal)
{
    // declaracao de variaveis
    int i;
	char * espacos;
    
    // loop para acrescentar os espacos em branco necessarios
    // de acordo com o tamanho do campo
    
    for (i = 0; i < (tamanhoTotal - strlen(texto)); ++i)
    {
    	espacos[i] = ' ';
	}
	espacos[i] = '\0';
	// retorna string com a quantidade de espacos em branco pretendida
	return (espacos);
}

/*
   	FUNCAO QUE ACRESCENTA ESPACOS EM BRANCO NOS NUMEROS
*/
char* espacoEmBrancoNumero(float valor)
{
    // declaracao de variaveis
    char * espacos;
    espacos = malloc(sizeof(char)*100);
	strcpy(espacos,"");
	    
    // loop para acrescentar os espacos em branco necessarios
    // de acordo com o tamanho do campo
    if (valor < 1000000) { strcat(espacos, " "); }
    if (valor < 100000)  { strcat(espacos, " "); }
    if (valor < 10000)   { strcat(espacos, " "); }
    if (valor < 1000)    { strcat(espacos, " "); }
    if (valor < 100)     { strcat(espacos, " "); }    
    if (valor < 10)      { strcat(espacos, " "); }    

	// retorna string com a quantidade de espacos em branco pretendida
	return espacos;
}

/*
   FUNCAO QUE GRAVA O CONTEUDO NO ARQUIVO EM DISCO
*/
void gravaSalariosNoArquivo(void)
{
      // declaracao de variaveis
      int i;
      int funcionariosEncontrados = 0;
      FILE *fp;
      char salarioBase[10] = "";
	  
	  // estrutura de data do sistema
  	  struct tm *dataHoraSistema;
      time_t seconds;
      time(&seconds);
      dataHoraSistema = localtime(&seconds);
	
	  // abre arquivo para escrita
      fp = fopen("calculo-de-salarios.txt", "w");

      // escreve dados no arquivo

      // grava cabecalho do relatorio
      fprintf(fp, "************************************************************************************************************************************\n");
      fprintf(fp, "** EMPRESA XYZ ** CALCULO DE PROCESSAMENTO DE SALARIOS **                                                     ** ");
      fprintf(fp, "%d/%d/%d %d:%d **\n", dataHoraSistema->tm_mday, dataHoraSistema->tm_mon + 1, dataHoraSistema->tm_year + 1900,dataHoraSistema->tm_hour,dataHoraSistema->tm_min);
      fprintf(fp, "************************************************************************************************************************************\n");
      fprintf(fp, "** MATRIC FUNCIONARIO                    SAL.BASE   HS.EXTRAS  ADIC.DEP.  DESC.FALTA SAL.BRUTO  IMP.RENDA  SEG.SOCIAL SAL.LIQUIDO **\n");
      fprintf(fp, "************************************************************************************************************************************\n");
      
      // percorre toda a estrutura com dados dos funcionarios e escreve no arqui
      for (i = 1; i <= 100; ++i)
      {
         if (strlen(funcionarios[i].matriculaFuncionario) > 0)
         {
            // mostra apenas registros validos
			fprintf(fp, "** ");
			// matricula
			fprintf(fp, "%s ", funcionarios[i].matriculaFuncionario);
            // nome
			fprintf(fp, "%s ", funcionarios[i].nomeFuncionario);
            fprintf(fp, "%s", espacoEmBrancoNome(funcionarios[i].nomeFuncionario, 30));
            // salario base
            fprintf(fp, "%s", espacoEmBrancoNumero(funcionarios[i].salarioBase));
            fprintf(fp, "%.2f ", funcionarios[i].salarioBase);
            // adicional por horas-extras
            fprintf(fp, "%s", espacoEmBrancoNumero(funcionarios[i].adicionalHorasExtras));
            fprintf(fp, "%.2f ", funcionarios[i].adicionalHorasExtras);
            // adicional por dependentes
            fprintf(fp, "%s", espacoEmBrancoNumero(funcionarios[i].adicionalDependentes));
            fprintf(fp, "%.2f ", funcionarios[i].adicionalDependentes);
            // desconto por faltas
            fprintf(fp, "%s", espacoEmBrancoNumero(funcionarios[i].descontoPorFaltas));
			fprintf(fp, "%.2f ", funcionarios[i].descontoPorFaltas);
			// salario bruto
			fprintf(fp, "%s", espacoEmBrancoNumero(funcionarios[i].salarioBruto));
            fprintf(fp, "%.2f ", funcionarios[i].salarioBruto);
            // desconto do imposto de renda
            fprintf(fp, "%s", espacoEmBrancoNumero(funcionarios[i].descontoImpostoDeRenda));
			fprintf(fp, "%.2f ", funcionarios[i].descontoImpostoDeRenda);
            // desconto da seguranca social
            fprintf(fp, "%s", espacoEmBrancoNumero(funcionarios[i].descontoSegurancaSocial));
			fprintf(fp, "%.2f ", funcionarios[i].descontoSegurancaSocial);
            // salario liquido
            fprintf(fp, "%s", espacoEmBrancoNumero(funcionarios[i].salarioLiquido));
			fprintf(fp, "%.2f ", funcionarios[i].salarioLiquido);
			// finaliza linha
			fprintf(fp, " **\n");
			// atualiza numero de funcionarios encontrados na estrutura
			funcionariosEncontrados++;
         }
      }

      // ultima linha
	  fprintf(fp, "************************************************************************************************************************************\n");
	  fprintf(fp, "   %d FUNCIONARIOS ENCONTRADOS.\n", funcionariosEncontrados);

      // fecha arquivo
      fclose(fp);

}

/*
   FUNCAO UTILIZADA APENAS PARA TESTES E DEBUG DO PROGRAMA
*/
void estruturaDEBUG(void)
{
   int i;
   for (i = 1; i <= 100; ++i)
   {
      if (strlen(funcionarios[i].matriculaFuncionario) > 0)
      {
         // mostra apenas registros validos
         printf("============================================================ \n");
         printf("   MATRICULA: %s \n", funcionarios[i].matriculaFuncionario);
         printf("   NOME:      %s \n", funcionarios[i].nomeFuncionario);
         printf("   SAL. BASE: %.2f \n", funcionarios[i].salarioBase);
         printf("   HS.EXTRAS: %d \n", funcionarios[i].quantidadeDeHorasExtras);
         printf("   ADIC.H.EX: %.2f \n", funcionarios[i].adicionalHorasExtras);
         printf("   DEPENDENT: %d \n", funcionarios[i].quantidadeDeDependentes);
         printf("   ADIC.DEP.: %.2f \n", funcionarios[i].adicionalDependentes);
         printf("   FALTAS   : %d \n", funcionarios[i].quantidadeDeFaltas);
         printf("   DESC.FALT: %.2f \n", funcionarios[i].descontoPorFaltas);
         printf("   SAL.BRUTO: %.2f \n", funcionarios[i].salarioBruto);
         printf("   PERC.I.R.: %.2f \n", funcionarios[i].percentualImpostoDeRenda);
         printf("   DESC.I.R.: %.2f \n", funcionarios[i].descontoImpostoDeRenda);
         printf("   PERC.SSOC: %.2f \n", funcionarios[i].percentualSegurancaSocial);
         printf("   DESC.SSOC: %.2f \n", funcionarios[i].descontoSegurancaSocial);
         printf("   SAL.LIQUI: %.2f \n", funcionarios[i].salarioLiquido);
      }
   }
}

/*
 * ----------------------------------------------------------------------------------
 *  PROGRAMA PRINCIPAL
 * ----------------------------------------------------------------------------------
 */

int main(void)
{
   
   // variaveis locais
   char opcaoDigitada[20];
   
   // define as cores do texto
   system("color 1F");
   limpaATela();

   printf("\n\n  PROGRAMA DE CALCULO DE SALARIOS \n\n");
   printf(" ============================================================================= \n\n\n");
   printf("  INICIANDO A EXECUCAO DO PROGRAMA  \n\n");
   printf("  * Preparando o programa para execucao                 [OK] \n");

   // limpa o conteudo da estrutura
   limpaConteudoDaEstrutura();
   printf("  * Iniciando execucao do programa                      [OK] \n");

   // carrega valores do arquivo funcionarios na estrutura
   carregaArquivoDeFuncionarios();
   printf("  * Carregando arquivo de funcionarios                  [OK] \n");

   // carrega valores do arquivo faltas na estrutura
   carregaArquivoDeFaltas();
   printf("  * Carregando arquivo de faltas                        [OK] \n");

   // carrega valores do arquivo horas extras na estrutura
   carregaArquivoDeHorasExtras();
   printf("  * Carregando arquivo de horas-extras                  [OK] \n");

   // atualiza salarios na estrutura
   atualizaSalarios();
   printf("  * Atualizando Salarios                                [OK] \n");

   // atualiza arquivo de calculo de salarios
   printf("  * Atualizando arquivo <calculo-de-salarios.txt>       [OK] \n");
   gravaSalariosNoArquivo();

   // finaliza o programa
   printf("  * Finalizando execucao do programa                    [OK] \n");
   telaEncerramento();   	   

   // fim do programa
   return 0;
}
