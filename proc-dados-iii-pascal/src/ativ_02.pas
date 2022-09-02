Program ativ_02;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: colocar em ordem crescente nomes lidos do teclado *)

    Uses CRT;

    Const Num_max = 100;
    Type  faixa   = 1..Num_max;
          nomes   = String[30];
          arranjo = Array[faixa] of nomes;
    Var   i,j,n : Integer;
          a     : arranjo;
          z     : nomes;
    Begin
       ClrScr;
	   (* mensagem de cabecalho *)
       writeln('Curso: Tecnico em Informatica - Colegio Santa Familia.');
	   writeln('Atividade: colocar em ordem crescente nomes lidos do teclado');
	   writeln('');
	   writeln('');
	   
	   (* execucao do programa *)	   
       (* escreve no meio da linha *)
       Writeln;
	   Writeln; 
       n:=0;
       Writeln('Digite um nome ou <0> para terminar: ');
       Writeln;
	   Writeln;
	   (* loop de leitura dos nomes *)
       Repeat
          n:=n+1;
          Write('a[',n:3,'] = ');
          Readln(a[n]);
       Until (n=Num_max) Or (a[n]='0');
       (* elimina o ultimo registro porque o ultimo nome digitado = 0 *)
	   n:=n-1; 
       ClrScr;
       For i:=1 to n-1 Do
          For j:=i+1 to n Do
             If a[i] >= a[j]
                Then Begin
                        z:=a[i];
                        a[i]:=a[j];
                        a[j]:=z;
                     End;
	   (* escreve nomes em ordem crescente *)
	    Writeln('Nomes em ordem crescente: ');
       For i:=1 to n Do Writeln(a[i]:30);
    end.