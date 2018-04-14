//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include <vector>
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TSelectionSort : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TSelectionSort(bool CreateSuspended, std::vector<int>);
	void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
