#include <stdio.h>
#include "combinatorics.h"

extern int extern_n;
int i_global_n = 0;
int global_n;

int main() {
	int n, k, local_n;
	local_n = i_global_n = extern_n = 0;

	printf("This program can count C(n,k). Enter 0 0 to exit.\n");
	printf("Addresses %x %x %x %x %x %x\n", &extern_n, &i_global_n, &global_n, &n, &k, &local_n);

	do {
		printf("Test %d: Enter n, k: ", ++local_n);
		scanf("%d %d", &n, &k);
		printf("C(%d,%d)=%d\n", n, k, C(n, k));
	} while (n != 0 || k != 0);

	printf("You tried %d times\n", local_n);
	return 0;
}