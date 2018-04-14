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

int increment(long inc[], long size)
{
    int p1, p2, p3, s;
    p1 = p2 = p3 = 1;
    s = -1;
    do
    {
        if (++s % 2)
        {
            inc[s] = 8*p1 - 6*p2 + 1;
        }
        else
        {
			inc[s] = 9*p1 - 9*p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
    p1 *= 2;
    }
    while(3*inc[s] < size);

    return s > 0 ? --s : 0;
}



__fastcall TShellSort::TShellSort(bool CreateSuspended, std::vector<int> _vec)
	: TThread(CreateSuspended)
{
	vec=_vec;
	QueryPerformanceFrequency(&freq);
}

void __fastcall TShellSort::UpdateCaption()
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
void __fastcall TShellSort::Execute()
{
	FreeOnTerminate = true;
	QueryPerformanceCounter(&t1);
	long inc, i, j, seq[40];
    int s;

	s = increment(seq, vec.size()); // вычисление последовательности приращений
    while (s >= 0)  // сортировка вставками с инкрементами inc[]
    {
		 inc = seq[s--];
		 for (i = inc; i < vec.size(); ++i)
         {
			 int temp = vec[i];
			 for (j = i; (j >= inc) && (temp < vec[j-inc]); j -= inc) {
				vec[j] = vec[j - inc];
			 }
			 vec[j] = temp;
         }
	}
	QueryPerformanceCounter(&t2);
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------

