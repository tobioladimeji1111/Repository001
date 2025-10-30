#include <windows.h>
#include <msxml2.h>
#include <msxml6.h>

void UnsafeXmlTest1(void)
{
  CLSID clsid = { 0 };
  void *pdoc = 0;
  HRESULT hr = CLSIDFromProgID(L"MSXML.DOMDocument", &clsid);
  hr = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, &pdoc); 
}