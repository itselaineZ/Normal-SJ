/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool is_alpha(char x) {
	return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

char Exchange(char bef, char x) {
	if (bef == ' ') {
		if (x >= 'a' && x <= 'z')
			x -= 'a' - 'A';
	}
	else if (x >= 'A' && x <= 'Z')
		x += 'a' - 'A';
	return x;
}

int main()
{
	cout << "请输入字符串\n";
	char S[85];
	gets_s(S);
	int i = 0;
	while (S[i] == ' ')
		++ i;
	if (i == 0 && is_alpha(S[i]))
		S[i] = Exchange(' ', S[i]), ++ i;
	for ( ; i && S[i]; ++i) 
		S[i] = Exchange(S[i-1], S[i]);
	cout << S << '\n';
	return 0;
}