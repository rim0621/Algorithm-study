#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	
	int input[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>input[i];

	make_heap(input,input+n,greater<int>());
	for(int i=0;i<n;i++)
		cout<<input[i]<<" ";
	cout<<endl;

}
