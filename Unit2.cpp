//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStructForm *StructForm;
const int AppBarHeight = 75;
//---------------------------------------------------------------------------
__fastcall TStructForm::TStructForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::AppBarResize()
{
  AppBar->SetBounds(0, AppBar->Parent->Height - AppBarHeight,
    AppBar->Parent->Width, AppBarHeight);
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::AppBarShow(int mode)
{
  if (mode == -1)
    mode = AppBar->Visible ? 0 : 1;
  if (mode == 0)
    AppBar->Visible = False;
  else {
    AppBar->Visible = True;
    AppBar->BringToFront();
  }
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::CloseButtonClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::Action1Execute(TObject *Sender)
{
	AppBarShow(-1);
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::FormResize(TObject *Sender)
{
	AppBarResize();
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	AppBarShow( (Key == VK_ESCAPE) ? -1 : 0 );
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled)
{
	AppBarShow( 0 );
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::Image1Click(TObject *Sender)
{
	for(unsigned __int64 i = 0; i < StringGrid1->ColCount; i++)
	for(unsigned __int64 j = 0; j < StringGrid1->RowCount; j++)
	StringGrid1->Cells[i][j] = "";
	StringGrid1->RowCount=1;
	Hide();


}
//---------------------------------------------------------------------------
void __fastcall TStructForm::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0]="Номер ярусу";
	StringGrid1->Cells[1][0]="Кількість операцій";
}
//---------------------------------------------------------------------------
void __fastcall TStructForm::FormHide(TObject *Sender)
{
  for(unsigned __int64 i = 0; i < StringGrid1->ColCount; i++)
	for(unsigned __int64 j = 0; j < StringGrid1->RowCount; j++)
	StringGrid1->Cells[i][j] = "";
	StringGrid1->RowCount=1;
}
//---------------------------------------------------------------------------

