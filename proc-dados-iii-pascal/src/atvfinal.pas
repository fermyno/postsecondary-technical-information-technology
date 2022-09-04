Program atvfinal;
(* Curso: Tec. Informatica - Colegio Santa Familia *)
(* Atividade: trabalho final *)

Uses CRT;

(* Declaracao de variaveis *)
var
   f      : Text;
   menu   : Integer;
   x      : Integer;
   s      : string[60];
   s_name : string[60];
   s_addr : string[60];
   s_code : string[60];

(* Procedimento que exibe o menu de opcoes *)
procedure opcoes;
begin
   (* personaliza cor do fundo *)
   textbackground(9);
   (* limpa a tela *)
   clrscr;
   writeln('Curso   : Tecnico em Informatica');
   writeln('Escola  : Colegio Santa Familia');
   writeln('Aluno   : Fermyno Gutierrez');
   writeln('Objetivo: Manipular registros no');
   writeln('          arquivo C:\alunos.txt');
   writeln('');
   writeln('');
   writeln('+-------------------------------+');  
   writeln('| Gestao de Estudantes          |');  
   writeln('+-------------------------------+');  
   writeln('|                               |');
   writeln('| Opcoes: [1] Inserir Registros |');
   writeln('|         [2] Exibir Registros  |');
   writeln('|         [9] Sair do Programa  |');
   writeln('|                               |');
   writeln('+-------------------------------+');  
end;

(* Procedimento que exibe uma barra de progresso ao iniciar o programa *)
(* finalidade puramente estetica *)
procedure splash;
begin
  (* limpa a tela *)
  clrscr;
  (* loop para criar o fundo da barra de carregamento *)
  for x:=30 to 50 do
  begin
     gotoXY(x,12);
     write(chr(176));
  end;
  (* exibe mensagem na tela em determinada coordenada *)
  gotoXY(31,10);
  write('Gestao de Estudantes');
  (* exibe mensagem na tela em determinada coordenada *)
  gotoXY(31,14);
  write('   Carregando ...');
  (* loop para mostrar a barra de carregamento *)
  for x:=30 to 50 do
  begin
     gotoXY(x,12);
     write(chr(178));
     delay(50);
  end;
end;

(* Procedimento que realiza a escrita de dados no arquivo *)
Procedure file_write;
Begin
   (* le os dados do aluno no teclado *)
   writeln('Insira os dados do aluno');   
   write('Nome     : ');   
   readln(s_name);
   write('Endereco : ');   
   readln(s_addr);
   write('Codigo   : ');   
   readln(s_code);
   (* manipula o arquivo *)
   Assign(f,'c:\alunos.txt');
   Append(f);
   (* salva os dados do aluno do arquivo *)
   writeln(f, s_name,';',s_addr,';',s_code,';');
   Close(f);
   writeln('Digite qualquer tecla para continuar...');
   readkey;
End;

(* Procedimento que realiza a leitura de dados no arquivo *)
Procedure file_read;
Begin
   (* le os dados do aluno do arquivo *)
   Assign(f,'c:\alunos.txt');
   reset(f);
   (* loop de leitura do arquivo *)
   while not eof(f) do
   begin
     readln(f,s);
	 (* escreve na tela o conteudo do arquivo *)
     writeln(s);
   end;
   readln;
   close(f);
   writeln('Digite qualquer tecla para continuar...');
   {readkey;}
End;

(* rotina principal do programa *)
begin
   (* exibe tela de carregamento do programa *)
   splash;
   (* exibe opcoes do menu *)
   opcoes;
   readln(menu);
   (* execucao do programa *)
   while menu<>9 do
   begin
      Case menu of
         1: file_write; { escreve dados no arquivo }
         2: file_read;  { le dados do arquivo }
      end;
      (* exibe opcoes do menu *)
      opcoes;
      readln(menu);	  
   end;

end.
