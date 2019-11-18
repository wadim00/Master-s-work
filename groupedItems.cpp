//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "groupedItems.h"
#include "itemDetail.h"
#include "Unit1.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TGridForm *GridForm;
const int AppBarHeight = 75;

__fastcall TGridForm::TGridForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TGridForm::AppBarResize()
{
  AppBar->SetBounds(0, AppBar->Parent->Height - AppBarHeight,
	AppBar->Parent->Width, AppBarHeight);
}

void __fastcall TGridForm::AppBarShow(int mode)
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

void __fastcall TGridForm::Action1Execute(TObject *Sender)
{
  AppBarShow(-1);
}

void __fastcall TGridForm::FormResize(TObject *Sender)
{
  AppBarResize();
}

void __fastcall TGridForm::FormShow(TObject *Sender)
{
  AppBarShow(0);
}

void __fastcall TGridForm::GroupPanel1_1Click(TObject *Sender)
{
	// Assuming here the image will be clicked

  BetcherForm->Show() ;
  AppBar->Height+=15;
  BetcherForm->Height-=10;
  BetcherForm->BringToFront();
  BetcherForm->algorithm_number=1;
  BetcherForm->Panel7->Caption="Алгоритм Бетчера";
}

void __fastcall TGridForm::Image11Click(TObject *Sender)
{
  Application->Terminate();
}

void __fastcall TGridForm::PickImageColor(TImage *img, TColor AColor)
{
  img->Canvas->Brush->Color = AColor;
  img->Canvas->Brush->Style = bsSolid;
  img->Canvas->FillRect(img->ClientRect);
  img->Canvas->Refresh();
}

void __fastcall TGridForm::ScrollBox2Resize(TObject *Sender)
{
  GroupPanel1->Height = ((TControl *)Sender)->ClientHeight-10;
  GroupPanel2->Height = ((TControl *)Sender)->ClientHeight-10;
  GroupPanel3->Height = ((TControl *)Sender)->ClientHeight-10;
  // Init panels
  PickImageColor(Image1, clYellow);
  PickImageColor(Image2, clInactiveCaption);
  PickImageColor(Image3, cl3DLight);
  PickImageColor(Image4, clBtnShadow);
  PickImageColor(Image5, clInactiveCaption);
  PickImageColor(Image6, cl3DLight);
  PickImageColor(Image7, clBtnShadow);
  PickImageColor(Image8, clInactiveCaption);
  PickImageColor(Image9, cl3DLight);
  PickImageColor(Image10, clBtnShadow);
}

void __fastcall TGridForm::FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled)
{
  AppBarShow( 0 );
}

void __fastcall TGridForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
  AppBarShow( (Key == VK_ESCAPE) ? -1 : 0 );
}
void __fastcall TGridForm::GroupPanel1_2Click(TObject *Sender)
{
  BetcherForm->Show() ;
  AppBar->Height+=15;
  BetcherForm->Height-=10;
  BetcherForm->BringToFront();
  BetcherForm->algorithm_number=2;
  BetcherForm->Panel7->Caption="Парно-непарна перестановка";


}
//---------------------------------------------------------------------------
void __fastcall TGridForm::GroupPanel1_3Click(TObject *Sender)
{
 // AnimateWindow(Handle, 500, AW_HIDE | AW_SLIDE | AW_VER_POSITIVE);
 //AnimateWindow(BetcherForm->Handle, 500, AW_ACTIVATE | AW_SLIDE | AW_HOR_POSITIVE);
  BetcherForm->Show() ;
  AppBar->Height+=15;
  BetcherForm->Height-=10;
  BetcherForm->BringToFront();
  BetcherForm->algorithm_number=3;
  BetcherForm->Panel7->Caption="Алгоритм Шелла";
}
//---------------------------------------------------------------------------

