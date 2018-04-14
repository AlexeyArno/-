//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TBitwiseSort : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TBitwiseSort(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
