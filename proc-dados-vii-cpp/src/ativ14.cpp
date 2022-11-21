/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Aprimorando a atividade anterior, o aluno deve modificar o 
 *            programa de modo a permitir que o usuario introduza os dados 
 *            do aluno manualmente, via teclado em uma estrutura e mostre 
 *            os resultados na tela
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

// Inicializando um struct
struct Aluno
{
    int codMatricula;
    int dataNascimento;
    char nomeCompleto[80];
    char endereco[80];
    char cep[20];
};

int main()
{

    cout << "Informe os dados do aluno.\n";

    // carrega os dados do aluno utilizando std::cin.getline
    Aluno aluno_1;

    cout << "Cod. Matricula  : ";
    cin >> aluno_1.codMatricula;

    cout << "Nome Completo   : ";
    cin >> ws; // elimina espacos em branco
    cin.getline(aluno_1.nomeCompleto, 80);

    cout << "Data Nascimento : ";
    cin >> aluno_1.dataNascimento;

    cout << "Endereco        : ";
    cin >> ws;
    cin.getline(aluno_1.endereco, 80);

    cout << "Cod. Postal     : ";
    cin >> ws;
    cin.getline(aluno_1.cep, 20);

    cout << "\n\n";

    // dica para inserir os dados via codigo:
    // Aluno aluno_1 = {123, 19991221, "Fulano", "Rua Alguma, 0", "80000-000"};

    // mostra dados na tela
    cout << "Dados do aluno  #" << endl
         << "Cod. Matricula  : " << aluno_1.codMatricula << endl
         << "Nome Completo   : " << aluno_1.nomeCompleto << endl
         << "Data Nascimento : " << aluno_1.dataNascimento << endl
         << "Endereco        : " << aluno_1.endereco << endl
         << "Cod. Postal     : " << aluno_1.cep << endl;
}
