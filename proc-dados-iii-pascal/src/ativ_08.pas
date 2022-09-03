Program ativ_08;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: ler dados e ordenar pelo nome (máximo 10 pessoas) *)

Uses CRT;

    Label fim;

    (* armazena dados em estrutura do tipo record *)
    Type Pessoas = Record
                      Nome    : String[30];
                      Idade   : Integer;
                      Sexo    : Char;
                      Altura  : Real;
                   End;

    (* array de pessoas *)
    Var p     : array[1..10] of Pessoas;
        i,x,y : Integer;
        s     : Pessoas;
    Begin
       ClrScr;
	   (* mensagem de cabecalho *)
       writeln('Curso: Tecnico em Informatica - Colegio Santa Familia.');
	   writeln('Atividade: ler dados e ordenar pelo nome (máximo 10 pessoas).');
	   writeln('');
	   writeln('');
	   
	   (* execucao do programa *)	   
       i:=0;
       Repeat
	      (* loop de leitura de dados do teclado *)
          i:=i+1;
          Write('Nome (<0> para sair): ');
          Readln(p[i].Nome);
          if p[i].Nome='0' then goto fim;
          Write('Idade: ');
          Readln(p[i].Idade);
          Write('Sexo: ');
          Readln(p[i].Sexo);
          Write('Altura: ');
          Readln(p[i].Altura);
          Writeln;
    fim:
	   (* ordenacao dos dados *)
       Until ((p[i].Nome='0') or (i=20));
       If i<20 then i:=i-1;
       For x:=1 to i-1 do
          For y:=x+1 to i do
             If ((p[x].nome) >= (p[y].nome))
                then begin
                        s:=p[x];
                        p[x]:=p[y];
                        p[y]:=s;
                     End;
       ClrScr;
	   (* mostra resultados na tela *)
       Writeln('Dados ordenados:');
       Writeln('');
       Writeln('NOME':30,'IDADE':6,'SEXO':5,'ALTURA':8);
       For x:=1 to i do
          Writeln(p[x].nome:30,p[x].idade:6,p[x].sexo:5,p[x].altura:8:2);
    End.