#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
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



__fastcall TBitwiseSort::TBitwiseSort(bool CreateSuspended, std::vector<int> _vec)
	: TThread(CreateSuspended)
{
	vec=_vec;
	QueryPerformanceFrequency(&freq);
}

void __fastcall TBitwiseSort::UpdateCaption()
{
	Form1->Timer7->Enabled = false;
	Form1->ListBox7->Clear();
	Form1->ListBox7->Items->Add(IntToStr(int(vec.size())));
	for(int i=0; i<10;i++){
		Form1->ListBox7->Items->Add(IntToStr(vec[i]));
	}
	Form1->ListBox7->Items->Add(".");
	Form1->ListBox7->Items->Add(".");
	Form1->ListBox7->Items->Add(".");

	Form1->Label15->Caption = FloatToStrF(
		(float)(t2.QuadPart-t1.QuadPart)/freq.QuadPart
		, ffGeneral, 4, 2);
}

int getMax( int n)
{
	int max = vec[0];
	for (int i = 1; i < n; i++)
		if (vec[i] > max)
			max = vec[i];
	return max;
}

void countSort(int n, int exp)
{
	int *output = new int[n];
	int i, count[10] = {0};
	for (i = 0; i < n; i++)
		count[(vec[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(vec[i] / exp) % 10] - 1] = vec[i];
		count[(vec[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		vec[i] = output[i];
}

void radixsort(int n)
{
	int exp, m;
	m = getMax( n);
	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(n, exp);
}

//---------------------------------------------------------------------------
void __fastcall TBitwiseSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
	radixsort( vec.size());
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------

