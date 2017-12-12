#include<bits/stdc++.h>
using namespace std;
int MIN(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	int a=13,b=11;
	cout<<MIN(a,b)<<endl;
	return 0;
}
