//---------------------------------------------------------------------------

#include <vcl.h>
#include <IdHTTP.hpp>
#pragma hdrstop

#include "Biometric_Lock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnEnrollClick(TObject *Sender)
{
	String sId,sHold;
	int ipos ;

	sHold = lblFingerID->Caption;
	ipos = sHold.Pos(":") + 1 ;
	sHold.Delete(1,ipos);
	sId = sHold;
	bool bNum = false, bDetails = false ;

	TStringList *outline = new TStringList;
	outline->LoadFromFile( "TEXTFILES/PROFILES.txt");

	if (edtStdDetails->Text.Length() < 3)
	{
	  MessageDlg("Enter Valid Student Details!!",mtError,mbAbortRetryIgnore,0);
	  bDetails = false ;
	} else bDetails = true ;

	if (edtStdNum->Text.Length() != 9) {
	   MessageDlg("INVALID Student Number!!",mtError,mbAbortRetryIgnore,0);
	   bNum = false ;
	} else bNum = true ;

	   String searchID = edtStdNum->Text; // search by id
		for (int i = 0; i < outline->Count; i++)
		{
			String line = outline->Strings[i];
			if (line.Pos(searchID) > 0)
			{
			   MessageDlg("Student already exists!!",mtError,mbAbortRetryIgnore,0);
			   bNum = false ;
			}
		}

	if (bDetails == true && bNum == true)
	{
		outline->Add(edtStdNum->Text + "#" + edtStdDetails->Text +"#IDx"+ sId);
		outline->SaveToFile("TEXTFILES/PROFILES.txt");

		MessageDlg("Enrolled Successfully!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		edtStdDetails->Text = "";
		edtStdNum->Text = "" ;
	}
	delete outline ;
}
//---------------------------------------------------------------------------


String lastResponse0 = "", lastResponse2 = "";
String lastResponse1 = "", lastResponse = "", lastResponseD = "";

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{


	TStringList *outline1 = new TStringList;
	outline1->LoadFromFile("TEXTFILES/PROFILES.txt");
	int ipos = 0 ;
	lstAll->Items->Clear();
	String sSID, sDetails,sFID;
		for (int i = 0; i < outline1->Count; i++)
		{
			String line = outline1->Strings[i];

			ipos = line.Pos("#");
			sSID = line.SubString(0,ipos -1);
			line = line.Delete(1,ipos);

			ipos = line.Pos("#");
			sDetails = line.SubString(0,ipos -1);
			line = line.Delete(1,ipos);

			sFID =  line ;

			lstAll->Items->Add(sSID + "\t" + sDetails + "\t\t" + sFID);
		}

	int pos ;
	String sId, sHold ;
	bool bFound = false, bHold = false ;

	sHold = lblScanned->Caption;
	pos = sHold.Pos(":") + 1 ;
	sHold.Delete(1,pos);
	sId = "IDx" + sHold;
	int index = -1 ;

  String currentText2 = sId;

  if (currentText2 != lastResponse2)
	{
		lastResponse2 = currentText2;
		for (int i = 0; i < outline1->Count; i++)
		{
			String line = outline1->Strings[i];
			if (line.Pos(sId) > 0)
			{
				index = i ;
				sHold = line ;
				bFound = true ;
			}
		}
	}

	delete outline1 ;

	TStringList *outline = new TStringList;
	outline1->LoadFromFile("TEXTFILES/IN_OUT.txt");

	String sStateIN = "IN", sStateOUT = "OUT", sFingerID = sId  ;
	bool bOUT = false, bIN = false ;
	int indexIN = -1, indexOUT = -1 ;

	String sSID2, sDetails2, sFID2;
	int iposH = 0 ;

	String currentText = sFingerID;


  if (currentText != lastResponse0)
	{
		lastResponse0 = currentText;

	for (int i = 0; i < outline->Count; i++)
		{
			String sline = outline->Strings[i];

			if (sline.Pos(sStateIN) > 0 && sline.Pos(sFingerID) > 0)
			{
				indexIN = i ;
				bIN = true ;

			}

			if (sline.Pos(sStateOUT) > 0 && sline.Pos(sFingerID) > 0)
			{
				indexOUT = i ;
				bOUT = true ;

			}

		}
	}

	int posIN = 0 , posOUT = 0 ;
	String sHoldIN, sHoldOUT ;
  if(bIN)
  {
	posIN = outline->Strings[indexIN].Pos("#IN");
	sHoldIN =  outline->Strings[indexIN].SubString(0, posIN - 1) ;
	outline->Strings[indexIN] =  sHoldIN + "#OUT" ;

	outline->SaveToFile("TEXTFILES/IN_OUT.txt");
  }

  if (bOUT)
  {
	 posOUT = outline->Strings[indexOUT].Pos("#OUT");
	 sHoldOUT =  outline->Strings[indexOUT].SubString(0, posOUT - 1) ;
	 outline->Strings[indexOUT] =  sHoldOUT + "#IN" ;

	 outline->SaveToFile("TEXTFILES/IN_OUT.txt");

  }

  if (!bIN && !bOUT && bFound)
	{
	   outline->Add(sHold + "#OUT" );
	   outline->SaveToFile("TEXTFILES/IN_OUT.txt");
	}

	lstIN->Items->Clear() ;
	lstOUT->Items->Clear() ;
  for (int i = 0; i < outline->Count; i++)
		{
			String sCarry,sword = outline->Strings[i];
			sCarry = sword ;
				iposH = sword.Pos("#");
				sSID2 = sword.SubString(0,iposH -1);
				sword = sword.Delete(1,iposH);

				iposH = sword.Pos("#");
				sDetails2 = sword.SubString(0,iposH -1);
				sword = sword.Delete(1,iposH);

				iposH = sword.Pos("#");
				sFID2 = sword.SubString(0,iposH -1);

			if (sCarry.Pos(sStateIN) > 0)
			{
				lstIN->Items->Add(sSID2 + "\t" + sDetails2 + "\t\t" + sFID2);
			}

			if (sCarry.Pos(sStateOUT) > 0)
			{
				lstOUT->Items->Add(sSID2 + "\t" + sDetails2 + "\t\t" + sFID2);
			}
		}

  delete outline ;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TStringList *outline1 = new TStringList;
	outline1->LoadFromFile("TEXTFILES/PROFILES.txt");
	int ipos = 0 ;

		String sSID, sDetails,sFID;
		for (int i = 0; i < outline1->Count; i++)
		{
				String line = outline1->Strings[i];

				ipos = line.Pos("#");
				sSID = line.SubString(0,ipos -1);
				line = line.Delete(1,ipos);

				ipos = line.Pos("#");
				sDetails = line.SubString(0,ipos -1);
				line = line.Delete(1,ipos);

				sFID = line ;

				lstAll->Items->Add(sSID + "\t" + sDetails + "\t\t" + sFID);
		}

	delete outline1 ;
}
//---------------------------------------------------------------------------
String sHolder = "" ;
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{  ///*
TIdHTTP *http = new TIdHTTP(NULL);
	String url = "http://192.168.10.202/last_enrolled";
	try
	{
		std::unique_ptr<TStringStream> response(new TStringStream(UnicodeString("")));
		http->Get(url, response.get());

		UnicodeString currentText = response->DataString;

		if (currentText != lastResponse) {
			lastResponse = currentText;
			lblFingerID->Caption = currentText;
		}
	}
	catch (const EIdConnClosedGracefully &e)
	{
	   (void)e;
	}

	url = "http://192.168.10.202/last_scanned";
	try
	{
		std::unique_ptr<TStringStream> response(new TStringStream(UnicodeString("")));
		http->Get(url, response.get());

		UnicodeString currentText1 = response->DataString;

		if (currentText1 != lastResponse1) {
			lastResponse1 = currentText1;
			lblScanned->Caption = currentText1;
		}
	}
	catch (const EIdConnClosedGracefully &e)
	{
	   (void)e;
	}


	url = "http://192.168.10.202/delete_op";
	try
	{
		std::unique_ptr<TStringStream> response(new TStringStream(UnicodeString("")));
		http->Get(url, response.get());

		UnicodeString currentTextD = response->DataString;

		if (currentTextD != lastResponseD) {
			lastResponseD = currentTextD;
			lblDelete->Caption = currentTextD;
			sHolder  = currentTextD;
		}
	}
	catch (const EIdConnClosedGracefully &e)
	{
	   (void)e;
	}
	delete http ;


   TStringList *outline = new TStringList;
	outline->LoadFromFile("TEXTFILES/PROFILES.txt");
   TStringList *outline1 = new TStringList;
	outline1->LoadFromFile("TEXTFILES/IN_OUT.txt");

   if (sHolder == "DELETE") {

	  for (int j = 0; j < outline->Count; j++) {
		outline->Delete(j) ;
	  }

	  for (int i = 0; i < outline1->Count; i++) {
		outline1->Delete(i) ;
	  }

      outline->SaveToFile("TEXTFILES/PROFILES.txt");
	  outline1->SaveToFile("TEXTFILES/IN_OUT.txt");
   }

   delete outline ;
   delete outline1 ;

}
//---------------------------------------------------------------------------
