/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32\n";
	char bit[40];
	cin >> (bit+1);
	int len = strlen(bit + 1);
	long long rt = 0ll;
	long long bin = 1ll;
	for (int i = len; i; --i, bin *= 2ll)
		rt += (bit[i] == '1') * bin;
	cout << rt << endl;
	return 0;
}
