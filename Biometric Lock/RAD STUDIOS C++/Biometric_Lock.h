//---------------------------------------------------------------------------

#ifndef Biometric_LockH
#define Biometric_LockH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *btnEnroll;
	TEdit *edtStdNum;
	TLabel *lblStdNo;
	TEdit *edtStdDetails;
	TLabel *lblStdDetails;
	TLabel *lblFingerID;
	TLabel *lblIn;
	TLabel *lblOut;
	TLabel *lblAll;
	TTimer *Timer1;
	TTimer *Timer2;
	TListBox *lstAll;
	TListBox *lstOUT;
	TListBox *lstIN;
	TLabel *lblScanned;
	TTimer *Timer3;
	TLabel *lblDelete;
	void __fastcall btnEnrollClick(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
