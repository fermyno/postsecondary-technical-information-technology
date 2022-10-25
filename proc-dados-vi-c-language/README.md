# Disciplina: Processamento de Dados VI - Linguagem C

> **Warning**
> 
> [DEPRECATED]  
> A tecnologia em uso neste repositório encontra-se obsoleta em muitos aspectos, e foram desenvolvidos no âmbito acadêmico. Os arquivos estão mantidos neste repositório apenas para fins de demonstração e documentação. 

## Atividades

Atividades desenvolvidas no âmbito da disciplina **Processamento de Dados IV - Linguagem C** do curso Técnico em Informática do Instituto São Francisco - Santa Família.

* **Atividade 1**:  
  **Programa**: [ativ01.c](src/ativ01.c)  
  **Objetivo**: Escreva um programa que receba duas strings e retorne o valor.  
  
* **Atividade 2**:  
  **Programa**: [ativ02.c](src/ativ02.c)  
  **Objetivo**: Escreva um programa que leia uma string do teclado (usando o gets()) e remova todos os caracteres 'a' encontrados. Na tela, apresente a quantidades de caracteres retirados da string.

* **Atividade 3**:  
  **Programa**: [ativ03.c](src/ativ03.c)  
  **Objetivo**: Escreva um programa utilizando o comando switch que leia uma string (utilize gets) e substitua todos os espaços e tabulacoes ('\t') por caracteres de nova linha. O loop acaba quando encontrar o caracter de final de linha '\0'.

* **Atividade 4**:  
  **Programa**: [ativ04.c](src/ativ04.c)  
  **Objetivo**: Faça um programa que inverta a sequencia de caracteres de uma string. Use o comando for para varrer toda a string até o seu final. Lembre-se de que a string sempre termina com o caracter '\0'.

* **Atividade 5**:  
  **Programa**: [ativ05.c](src/ativ05.c)  
  **Objetivo**: Faça um programa de conversão de base numérica. A partir da opção escolhida, o programa deverá pedir o número na base escolhida, ler e apresentar o número na base desejada. Em seguida, o programa deve perguntar ao usuário se ele deseja retornar ao menu principal ou finalizar o programa. O programa deverá apresentar uma tela de entrada com as seguintes opções:  
  ```
   < Conversao de base >
   1: decimal para hexadecimal
   2: hexadecimal para decimal
   3: decimal para octal
   4: octal para decimal
   5: Encerra
   Informe sua opcao:
  ```
* **Atividade 6**:  
  **Programa**: [ativ06.c](src/ativ06.c)  
  **Objetivo**: Faça um programa usando enumeração. Crie uma enumeração de meses do ano, e utilize para indexar um vetor de nomes dos meses. Desta forma, apresente os nomes dos meses do ano na tela.  
 
* **Atividade 7**:  
  **Programa**: [ativ07.c](src/ativ07.c)  
  **Objetivo**: Escreva um programa que leia nomes pelo teclado e imprima na tela, utilizando as funções puts e gets.  
  
* **Atividade 8**:  
  **Programa**: [ativ08.c](src/ativ08.c)  
  **Objetivo**: Faça um programa que leia uma string do teclado. Em seguida, verifique se a string corresponde a um número. Se sim, calcular o valor que a string representa (inclusive quando for negativo) e apresentá-lo na tela como float. Se não, o número apresentado deverá ser zero. Observações: é obrigatória a utilização de ponteiros para percorrer a string.  
  
* **Atividade 9**:  
  **Programa**: [ativ09.c](src/ativ09.c)  
  **Objetivo**: Escreva um programa que leia uma matriz pelo teclado e apresente os resultados na tela. A função deve ter o seguinte formato: lermatriz(int *mat)  

* **Atividade 10**:  
  **Programa**: [ativ10.c](src/ativ10.c)  
  **Objetivo**: Escreva um programa que faça uso dos parametros argc e argv. O programa deverá receber a partir da linha de comando o dia, mês e ano correntes, e imprimir a data em formato apropriado. Atenção: o programa deve ser executado no console de comandos, de modo a permitir a passagem dos argumentos.  
  Exemplo: **ativ10.exe 30 10 22**  

* **Atividade 11**:  
  **Programa**: [ativ11.c](src/ativ11.c)  
  **Objetivo**: Faça um programa que utilize os argumentos argv e argc. O programa deverá receber dois numeros e apresentar a soma deles. Para isso, é preciso uma função que transforme string em inteiro, pois o tipo de argv é char. Atenção: o programa deve ser executado no console de comandos, de modo a permitir a passagem dos argumentos.  
  Exemplo: **ativ11.exe 14 18**
  
* **Atividade 12**:  
  **Programa**: [ativ12.c](src/ativ12.c)  
  **Objetivo**: Um problema tradicional de recursividade consiste em encontrar o termo da sequência de Fibonacci. As séries de Fibonacci são de grande importância matemática. A lei básica define que, a partir do terceiro termo, todos os termos são a soma dos dois últimos. Faça um programa que encontre o termo da sequência de Fibonacci. A seguir são apresentados os primeiros termos da sequência.  
  ```
   F = {1, 1, 2, 3, 5, 8, 13, 21, 34...}
   O primeiro e o segundo termos são 1.
   O terceiro termo é 2 (1+1).
   O quarto termo é 3 (1+2).
   O próximo termo e 5 (3+2).
   E assim sucessivamente.
  ```  

* **Atividade 13**:  
  **Programa**: [ativ13.c](src/ativ13.c)  
  **Objetivo**: Escreva um programa que leia um arquivo do tipo base de dados em <ativ13.txt>, retire e apresente informações importantes na tela. Você pode criar o arquivo no EDIT (DOS), NOTEPAD (Windows), ou no PICO (UNIX e Linux).  
  O arquivo pode ser do tipo:  
  ```   
Nome:     Joao da Silva             Telefone: +55 00 000-0000
Endereco: Rua do Joao, 168
$
Nome:     Maria da Silva            Telefone: +55 99 999-9999
Endereco: Rua da Vila, 093
$
  ```   
