//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit1.h"
#include <vector>
#include <time.h>
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
//      void __fastcall TPyramidalSort::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------


void heapify( int n, int i)
{
   // Find largest among root, left child and right child
   int largest = i;
   int l = 2*i + 1;
   int r = 2*i + 2;

   if (l < n && vec[l] > vec[largest])
     largest = l;

   if (r < n && vec[r] > vec[largest])
     largest = r;

   // Swap and continue heapifying if root is not largest
   if (largest != i)
   {
	 std::swap(vec[i], vec[largest]);
	 heapify(n, largest);
   }
}

// main function to do heap sort
void heapSort()
{
	int n = vec.size();
   // Build max heap
   for (int i = n / 2 - 1; i >= 0; i--)
	 heapify(n, i);

   // Heap sort
   for (int i=n-1; i>=0; i--)
   {
	 std::swap(vec[0], vec[i]);

     // Heapify root element to get highest element at root again
	 heapify(i, 0);
   }
}


__fastcall THeapSort::THeapSort(bool CreateSuspended, std::vector<int> _vec)
	: TThread(CreateSuspended)
{
	vec=_vec;
	QueryPerformanceFrequency(&freq);
}

void __fastcall THeapSort::UpdateCaption()
{
	Form1->Timer5->Enabled = false;
	Form1->ListBox5->Clear();
	Form1->ListBox5->Items->Add(IntToStr(int(vec.size())));
	for(int i=0; i<10;i++){
		Form1->ListBox5->Items->Add(IntToStr(vec[i]));
	}
	Form1->ListBox5->Items->Add(".");
	Form1->ListBox5->Items->Add(".");
	Form1->ListBox5->Items->Add(".");

//	int timeout = (End-Start)/QPT;
	Form1->Label13->Caption = FloatToStrF(
		(float)(t2.QuadPart-t1.QuadPart)/freq.QuadPart
		, ffGeneral, 4, 2);
}
//---------------------------------------------------------------------------
void __fastcall THeapSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
    heapSort();
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//--------------------------------------------------------------------------
