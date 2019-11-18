//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "itemDetail.h"
#include "groupedItems.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDetailForm *DetailForm;
const int AppBarHeight = 75;

//---------------------------------------------------------------------------
__fastcall TDetailForm::TDetailForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormCreate(TObject *Sender)
{
  TCustomStyleServices *LStyle;
  TColor MemoColor, MemoFontColor;

  //Set background color for memos to the color of the form, from the active style.
  LStyle = TStyleManager::ActiveStyle;
  MemoColor = LStyle-> GetStyleColor(scGenericBackground);
  MemoFontColor = LStyle->GetStyleFontColor(sfButtonTextNormal);

  Memo1->Color = MemoColor;
  Memo1->Font->Color = MemoFontColor;
  Memo2->Color = MemoColor;
  Memo2->Font->Color = MemoFontColor;
  Memo3->Color = MemoColor;
  Memo3->Font->Color = MemoFontColor;
  Memo4->Color = MemoColor;
  Memo4->Font->Color = MemoFontColor;

  //Fill image
  GridForm->PickImageColor(Image2, clBtnShadow);
}

void __fastcall TDetailForm::AppBarResize()
{
  AppBar->SetBounds(0, AppBar->Parent->Height - AppBarHeight,
    AppBar->Parent->Width, AppBarHeight);
}

void __fastcall TDetailForm::AppBarShow(int mode)
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

void __fastcall TDetailForm::FormShow(TObject *Sender)
{
  AppBarShow(0);

  String memoStr;
  TStringList *GroupElements;
  TCustomStyleServices *LStyle;

	// Show the originating badge"s title
  GroupElements= new TStringList();
  GroupElements->Delimiter = L'_';
  GroupElements->DelimitedText = GridForm->SelectedGroup;
  TitleLabel->Caption = "Title: " + GroupElements->Strings[0];
  ItemTitle->Caption =  "Item Title: " + GroupElements->Strings[1];

  LStyle = TStyleManager::ActiveStyle;
  Memo1->Color = LStyle->GetStyleColor(scGenericBackground);
  Memo1->Font->Color = LStyle->GetStyleFontColor(sfButtonTextNormal);
  Memo2->Color = LStyle->GetStyleColor(scGenericBackground);
  Memo2->Font->Color = LStyle->GetStyleFontColor(sfButtonTextNormal);
  Memo3->Color = LStyle->GetStyleColor(scGenericBackground);
  Memo3->Font->Color = LStyle->GetStyleFontColor(sfButtonTextNormal);
  Memo4->Color = LStyle->GetStyleColor(scGenericBackground);
  Memo4->Font->Color = LStyle->GetStyleFontColor(sfButtonTextNormal);

  memoStr = GenericText + sLineBreak + sLineBreak +
            GenericText + sLineBreak + sLineBreak +
            GenericText + sLineBreak + sLineBreak +
            GenericText + sLineBreak + sLineBreak +
            GenericText + sLineBreak + sLineBreak +
            GenericText + sLineBreak;
  Memo1->Lines->Add(memoStr);
  Memo2->Lines->Add(memoStr);
  Memo3->Lines->Add(memoStr);
  Memo4->Lines->Add(memoStr);
}

void __fastcall TDetailForm::Image11Click(TObject *Sender)
{
  DetailForm->Hide();
}

void __fastcall TDetailForm::Action1Execute(TObject *Sender)
{
  AppBarShow(-1);
}

void __fastcall TDetailForm::FormResize(TObject *Sender)
{
  AppBarResize();
}

void __fastcall TDetailForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
  AppBarShow( (Key == VK_ESCAPE) ? -1 : 0 );
}

void __fastcall TDetailForm::FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled)
{
  AppBarShow( 0 );
}

void __fastcall TDetailForm::BackToMainForm(TObject *Sender)
{
  Hide();
  GridForm->BringToFront();
}
