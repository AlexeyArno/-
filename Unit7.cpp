#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
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



__fastcall TFastSort::TFastSort(bool CreateSuspended, std::vector<int> _vec)
	: TThread(CreateSuspended)
{
	vec=_vec;
	QueryPerformanceFrequency(&freq);
}

void __fastcall TFastSort::UpdateCaption()
{
	Form1->Timer6->Enabled = false;
	Form1->ListBox6->Clear();
	Form1->ListBox6->Items->Add(IntToStr(int(vec.size())));
	for(int i=0; i<10;i++){
		Form1->ListBox6->Items->Add(IntToStr(vec[i]));
	}
	Form1->ListBox6->Items->Add(".");
	Form1->ListBox6->Items->Add(".");
	Form1->ListBox6->Items->Add(".");

//	int timeout = (End-Start)/QPT;
	Form1->Label14->Caption = FloatToStrF(
		(float)(t2.QuadPart-t1.QuadPart)/freq.QuadPart
		, ffGeneral, 4, 2);
}

void quickSortR(int* a, long N) {
	long i = 0, j = N;
	int temp, p;
	p = a[ N>>1 ];
    do {
        while ( a[i] < p ) i++;
        while ( a[j] > p ) j--;

        if (i <= j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++; j--;
        }
	} while ( i<=j );
    if ( j > 0 ) quickSortR(a, j);
    if ( N > i ) quickSortR(a+i, N-i);
}

//---------------------------------------------------------------------------
void __fastcall TFastSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
	int* arr = &vec[0];
	quickSortR(arr, vec.size());
	std::vector<int> v(arr, arr + vec.size());
	vec = v;
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------

