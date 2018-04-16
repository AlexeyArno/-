#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include <vector>
#include <time.h>
//#include <chrono.h>
#include<stdlib>
#pragma package(smart_init)
std::vector<int> vec;
LARGE_INTEGER t1,t2,freq;
double elapsedTime;

//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TSelectionSort::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------



__fastcall TInsertSort::TInsertSort(bool CreateSuspended, std::vector<int> _vec)
	: TThread(CreateSuspended)
{
	vec=_vec;
	QueryPerformanceFrequency(&freq);
}

void __fastcall TInsertSort::UpdateCaption()
{
	Form1->Timer3->Enabled = false;
	Form1->ListBox3->Clear();
	Form1->ListBox3->Items->Add(IntToStr(int(vec.size())));
	for(int i=0; i<10;i++){
		Form1->ListBox3->Items->Add(IntToStr(vec[i]));
	}
	Form1->ListBox3->Items->Add(".");
	Form1->ListBox3->Items->Add(".");
	Form1->ListBox3->Items->Add(".");

//	int timeout = (End-Start)/QPT;
	Form1->Label11->Caption = FloatToStrF(
		(float)(t2.QuadPart-t1.QuadPart)/freq.QuadPart
		, ffGeneral, 4, 2);
}
//---------------------------------------------------------------------------
void __fastcall TInsertSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
	int i, key, j;
	   for (i = 1; i < vec.size(); i++)
	   {
		   key = vec[i];
		   j = i-1;

		   /* Move elements of arr[0..i-1], that are
			  greater than key, to one position ahead
			  of their current position */
		   while (j >= 0 && vec[j] > key)
		   {
			   vec[j+1] = vec[j];
			   j = j-1;
		   }
		   vec[j+1] = key;
	   }
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------
