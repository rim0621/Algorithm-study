#include<bits/stdc++.h>
using namespace std;
void PrintBracket(bool *state,int size)
{
	for(int i=1;i<size;i++)
	{
		if(state[i])
		{
			cout<<"(";
		}
		else
		{
			cout<<")";
		}
	}
	cout<<endl;
}
void Bracket(bool *state, int size,int start, int end)
{
	if(start==0&&end==0)
	{
		PrintBracket(state,size);
		return ;
	}
	if( start>0){
		state[size]=true;
		Bracket(state,size+1,start-1,end+1);
	}
	if(end>0){
		state[size]=false;
		Bracket(state,size+1,start,end-1);
	}
}

int main()
{
	int n;
	cin>>n;
	bool state[2*100];
	Bracket(state,1,n,0);
	return 0;
}
