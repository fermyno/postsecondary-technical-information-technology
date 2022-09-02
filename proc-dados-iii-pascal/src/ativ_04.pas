program ativ_04;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: calcular a área de um círculo *)

Uses CRT;
	
const
   PI = 3.141519265;
var
   Area, Comprimento, Raio : real;
begin
   ClrScr;
   (* mensagem de cabecalho *)
   writeln('Curso: Tecnico em Informatica - Colegio Santa Familia.');
   writeln('Atividade: calcular a área de um círculo.');
   writeln('');
   writeln('');
	   
   (* execucao do programa *)
   write('Digite o Raio do circulo: ');
   readln( Raio );
   (* calcula a area *)
   Area := PI * Raio * Raio;
   (* calcula o comprimento *)
   Comprimento := 2 * PI * Raio;
   (* mostra resultados na tela *)
   writeln('Area = ', Area);
   writeln('Comprimento da Circunferencia = ', Comprimento);
end.
