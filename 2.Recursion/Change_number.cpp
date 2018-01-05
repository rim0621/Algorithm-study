#include<bits/stdc++.h>
using namespace std;

void baseConversion(int n, int base)
{
	static char baseTable[]="0123456789abcdef";
	if(n>=base)
	  baseConversion(n/base,base);
	printf("%c",baseTable[n%base]);
}
main()
{
	int num=1234567;
	baseConversion(num,16); //16 진수
	printf("\n");
}
