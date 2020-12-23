/*1952339 –≈08 ’≈‹∞‘¬*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void tj_strcpy(char a[], char b[])
{
	int n = strlen(b);
	for (int i = 0; i <= n; ++i)
		a[i] = b[i];
}

int main()
{
	char S[3][30], t[30];
	cin >> S[0] >> S[1] >> S[2];
	if (strcmp(S[0], S[1]) > 0) {
		tj_strcpy(t, S[0]);
		tj_strcpy(S[0], S[1]);
		tj_strcpy(S[1], t);
	}
	if (strcmp(S[0], S[2]) > 0) {
		tj_strcpy(t, S[2]);
		tj_strcpy(S[2], S[1]);
		tj_strcpy(S[1], S[0]);
		tj_strcpy(S[0], t);
	}
	else if (strcmp(S[1], S[2]) > 0) {
		tj_strcpy(t, S[1]);
		tj_strcpy(S[1], S[2]);
		tj_strcpy(S[2], t);
	}
	cout << S[0] << '\n';
	cout << S[1] << '\n';
	cout << S[2] << '\n';
	return 0;
}