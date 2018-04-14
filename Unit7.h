//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TFastSort : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TFastSort(bool CreateSuspended, std::vector<int>);
	void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
