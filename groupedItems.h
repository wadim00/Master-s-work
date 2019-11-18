//---------------------------------------------------------------------------

#ifndef groupedItemsH
#define groupedItemsH
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
#include <Vcl.ImgList.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Touch.GestureMgr.hpp>
//---------------------------------------------------------------------------
const String GenericText = "Sed ut perspiciatis unde omnis iste natus error "
  "sit voluptatem accusantium doloremque laudantium, totam rem aperiam, "
  "eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae "
  "vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas "
  "sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores "
  "eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, "
  "qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, "
  "sed quia non numquam eius modi tempora incidunt ut labore et dolore "
  "magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis "
  "nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut "
  "aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit "
  "qui in ea voluptate velit esse quam nihil molestiae consequatur, vel "
  "illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
class TGridForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TPanel *GroupPanel1;
    TLabel *Label2;
    TFlowPanel *FlowPanel1;
    TPanel *GroupPanel1_1;
    TPanel *GroupPanel1_2;
    TPanel *Panel5;
    TLabel *Label3;
    TLabel *Label4;
    TImage *Image2;
    TPanel *Panel6;
    TLabel *Label5;
    TPanel *GroupPanel1_3;
    TImage *Image3;
    TPanel *Panel4;
    TLabel *Label6;
    TPanel *GroupPanel2;
    TFlowPanel *FlowPanel2;
    TLabel *Label7;
    TPanel *GroupPanel2_1;
    TLabel *Label8;
    TLabel *Label9;
    TImage *Image4;
    TPanel *Panel2;
    TPanel *GroupPanel2_2;
    TPanel *Panel3;
    TImage *Image5;
    TPanel *GroupPanel3;
    TFlowPanel *FlowPanel3;
    TPanel *GroupPanel3_1;
    TPanel *GroupPanel3_2;
    TPanel *GroupPanel3_3;
    TPanel *GroupPanel3_4;
    TPanel *GroupPanel3_5;
    TPanel *Panel7;
    TPanel *Panel8;
    TPanel *Panel9;
    TPanel *Panel10;
    TPanel *Panel11;
    TImage *Image6;
    TImage *Image7;
    TImage *Image8;
    TImage *Image9;
    TScrollBox *ScrollBox2;
    TImage *Image10;
    TPanel *Panel12;
    TLabel *Label10;
    TImage *Image11;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label17;
    TLabel *Label18;
    TLabel *Label19;
    TLabel *Label20;
    TLabel *Label21;
    TLabel *Label22;
    TLabel *Label23;
    TLabel *Label24;
    TGestureManager *GestureManager1;
    TActionList *ActionList1;
	TAction *Action1;
	TPanel *AppBar;
	TImage *Image1;
    void __fastcall ScrollBox2Resize(TObject *Sender);
    void __fastcall GroupPanel1_1Click(TObject *Sender);
    void __fastcall Image11Click(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Action1Execute(TObject *Sender);
	void __fastcall FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall GroupPanel1_2Click(TObject *Sender);
	void __fastcall GroupPanel1_3Click(TObject *Sender);
	// User declarations

public:		// User declarations
	void __fastcall AppBarResize(void);
	void __fastcall AppBarShow(int mode);
	UnicodeString SelectedGroup;  // group string from
    void __fastcall PickImageColor(TImage *img, TColor AColor);
	__fastcall TGridForm(TComponent* Owner);
};

extern PACKAGE TGridForm *GridForm;

#endif
