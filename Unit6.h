//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>
//---------------------------------------------------------------------------
class THeapSort : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall THeapSort(bool CreateSuspended, std::vector<int>);
	void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
