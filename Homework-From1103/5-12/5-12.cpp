/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	cout << "���������봮\n";
	char S[85];
	gets_s(S);
	cout << "����:" << S << '\n';
	cout << "ԭ��:";
	for (int i = 0; S[i]; ++i) {
		if (S[i] >= 'a' && S[i] <= 'z')
			S[i] = 'a' - 1 + 26 - (S[i] - 'a' + 1) + 1;
		else if(S[i] >= 'A' && S[i] <= 'Z')
			S[i] = 'A' - 1 + 26 - (S[i] - 'A' + 1) + 1;
	}
	cout << S << '\n';
	return 0;
}