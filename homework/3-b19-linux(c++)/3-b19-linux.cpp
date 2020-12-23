/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{

	int tot = 0;
	for(int x1 = 1; x1 <= 9; ++ x1)
		for (int x2 = 1; x2 <= 9; ++x2) {
			if (x2 == x1)
				continue;
			for (int x3 = 1; x3 <= 9; ++x3) {
				if (x3 == x2 || x3 == x1)
					continue;
				for (int x4 = x1+1; x4 <= 9; ++x4) {
					if (x4 == x3 || x4 == x2 || x4 == x1)
						continue;
					for (int x5 = 1; x5 <= 9; ++x5) {
						if (x5 == x4 || x5 == x3 || x5 == x2 || x5 == x1)
							continue;
						for (int x6 = 1; x6 <= 9; ++x6) {
							if (x6 == x5 || x6 == x4 || x6 == x3 || x6 == x2 || x6 == x1)
								continue;
							for (int x7 = x4+1; x7 <= 9; ++x7) {
								if (x7 == x6 || x7 == x5 || x7 == x4 || x7 == x3 || x7 == x2 || x7 == x1)
									continue;
								for (int x8 = 1; x8 <= 9; ++x8) {
									if (x8 == x7 || x8 == x6 || x8 == x5 || x8 == x4 || x8 == x3 || x8 == x2 || x8 == x1)
										continue;
									for (int x9 = 1; x9 <= 9; ++x9) {
										if (x9 == x8 || x9 == x7 || x9 == x6 || x9 == x5 || x9 == x4 || x9 == x3 || x9 == x2 || x9 == x1)
											continue;
										if((x1+x4+x7)*100+(x2+x5+x8)*10+x3+x6+x9 == 1953)
											cout << "No." << setw(3) << ++tot << " : " << x1*100+x2*10+x3 << '+' << x4*100+x5*10+x6 << '+' << x7*100+x8*10+x9 << '=' << 1953 << '\n';
									}
								}
							}
						}
					}
				}
			}
		}
	cout << "total=" << tot << '\n';
	return 0;
}