program ativ_06;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: converte letra para minusculas *)

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
   write('Digite uma letra maiúscula: ');
   (* le letra digitada no teclado *)
   readln(Maiuscula);
   (* converte letra *)
   Minuscula := Chr(Ord(Maiuscula) + 32);
   (* escreve resultado na tela *)
   writeln('LowCase(' , Maiuscula , ') = ', Minuscula);
end.