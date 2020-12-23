#include<stdio.h>
#include<string.h>
int main() {
	int a[5][10], b[10];
	b[5] = 0;
	a[0][0] = 5;
	printf("%d\n", a[b]);
	printf("%d\n", *(*a));
	return 0;
}