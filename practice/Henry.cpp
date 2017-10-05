#include <iostream>
#include <stdio.h>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	gcd(b, a%b);
}

int main() {
	int testCase;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int x;
		if (b%a == 0)
			cout << b / a << endl;
		else {
			while (a != 1) {
				int tmp = gcd(a, b);
				a /= tmp;
				b /= tmp;
				if (a == 1)
					break;
				x = b / a + 1;
				a = a*x - b;
				b = b*x;
			}
			cout << b << endl;
		}
	}
	return 0;
}
