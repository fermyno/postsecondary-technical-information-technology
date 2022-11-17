/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que mostra um vetor char de 10 posicoes na tela.
 *
 * Instrucoes:
 * Para criar o arquivo de objeto, execute o comando:
 *   g++ -c file.cpp -o file.o
 *   g++ file.o -o file
 *
 * Bibliografia complementar:
 *   Introducao a Programacao em C++
 *   Lucas S. Vieira
 *
 */

#include <iostream>
using namespace std;

#define TAMANHO_DO_VETOR 6

int main()
{

    char meuVetor[10];
    meuVetor[0] = 'M';
    meuVetor[1] = 'e';
    meuVetor[2] = 'u';
    meuVetor[3] = ' ';
    meuVetor[4] = 'V';
    meuVetor[5] = 'e';
    meuVetor[6] = 't';
    meuVetor[7] = 'o';
    meuVetor[8] = 'r';
    meuVetor[9] = '!';

    std::cout << "Exibindo elementos do vetor: \n" << std::endl;

    std::cout << "Elemento [0]: " << meuVetor[0] << std::endl
              << "Elemento [1]: " << meuVetor[1] << std::endl
              << "Elemento [2]: " << meuVetor[2] << std::endl
              << "Elemento [3]: " << meuVetor[3] << std::endl
              << "Elemento [4]: " << meuVetor[4] << std::endl
              << "Elemento [5]: " << meuVetor[5] << std::endl
              << "Elemento [6]: " << meuVetor[6] << std::endl
              << "Elemento [7]: " << meuVetor[7] << std::endl
              << "Elemento [8]: " << meuVetor[8] << std::endl
              << "Elemento [9]: " << meuVetor[9] << std::endl;

    return 0;

}