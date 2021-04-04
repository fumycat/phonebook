//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "UAbonentList.cpp"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
UAbonentList book;

void update_listbox()
{
	Form1->ListBox1->Items->Clear();
	std::vector<UnicodeString> data;
    data = book.as_str();
	for (auto const& z: data) {
        Form1->ListBox1->Items->Add(z);
    }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// button2 click clear
    book.clr();
	update_listbox();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// button1 click add
	UnicodeString sname = Form1->Edit1->Text;
	UnicodeString sphone = Form1->Edit2->Text;
	book.add(sname, sphone);
    update_listbox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    // button3 click remove
	int i = Form1->ListBox1->ItemIndex;
	if (i == -1) {
        return;
	}
	book.rem(i);
    update_listbox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
    // button7 click test data
	map<UnicodeString, UnicodeString> test_data = {
		{"Boba", "88006661122"},
		{"Biba", "900"},
		{"Jija", "89991112233"},
		{"Hihi", "7777777"},
		{"Haha", "66666666"},
		{"Artem", "51447"},
        {"Vlad", "1337"}
	};
	for (auto const& z: test_data) {
		book.add(z.first, z.second);
	}
	update_listbox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	// button6 click find
	UnicodeString fkey = Form1->Edit3->Text;
	int index = book.find(fkey);
	if (index == -1) {
		ShowMessage("Не найдено.");
	} else {
		Form1->ListBox1->ItemIndex = index;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	// button5 click save
	std::wofstream out_file("book.txt");
    std::vector<UnicodeString> data;
	data = book.as_str();
	if (out_file.is_open()) {
		for (auto const& z: data) {
            out_file << z.c_str() << std::endl;
		}
		out_file.close();
		ShowMessage("Сохранено.");
		return;
	} else {
		ShowMessage("Ошибка.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	// button4 click edit
	int i = Form1->ListBox1->ItemIndex;
	if (i == -1) {
		return;
	}
	pair<UnicodeString, UnicodeString> p = book.get_at(i);
	UnicodeString xname = p.first;
	UnicodeString xphone = p.second;
	TForm2 *Form = new TForm2(this, &xname, &xphone);
	Form->ShowModal();

	book.rem(i);
    book.add(xname, xphone);
	update_listbox();
}
//---------------------------------------------------------------------------

