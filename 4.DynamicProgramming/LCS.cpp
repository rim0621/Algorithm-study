#include<bits/stdc++.h>
using namespace std;

#define MAX_LENGTH 101
#define MAX(a,b) ((a)>(b)?(a):(b))

int L[MAX_LENGTH][MAX_LENGTH];
int  S[MAX_LENGTH][MAX_LENGTH]; //0으로 초기화
// L[][]은 sm 그리고 tm의 최장길이를 저장... S[][]는 LCS를 구하기 위한 저장 정보... 
int lengthLCS(string s,string t, int m, int n)
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			{
				L[i][j]=L[i-1][j-1]+1; // 대각선으로 부터 +1 //2번째 경우
				S[i][j]=0;
			}
			else
			{
				L[i][j]=MAX(L[i][j-1],L[i-1][j]);
				if(L[i][j]==L[i][j-1])
					S[i][j]=1;	//위에서	
				else
					S[i][j]=2;	//옆에서
			}
		}
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	return L[m][n];
}
void printLCS(string s,string t,int m,int n)
{
	if(m==0 || n==0)
		return ;
	if(S[m][n]==0)
	{
		printLCS(s,t,m-1,n-1);
		printf("%c ",s[m-1]);
	}
	else if(S[m][n]==1)
		printLCS(s,t,m,n-1);
	else if(S[m][n]==2)
		printLCS(s,t,m-1,n);
}
int main()
{
	string s,t;
	cin>> s>> t;
	if(s.size()>t.size())
	{
		string tmp=s;
		s=t;
		t=tmp;
	}
	int length=lengthLCS(s,t,s.size(),t.size());
	cout<<"최대 길이: "<<length<<endl;
	cout<<"추적: ";
	printLCS(s,t,s.size(),t.size());
	cout<<endl;
	return 0;
}
