#include <stdio.h>
 	
extern "C"
{
   	__declspec(dllexport) int factorial(int n) {
         	if (n == 0) return 1;
         	else return factorial(n - 1) * n;
   	}
 
   	__declspec(dllexport) int Cnk(int n, int k) {
         	return factorial(n) / (factorial(k)*factorial(n - k));
   	}
 	
   	__declspec(dllexport) void Hello( void )
   	{
         	printf("Hello from DLL!\n");
   	}
}
