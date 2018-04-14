#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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



__fastcall TBubbleSort::TBubbleSort(bool CreateSuspended, std::vector<int> _vec)
	: TThread(CreateSuspended)
{
	vec=_vec;
	QueryPerformanceFrequency(&freq);
}

void __fastcall TBubbleSort::UpdateCaption()
{
	Form1->Timer2->Enabled = false;
	Form1->ListBox2->Clear();
	Form1->ListBox2->Items->Add(IntToStr(int(vec.size())));
	for(int i=0; i<10;i++){
		Form1->ListBox2->Items->Add(IntToStr(vec[i]));
	}
	Form1->ListBox2->Items->Add(".");
	Form1->ListBox2->Items->Add(".");
	Form1->ListBox2->Items->Add(".");

//	int timeout = (End-Start)/QPT;
	Form1->Label10->Caption = FloatToStrF(
		(float)(t2.QuadPart-t1.QuadPart)/freq.QuadPart
		, ffGeneral, 4, 2);
}
//---------------------------------------------------------------------------
void __fastcall TBubbleSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
	int tmp, i, j;
	for(i = 0; i < vec.size() - 1; ++i)
    {
		for(j = 0; j < vec.size() - 1; ++j)
        {
			if (vec[j + 1] < vec[j])
			{
				tmp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = tmp;
            }
        }
	}
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------
