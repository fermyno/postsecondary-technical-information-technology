program ativ_05;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: converte letra para maiusculas *)

Uses CRT;

var 
   Maiuscula, Minuscula : char;
begin
   ClrScr;
   (* mensagem de cabecalho *)
   writeln('Curso: Tecnico em Informatica - Colegio Santa Familia.');
   writeln('Atividade: colocar em ordem decrescente 3 números lidos do teclado.');
   writeln('');
   writeln('');
	   
   (* execucao do programa *)
   write('Digite uma letra minúscula: ');
   (* le letra digitada no teclado *)
   readln(Minuscula);
   (* converte letra *)
   Maiuscula := Chr(Ord(Minuscula) - 32);
   (* escreve resultado na tela *)
   writeln('UpCase(' , Minuscula , ') = ', Maiuscula);
end.
