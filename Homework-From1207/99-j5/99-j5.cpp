/* 1952339 ĞÅ08 ÕÅÜ°ÔÂ */
#include <iostream>
using namespace std;

void f_sub(int x)
{
	cout << "x = " << x << endl;
}
void ff(const char *p)
{
	cout << "****\n";
}
int main()
{
	void (*a)(const char *p);
	void (*(*f[3])(const char* p))(int x);
	f[0]("Hello") = &f_sub;
	cout << f[0]("Hello");
	f[0]("Tongji")(7);

	return 0;
}
