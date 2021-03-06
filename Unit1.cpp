// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//! Variable to store the value of the first number
UnicodeString number1;
//! Variable to store the value of the second number
UnicodeString number2;
//! Variable to store the sign value of the operation
UnicodeString znak;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
/**
*@brief Number button press event handler
*/
void __fastcall TForm1::Button1Click(TObject *Sender) {
	TControl* ptContr;
	ptContr = static_cast<TControl*>(Sender);
	UnicodeString str = ptContr->Name;

	TButton* ptButton;
	ptButton = dynamic_cast<TButton*>(Sender);
	if (ptButton == NULL) {
		ShowMessage("?? ?????? ?-" + str);
		return;
	}
	// ShowMessage("??????-" + str);
	Form1->Label1->Caption = Label1->Caption + ptButton->Caption;
}

// ---------------------------------------------------------------------------
/**
*@brief Clear button click event handler
*/
void __fastcall TForm1::Button10Click(TObject *Sender) {
	Label1->Caption = "";
}

// ---------------------------------------------------------------------------
/**
*@brief Addition button click event handler
*/
void __fastcall TForm1::Button13Click(TObject *Sender) {
	znak = "+";
	number1 = Label1->Caption;
	Label1->Caption = "";
}

// ---------------------------------------------------------------------------
/**
*@brief Substraction button click event handler
*/
void __fastcall TForm1::Button14Click(TObject *Sender) {
	znak = "-";
	number1 = Label1->Caption;
	Label1->Caption = "";
}

// ---------------------------------------------------------------------------
/**
*@brief Multiplication button click event handler
*/
void __fastcall TForm1::Button15Click(TObject *Sender) {
	znak = "*";
	number1 = Label1->Caption;
	Label1->Caption = "";
}

// ---------------------------------------------------------------------------
/**
*@brief Division button click event handler
*/
void __fastcall TForm1::Button16Click(TObject *Sender) {
	znak = "/";
	number1 = Label1->Caption;
	Label1->Caption = "";
}

// ---------------------------------------------------------------------------
/**
*@brief Result button click event handler
*/
void __fastcall TForm1::Button12Click(TObject *Sender) {
	number2 = Label1->Caption;
	if (number1 != "" & number2 != "" & znak != "") {
		if (znak == "+") {
			Label1->Caption = FloatToStr(StrToFloat(number1) + StrToFloat(number2));
		}
		if (znak == "-") {
			Label1->Caption = FloatToStr(StrToFloat(number1) - StrToFloat(number2));
		}
		if (znak == "*") {
			Label1->Caption = FloatToStr(StrToFloat(number1) * StrToFloat(number2));
		}
		if (znak == "/") {
			if (number2 != "0") {
				Label1->Caption = FloatToStr(StrToFloat(number1) / StrToFloat(number2));
			}
			else Label1->Caption = "?????? ?????? ?? 0";
		}
		if (znak == "%") {
			Label1->Caption = FloatToStr(StrToInt(number1) % StrToInt(number2));
		}

		number2 = "";
		znak = "";
		number1 = Label1->Caption;
		return;
	}
	number2 = "";
	znak = "";
	number1 = "";
	Label1->Caption = "";
	ShowMessage("?? ?????????? ?????? ????????? ???? ???????");
}
// ---------------------------------------------------------------------------
/**
*@brief Raising to the 3rd power button click event handler
*/
void __fastcall TForm1::Button17Click(TObject *Sender)
{
	znak = "%";
	number1 = Label1->Caption;
	Label1->Caption = "";

}
//---------------------------------------------------------------------------
/**
*@brief Sign change button click event handler
*/
void __fastcall TForm1::Button18Click(TObject *Sender)
{
	UnicodeString str = Label1->Caption;
	if (str != "") {
        if (str.Pos("-") == 0) {
			str.Insert("-",1);
			Label1->Caption = str;
		}
		else if (str.Pos("-") == 1) {
			str.Delete(1,1);
			Label1->Caption = str;
		}
	}

}
//---------------------------------------------------------------------------
/**
*@brief Deleting a character button click event handler
*/
void __fastcall TForm1::Button19Click(TObject *Sender)
{
	UnicodeString str = Label1->Caption;
	str.Delete(Label1->Caption.Length(),1);
    Label1->Caption = str;
}
//---------------------------------------------------------------------------

