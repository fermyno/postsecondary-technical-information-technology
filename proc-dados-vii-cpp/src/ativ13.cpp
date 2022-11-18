/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que inicializa uma estrutura e mostra seus dados na tela.
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
    char cep[80];
};

int main()
{

    // inicializa estrutura Aluno carregando dados de um elemento
    Aluno aluno_1 = {123, 19991231, "Fulano de Tal", "Rua Que Sobe e Desce, 10", "90000-000"};

    // exibe conteudo da estrutura Aluno na tela
    cout << "A Estrutura Aluno foi inicializada com os seguintes dados:\n"
         << endl;

    cout << "Dados do aluno  #" << endl
         << "Cod. Matricula  : " << aluno_1.codMatricula << endl
         << "Nome Completo   : " << aluno_1.nomeCompleto << endl
         << "Data Nascimento : " << aluno_1.dataNascimento << endl
         << "Endereco        : " << aluno_1.endereco << endl
         << "Cod. Postal     : " << aluno_1.cep << endl;
}
