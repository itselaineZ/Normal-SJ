/*1952339 пе08 уеэ╟тб*/
#include <stdio.h>

int main()
{
	int tot = 0, x1, x2, x3, x4, x5, x6, x7, x8, x9;
	x1 = 1;
	while(x1 <= 9){
		x2 = 1;
		while(x2 <= 9) {
			if (x2 == x1){
                ++ x2;
				continue;
			}
			x3 = 1;
			while(x3 <= 9) {
				if (x3 == x2 || x3 == x1){
                    ++ x3;
                    continue;
                }
				x4 = x1+1;
				while(x4 <= 9) {
					if (x4 == x3 || x4 == x2 || x4 == x1){
                        ++ x4;
                        continue;
                    }
					x5 = 1;
					while(x5 <= 9) {
						if (x5 == x4 || x5 == x3 || x5 == x2 || x5 == x1){
                            ++ x5;
                            continue;
						}
						x6 = 1;
						while(x6 <= 9) {
							if (x6 == x5 || x6 == x4 || x6 == x3 || x6 == x2 || x6 == x1){
                          		++ x6;
                            	continue;
							}
							x7 = x4 + 1;
							while(x7 <= 9) {
								if (x7 == x6 || x7 == x5 || x7 == x4 || x7 == x3 || x7 == x2 || x7 == x1){
                            		++ x7;
                            		continue;
								}
								x8 = 1;
								while(x8 <= 9) {
									if (x8 == x7 || x8 == x6 || x8 == x5 || x8 == x4 || x8 == x3 || x8 == x2 || x8 == x1){
                            			++ x8;
                            			continue;
									}
									x9 = 1;
									while(x9 <= 9) {
										if (x9 == x8 || x9 == x7 || x9 == x6 || x9 == x5 || x9 == x4 || x9 == x3 || x9 == x2 || x9 == x1){
                            				++ x9;
                            				continue;
											}
										if ((x1 + x4 + x7) * 100 + (x2 + x5 + x8) * 10 + x3 + x6 + x9 == 1953) {
											++tot;
											if (tot < 10)
												printf("No.  %d : %d+%d+%d=1953\n", tot, x1 * 100 + x2 * 10 + x3, x4 * 100 + x5 * 10 + x6, x7 * 100 + x8 * 10 + x9);
											else if (tot < 100)
												printf("No. %d : %d+%d+%d=1953\n", tot, x1 * 100 + x2 * 10 + x3, x4 * 100 + x5 * 10 + x6, x7 * 100 + x8 * 10 + x9);
											else
												printf("No.%d : %d+%d+%d=1953\n", tot, x1 * 100 + x2 * 10 + x3, x4 * 100 + x5 * 10 + x6, x7 * 100 + x8 * 10 + x9);
										}
										++ x9;
									}
									++ x8;
								}
								++ x7;
							}
							++ x6;
						}
						++ x5;
					}
					++ x4;
				}
				++ x3;
			}
			++ x2;
		}
		++ x1;
	}
	printf("total=%d\n", tot);
	return 0;
}
