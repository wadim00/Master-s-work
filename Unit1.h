//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TBetcherForm : public TForm
{
__published:	// IDE-managed Components

	TImage *Image1;
	TButton *Button1;
	TEdit *Edit1;
	TButton *Button2;
	TStringGrid *StringGrid1;
	TStringGrid *StringGrid2;
	TStringGrid *StringGrid3;
	TChart *Chart1;
	TChart *Chart2;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TButton *Button3;
	TSaveTextFileDialog *SaveTextFileDialog1;
	TMemo *Memo1;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TLineSeries *Series1;
	TLineSeries *Series2;
	TPanel *Panel6;
	TSplitter *Splitter1;
	TLabel *Label3;
	TLabel *Label2;
	TEdit *Edit2;
	TLabel *Label4;
	TEdit *Edit3;
	TLabel *Label5;
	TEdit *Edit4;
	TLabel *Label6;
	TEdit *Edit5;
	TPanel *Panel7;
	TCheckBox *CheckBox1;
	TLabel *Label1;
	TEdit *Edit6;
	TCheckBox *CheckBox2;
	TPanel *Panel8;
	TImage *Image2;
	void __fastcall BackToMainForm(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Chart2ClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex,
          TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TBetcherForm(TComponent* Owner);
	  int algorithm_number;
	  TPanel *Panel1;
};
//---------------------------------------------------------------------------
extern PACKAGE TBetcherForm *BetcherForm;
//---------------------------------------------------------------------------
#endif
