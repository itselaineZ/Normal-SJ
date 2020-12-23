#include <iostream>
using namespace std;

int x;
double y;
int z;
int a[10], k;

int main()
{
	/*
	int x;
	double y;
	int z;
	int k, a[10];*/
	printf("%x\n", &x);
	printf("%x\n", &y);
	printf("%x\n", &z);
	printf("%x\n", &k);
	printf("%x\n", a);
	printf("%x\n", &a[1]);
	return 0;
}