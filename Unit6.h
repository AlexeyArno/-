//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TPyramidalSort : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TPyramidalSort(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
