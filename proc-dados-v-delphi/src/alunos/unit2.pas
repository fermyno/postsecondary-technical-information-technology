unit Unit2;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls;

type

  { TForm2 }

  TForm2 = class(TForm)
    Button1: TButton;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  Form2: TForm2;

implementation

{$R *.lfm}

{ TForm2 }

procedure TForm2.Button1Click(Sender: TObject);
begin
   { fecha o formulario Ajuda > Sobre }
  Form2.Close;
end;

procedure TForm2.FormCreate(Sender: TObject);
begin
   { define o texto do formulario de Ajuda > Sobre }
   Form2.Label1.Caption := 'Autor: Fermyno Gutierrez'#10'Controle de Alunos';

end;

end.

