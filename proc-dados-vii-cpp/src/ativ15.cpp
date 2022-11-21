/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Aprimorando a atividade anterior, o aluno deve modificar o 
 *            programa de modo a permitir que o usuario introduza os dados 
 *            do aluno manualmente, via teclado, em uma estrutura, salve 
 *            esses dados no arquivo "ativ15.txt", e mostre os resultados 
 *            na tela, lendo os dados do arquivo salvo.
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
#include <fstream>
#include <string>
using namespace std;

// Inicializando a struct
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
    // declaracao de variaveis
    const char nomeArquivo[20] = "ativ15.txt";
    string linha;

    cout << "## Informe os dados do aluno ##\n";

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

    // grava os dados inseridos pelo usuario no arquivo "ativ15.txt"
    ofstream arquivoGravar(nomeArquivo);
    // testa se arquivo pode ser manipulado
    if (arquivoGravar.is_open())
    {
        // grava dados no arquivo
        arquivoGravar << "Dados do aluno  #\n";
        arquivoGravar << "Cod. Matricula  : " << aluno_1.codMatricula << endl;
        arquivoGravar << "Nome Completo   : " << aluno_1.nomeCompleto << endl;
        arquivoGravar << "Data Nascimento : " << aluno_1.dataNascimento << endl;
        arquivoGravar << "Endereco        : " << aluno_1.endereco << endl;
        arquivoGravar << "Cod. Postal     : " << aluno_1.cep << endl;
        // fecha arquivo
        arquivoGravar.close();
    }
    else
        cout << "Nao foi possivel abrir o arquivo para gravacao!\n";

    // testa se arquivo pode ser aberto
    ifstream arquivoLer(nomeArquivo);
    if (arquivoLer.is_open())
    {
        // le todas as linhas do arquivo
        while (getline(arquivoLer, linha))
        {
            // mostra linha na tela
            cout << linha << '\n';
        }
        // fecha arquivo
        arquivoLer.close();
    }
    else
        cout << "Nao foi possivel abrir o arquivo para leitura!\n";
}
