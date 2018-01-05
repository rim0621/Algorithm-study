#include<bits/stdc++.h>

void Hanoi(int n, int a, int b, int c)
{
	if(n>0)
	{
		Hanoi(n-1,a,c,b);
		printf("move from %d to %d\n",a,c);
		Hanoi(n-1,b,a,c);
	}
}

int main()
{
	int numDisks=5;
	Hanoi(numDisks,1,2,3);

}
