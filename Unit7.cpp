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

	Form1->Label14->Caption = FloatToStrF(
		(float)(t2.QuadPart-t1.QuadPart)/freq.QuadPart
		, ffGeneral, 4, 2);
}


void quickSort(int* arr, int left, int right) {
	  int i = left, j = right;
	  int tmp;
	  int pivot = arr[(left + right) / 2];
	  while (i <= j) {
			while (arr[i] < pivot)
				  i++;
			while (arr[j] > pivot)
				  j--;
			if (i <= j) {
				  tmp = arr[i];
				  arr[i] = arr[j];
				  arr[j] = tmp;
				  i++;
				  j--;
			}
	  };
	  if (left < j)
			quickSort(arr, left, j);
	  if (i < right)
			quickSort(arr, i, right);
}

//---------------------------------------------------------------------------
void __fastcall TFastSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
	int* arr = &vec[0];
	quickSort(arr, 0, vec.size()-1);
	std::vector<int> v(arr, arr + vec.size());
	vec = v;
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------

