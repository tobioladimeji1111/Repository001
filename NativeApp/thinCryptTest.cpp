#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>
#include <intsafe.h>


HCRYPTKEY ThinCryptEspTest1(int length, LPCWSTR szContainer)
{
	HCRYPTPROV hProv = NULL;
	HCRYPTKEY hKey = NULL;

	if(CryptAcquireContext(&hProv, szContainer, NULL, PROV_RSA_FULL, 0)
		 || CryptAcquireContext(&hProv, szContainer, NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET))
	{
		if(CryptGenKey(hProv, CALG_RSA_KEYX, length << 16, &hKey))
		{
			return hKey;
		} else {
			printf("Failed to generate key -- error 0x%x", GetLastError());
		}
	} else {
		printf("Failed to acquire or create cryptography context");
	}

	return NULL;
}

int main(int argc, char **argv)
{

	char tim[256];
	strcpy(tim, argv[0]);
}

