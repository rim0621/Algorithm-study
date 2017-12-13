#include<bits/stdc++.h>
#define MAX_S 100
using namespace std;


int DFA[3][MAX_S];
char p[MAX_S];
char input[MAX_S];
int wordToInt(char state)
{
	if(state=='a')
		return 0;
	if(state=='b')
		return 1;
	if(state=='c')
		return 2;

}
void constructDFA(int size)
{

	int x=0;
        for(int i=0;i<size+1;i++)
        {
                for(int j=0;j<3;j++)
                {
                         DFA[j][i]=DFA[j][x];

   		}
	        x=DFA[wordToInt(p[i])][x];
		if(size-1>=i){
                	DFA[wordToInt(p[i])][i]=i+1;
		}
		
        }

}
int findDFA(int msize,int nsize)
{
        for(int i=0;i<3;i++)
        {
                for(int j=0;j<nsize+1;j++)
                        cout<<DFA[i][j]<<" ";
                cout<<endl;
        }


  int tmp=0;
  for(int i=0;i<msize+1;i++)
  {
    	if(tmp==nsize)
     	{
		return 1;
     	}
        int a=DFA[wordToInt(input[i])][tmp];    //word, state
	tmp=a;
	cout<<a<<endl;
  }
	cout<<endl;
	return 0;
}
int main()
{
	cout<<"pattern n:";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	cout<<"string: ";
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>input[i];
	} 
	constructDFA(n);
 	cout<<findDFA(m,n)<<endl;
	return 0;
}


