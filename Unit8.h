//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TBitwiseSort : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TBitwiseSort(bool CreateSuspended, std::vector<int>);
	void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
