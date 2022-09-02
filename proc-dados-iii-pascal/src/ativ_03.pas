Program ativ_03;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: exercicio de escrita em disco *)

Uses CRT;

Var
   F : Text;
   i : Integer;
   z : Char;
   MENSAGEM : string[60];
   
Begin
   ClrScr;
   (* mensagem de cabecalho *)
   writeln('Curso: Tecnico em Informatica - Colegio Santa Familia.');
   writeln('Atividade: exercicio de escrita em disco, escreve no arquivo C:\EXEMPLO.TXT.');
   writeln('');
   writeln('');
	   
   (* execucao do programa *)
   (* le mensagem do teclado *)
   write('Digite a mensagem a ser gravada: ');   
   readln(MENSAGEM);	
   (* arquivo de dados *)
   Assign(F,'C:\EXEMPLO.TXT');
   Rewrite(F);
   (* mensagem de encerramento *)
   writeln(F, MENSAGEM);
   close(F);	
   writeln('Dados escritos com sucesso. Digite qualquer tecla para sair.');
   readkey;

End.
