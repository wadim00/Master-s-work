//---------------------------------------------------------------------------

#ifndef itemDetailH
#define itemDetailH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Variants.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Touch.GestureMgr.hpp>
//---------------------------------------------------------------------------
class TDetailForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *TitleLabel;
    TImage *Image1;
    TScrollBox *ScrollBox1;
    TPanel *TextPanel;
    TLabel *ItemTitle;
    TLabel *ItemSubtitle;
    TImage *Image2;
    TMemo *Memo1;
    TMemo *Memo2;
    TMemo *Memo3;
    TMemo *Memo4;
    TPanel *AppBar;
    TGestureManager *GestureManager1;
    TActionList *ActionList1;
    TAction *Action1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Image11Click(TObject *Sender);
	void __fastcall Action1Execute(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled);
	void __fastcall BackToMainForm(TObject *Sender);
private:	// User declarations
	void __fastcall AppBarResize(void);
	void __fastcall AppBarShow(int mode);
public:		// User declarations
	__fastcall TDetailForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDetailForm *DetailForm;
//---------------------------------------------------------------------------
#endif
