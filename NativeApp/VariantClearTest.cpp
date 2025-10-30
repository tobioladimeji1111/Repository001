#include <windows.h>

bool VariantClearTest1()
{
	VARIANT v;
	VariantClear(&v);
	return true;
}