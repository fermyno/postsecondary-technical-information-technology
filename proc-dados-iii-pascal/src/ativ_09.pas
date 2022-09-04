Program ativ_09;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: exemplo de uso de funcoes *)

   Uses CRT;
   (* variáveis globais *)
   Var x,y : Real;
   
   (* Soma é uma função que depende de dois parâmetros reais e devolve um valor real *)   
   Function Soma(a,b:real):real;     
   Begin
      Soma:=a+b;
   End;
   
   Begin
      ClrScr;
	  (* mensagem de cabecalho *)
      writeln('Curso: Tecnico em Informatica - Colegio Santa Familia.');
	  writeln('Atividade: exemplo de uso de funcoes que efetua a soma de dois numeros.');
	  writeln('');
	  writeln('');
	   
	  (* execucao do programa *)	  
      Write('Informe o primeiro numero: ');
      Readln(x);
      Write('Informe o segundo numero: ');
      Readln(y);
      Writeln;
	  (* mostra resultado na tela *)
      Writeln('Valor da soma: ',Soma(x,y):10:2);
   End.
   