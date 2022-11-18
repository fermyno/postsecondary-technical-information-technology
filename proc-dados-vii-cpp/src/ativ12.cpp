/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que percorre uma matriz e imprime seus valores.
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
#include <iomanip>

using namespace std;

// declaracao de constantes
const int linhas = 3;
const int colunas = 6;

int main()
{
    cout << "Programa que mostra na tela o conteudo de uma matriz.\nMatriz:\n"
         << endl;

    // Matriz de tres linhas e seis colunas
    int A[linhas][colunas] = {
        {65, 18, 9, 57, 11, 299},
        {32, 39, 14, 21, 6, 98},
        {32, 38, 49, 77, 62, 19},
    };
    // Percorrendo o "vetor de vetores", ou
    // seja, cada linha
    for (int i = 0; i < linhas; i++)
    {
        // Percorrendo o "sub-vetor", ou
        // seja, cada coluna para a linha i
        for (int j = 0; j < colunas; j++)
        {
            // Imprimimos cada elemento
            cout << setw(2)
                 << A[i][j] << ' ';
        }
        // Pule uma linha apos imprimir a
        // linha da matriz
        cout << endl;
    }
}
