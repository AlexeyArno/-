//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <stdlib>
#include <time.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int timerPos1 = 1;
int timerPos2 = 1;
int timerPos3 = 1;
int timerPos4 = 1;
int timerPos5 = 1;
int timerPos6 = 1;
int timerPos7 = 1;
std::vector<int> basicVec;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void SelectionSort(){
	Form1->Timer1->Enabled = true;
	TSelectionSort *myThread = new TSelectionSort(false, basicVec);
}

void BubbleSort(){
	Form1->Timer2->Enabled = true;
	TBubbleSort *myThread = new TBubbleSort(false, basicVec);
}

void InsertSort(){
	Form1->Timer3->Enabled = true;
	TInsertSort *myThread = new TInsertSort(false, basicVec);
}

void ShellSort(){
	Form1->Timer4->Enabled = true;
	TShellSort *myThread = new TShellSort(false, basicVec);
}

void FastSort(){
	Form1->Timer6->Enabled = true;
	TFastSort *myThread = new TFastSort(false,basicVec);
}


//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Form1->ListBox8->Clear();
	int count = StrToInt(Form1->ComboBox1->Items->Strings[ComboBox1->ItemIndex]);
	for(int i=0; i<count;i++)
	{
		basicVec.push_back(rand()%20);
	}
	for(int j=0;j<10;j++)
	{
		Form1->ListBox8->Items->Add(IntToStr(basicVec[j]));
	}

	Form1->ListBox8->Items->Add(".");
	Form1->ListBox8->Items->Add(".");
	Form1->ListBox8->Items->Add(".");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	SelectionSort();
	BubbleSort();
	InsertSort();
//	ShellSort();
	FastSort();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	ListBox1->Clear();
	ListBox2->Clear();
	ListBox3->Clear();
	ListBox4->Clear();
	ListBox5->Clear();
	ListBox6->Clear();
	ListBox7->Clear();
	ListBox8->Clear();

	Label9->Caption="";
	Label10->Caption="";
	Label11->Caption="";
	Label12->Caption="";
	Label13->Caption="";
	Label14->Caption="";
	Label15->Caption="";

	basicVec.clear();



}

void someLoader1(int* pos, TLabel* Obj)
{
   switch(*pos){
		case 1:
			*pos = 2;
			Obj->Caption = "\\";
			break;
		case 2:
			*pos = 3;
			Obj->Caption = "|";
			break;
		case 3:
			*pos = 4;
			Obj->Caption = "/";
			break;
		case 4:
			*pos = 5;
			Obj->Caption = "-";
			break;
		case 5:
			*pos = 6;
			Obj->Caption = "\\";
			break;
		case 6:
			*pos = 7;
			Obj->Caption = "|";
			break;
		case 7:
			*pos = 8;
			Obj->Caption = "/";
			break;
		case 8:
			*pos = 1;
			Obj->Caption = "-";
			break;
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	someLoader1(&timerPos1, Label9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	someLoader1(&timerPos2, Label10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	someLoader1(&timerPos3, Label11);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
	someLoader1(&timerPos4, Label12);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
	someLoader1(&timerPos5, Label13);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer6Timer(TObject *Sender)
{
	someLoader1(&timerPos6, Label14);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer7Timer(TObject *Sender)
{
	someLoader1(&timerPos7, Label15);
}
//---------------------------------------------------------------------------

