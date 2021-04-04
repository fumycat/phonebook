//---------------------------------------------------------------------------

#include <iostream>
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner, UnicodeString *name, UnicodeString *phone)
	: TForm(Owner)
{
	xname = name;
	xphone = phone;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
	Edit1->Text = *xname;
	Edit2->Text = *xphone;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	*xname = Edit1->Text;
	*xphone = Edit2->Text;
    this->Close();
}
//---------------------------------------------------------------------------
