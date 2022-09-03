Program ativ_07;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: ler notas de alunos e listar notas menores que 6 *)

Uses CRT;
    Const
              No_de_alunos = 20;
    Type
              Classe = Array[1..No_de_alunos] Of Real;
    Var
              n : Integer;
              a : Classe;
    Begin
       ClrScr;
	   (* mensagem de cabecalho *)
       writeln('Curso: Tecnico em Informatica - Colegio Santa Familia.');
	   writeln('Atividade: ler notas de alunos e listar notas menores que 6.');
	   writeln('');
	   writeln('');
	   
	   (* execucao do programa *)	   
       For n:=1 to No_de_alunos Do
          Begin
             Write('Informe a nota do aluno numero ',n:2,'/',No_de_alunos,': ');
             Readln(a[n]);
          End;
       ClrScr;
	   (* lista nota dos alunos reprovados *)
       Writeln('Relacao de alunos reprovados com media menor que 6:');
       Writeln('');
       Writeln('Aluno -- Nota');
       For n:=1 to No_de_alunos Do
          If a[n]<6
             Then Writeln(n:2,a[n]:10:1);
    End.
	