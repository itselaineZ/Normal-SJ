/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	cout << "请输入一个0/1组成的字符串，长度不超过32\n";
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
