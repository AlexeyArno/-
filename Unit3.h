//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TBubbleSort : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TBubbleSort(bool CreateSuspended, std::vector<int>);
	void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
