//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TInsertSort : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TInsertSort(bool CreateSuspended, std::vector<int>);
	void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
