#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
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

void sort()
{
	int n = vec.size();
	int gap,i,j,temp;

    for(gap=n/2;gap>0;gap/=2)
    {
        for(i=gap;i<n;i+=1)
        {
			temp=vec[i];
			for(j=i;j>=gap&&vec[j-gap]>temp;j-=gap)
				vec[j]=vec[j-gap];

			vec[j]=temp;
		}
    }
}


__fastcall TShellSort::TShellSort(bool CreateSuspended, std::vector<int> _vec)
	: TThread(CreateSuspended)
{
	vec=_vec;
	QueryPerformanceFrequency(&freq);
}

void __fastcall TShellSort::UpdateCaption()
{
	Form1->Timer4->Enabled = false;
	Form1->ListBox4->Clear();
	Form1->ListBox4->Items->Add(IntToStr(int(vec.size())));
	for(int i=0; i<10;i++){
		Form1->ListBox4->Items->Add(IntToStr(vec[i]));
	}
	Form1->ListBox4->Items->Add(".");
	Form1->ListBox4->Items->Add(".");
	Form1->ListBox4->Items->Add(".");

//	int timeout = (End-Start)/QPT;
	Form1->Label12->Caption = FloatToStrF(
		(float)(t2.QuadPart-t1.QuadPart)/freq.QuadPart
		, ffGeneral, 4, 2);
}
//---------------------------------------------------------------------------
void __fastcall TShellSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
	sort();
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------

