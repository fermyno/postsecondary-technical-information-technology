Program ativ_01;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: colocar em ordem decrescente 3 números lidos do teclado *)

    Uses CRT;
    Label Inicio;
    Var x,y,z : Integer;
        tecla : Char;
    Begin
       Inicio:
       ClrScr;
	   (* mensagem de cabecalho *)
       writeln('Curso: Tecnico em Informatica - Colegio Santa Familia.');
	   writeln('Atividade: colocar em ordem decrescente 3 números lidos do teclado.');
	   writeln('');
	   writeln('');
	   
	   (* execucao do programa *)
       Write('Digite o primeiro numero: ');
	   (* le numero introduzido pelo teclado *)
       Readln(x);
       Write('Digite o segundo numero: ');
	   (* le numero introduzido pelo teclado *)
       Readln(y);
       Write('Digite o terceiro numero: ');
	   (* le numero introduzido pelo teclado *)
       Readln(z);

	   (* quebras de linhas *)
       Writeln;
       Writeln;
	   
	   (* ordenacao dos numeros *)
	   Write('Numeros ordenados decrescentemente: ');
       If (x>=y)
          Then If (x>=z)
             Then If (y>=z)
                Then Writeln(x,' ',y,' ',z)
                Else Writeln(x,' ',z,' ',y)
             Else Writeln(z,' ',x,' ',y)
          Else If (y>=z)
          Then If (x>=z)
             Then Writeln(y,' ',x,' ',z)
             Else Writeln(y,' ',z,' ',x)
          Else Writeln(z,' ',y,' ',x);
       
	   Writeln;
       
	   Write('Tecle S para executar novamente ou <ENTER> para Sair: ');
       Tecla:=Readkey;
       
	   If ((Tecla = 'S') OR (Tecla = 's')) Then Goto Inicio;
	   
    End.
	