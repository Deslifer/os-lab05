#include <windows.h>
#include <stdio.h>
 
extern "C" {
   	_declspec(dllimport) void Hello(void);
}
int main(void) {
   	Hello();
   	return 0;
}
