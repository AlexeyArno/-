//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
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



__fastcall TSelectionSort::TSelectionSort(bool CreateSuspended, std::vector<int> _vec)
	: TThread(CreateSuspended)
{
	vec=_vec;
	QueryPerformanceFrequency(&freq);
}

void __fastcall TSelectionSort::UpdateCaption()
{
	Form1->Timer1->Enabled = false;
	Form1->ListBox1->Clear();
	Form1->ListBox1->Items->Add(IntToStr(int(vec.size())));
	for(int i=0; i<10;i++){
		Form1->ListBox1->Items->Add(IntToStr(vec[i]));
	}
	Form1->ListBox1->Items->Add(".");
	Form1->ListBox1->Items->Add(".");
	Form1->ListBox1->Items->Add(".");

//	int timeout = (End-Start)/QPT;
	Form1->Label9->Caption = FloatToStrF(
		(float)(t2.QuadPart-t1.QuadPart)/freq.QuadPart,
		ffGeneral, 4,2);
}
//---------------------------------------------------------------------------
void __fastcall TSelectionSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
	int tmp, i, j, pos;
	for(i = 0; i < vec.size(); ++i)
	{
        pos = i;
		tmp = vec[i];
		for(j = i + 1; j < vec.size(); ++j)
		{
			if (vec[j] < tmp)
            {
               pos = j;
			   tmp = vec[j];
            }
		}
		vec[pos] = vec[i];
		vec[i] = tmp;
	}
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------

