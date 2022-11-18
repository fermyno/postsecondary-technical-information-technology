/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que conta a quantidade de vogais em uma palavra.
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

int main()
{

    char texto[60];

    cout << "Programa que conta a quantidade de vogais em uma palavra.\n";
    cout << "Digite uma palavra: ";

    cin.getline(texto, 60);

    int num_vogais = 0;

    for (int i = 0; i < strlen(texto); i++)
    {
        char caractere = tolower(texto[i]);

        switch (caractere)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            num_vogais++;
            break;
        default:
            break;
        }
    }

    cout << "Palavra: " << texto << endl;
    cout << "Numero de vogais: " << num_vogais << endl;
}