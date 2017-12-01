#include <windows.h>
#include <stdio.h>
 
typedef void(__cdecl *DLLHELLO)(void);
 
int main(void)
{
   	HINSTANCE hLib;
   	DLLHELLO Hello;
   	BOOL libSuccess = FALSE;
 
   	// загрузить DLL-библиотеку
   	hLib = LoadLibrary(L"DLL.dll");
 
   	// если дескриптор получен, найти адрес функции и вызывать ее
   	if (hLib != NULL)
   	{
         	Hello = (DLLHELLO) GetProcAddress(hLib, "Hello");
         	printf("Address of Hello = %08x\n", (unsigned) Hello);
         	printf("Address of main = %08x\n", (unsigned) main);
 
         	// если адрес допустимый, вызвать функцию
         	if (NULL != Hello)
         	{
                	libSuccess = TRUE;
                	Hello();
         	}
         	// освободить DLL-библиотеку
         	FreeLibrary(hLib);
   	}
   	if (!libSuccess) printf("Error loading library DLL.dll\n");
   	return 0;
}
