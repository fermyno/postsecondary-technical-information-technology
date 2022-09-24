unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, DB, dbf, Forms, Controls, Graphics, Dialogs, DBCtrls,
  DBGrids, StdCtrls, Menus, unit2;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    DataSource1: TDataSource;
    Dbf1: TDbf;
    DBGrid1: TDBGrid;
    DBNavigator1: TDBNavigator;
    Label1: TLabel;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    MenuItem5: TMenuItem;
    MenuItem6: TMenuItem;
    MenuItem7: TMenuItem;
    MenuItem8: TMenuItem;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure MenuItem2Click(Sender: TObject);
    procedure MenuItem4Click(Sender: TObject);
    procedure MenuItem5Click(Sender: TObject);
    procedure MenuItem6Click(Sender: TObject);
    procedure MenuItem8Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.FormCreate(Sender: TObject);
begin
   { codigo carregado na criacao do formulario princial }
   Form1.Label1.Caption := 'Controle de Alunos';
   { configuracao das base de dados }
   Form1.DBGrid1.DataSource := Form1.DataSource1;
   Form1.DBNavigator1.DataSource := Form1.DataSource1;
   { define Turma 1 como primeira turma a ser visualizada }
   Form1.Label1.Caption := 'Controle de Alunos - Turma 1';
   Form1.Dbf1.TableName := 'C:\alunos\alunosT1.dbf';
   Form1.Dbf1.FilePath := 'C:\alunos\';
   Form1.Dbf1.FilePathFull := 'C:\alunos\';
   Form1.Dbf1.StoreDefs := True;
   Form1.Dbf1.Active := True;
   Form1.DataSource1.DataSet := Form1.Dbf1;
end;

procedure TForm1.MenuItem2Click(Sender: TObject);
begin
   { sair do programa }
   Close;
end;

procedure TForm1.MenuItem4Click(Sender: TObject);
begin
   { atualiza o nome da turma no label }
   Form1.Label1.Caption := 'Controle de Alunos - Turma 1';
   { carrega os dados da tabela c:\alunos\alunosT1.dbf }
   Form1.Dbf1.Active := False;
   Form1.Dbf1.TableName := 'C:\alunos\alunosT1.dbf';
   Form1.Dbf1.Active := True;
end;

procedure TForm1.MenuItem5Click(Sender: TObject);
begin
   { atualiza o nome da turma no label }
   Form1.Label1.Caption := 'Controle de Alunos - Turma 2';
   { carrega os dados da tabela c:\alunos\alunosT2.dbf }
   Form1.Dbf1.Active := False;
   Form1.Dbf1.TableName := 'C:\alunos\alunosT2.dbf';
   Form1.Dbf1.Active := True;
end;

procedure TForm1.MenuItem6Click(Sender: TObject);
begin
   { atualiza o nome da turma no label }
   Form1.Label1.Caption := 'Controle de Alunos - Turma 3';
   { carrega os dados da tabela c:\alunos\alunosT3.dbf }
   Form1.Dbf1.Active := False;
   Form1.Dbf1.TableName := 'C:\alunos\alunosT3.dbf';
   Form1.Dbf1.Active := True;
end;

procedure TForm1.MenuItem8Click(Sender: TObject);
begin
   { abrir formulario Ajuda > Sobre }
   Form2.Show;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
   { sair do programa }
   Close;
end;

end.

