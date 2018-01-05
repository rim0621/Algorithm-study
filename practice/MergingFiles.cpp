#include<bits/stdc++.h>
#define INF 9999999
using namespace std;
int sum[502];
int cache[502][502];
int input[502];
int mergeFile(int i,int j)
{
	if(i>=j)
		return 0;
	if(i+1==j)
		return input[i]+input[j];
	int &ret = cache[i][j];	
	if(ret<INF)
		return ret;

	for(int start=i; start<=j-1;start++)
	{
		ret=min(ret,mergeFile(i,start)+mergeFile(start+1,j)+sum[j]-sum[i-1]);
	}
	return ret;
}

int main()
{
	int numCase;
	scanf("%d",&numCase);
	for(int excute=0;excute<numCase;excute++)
	{
		
		memset(cache,INF,sizeof(cache));
		int n;
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
		{
			scanf("%d",&input[i]);
			sum[i]=sum[i-1]+input[i];
		}

		printf("%d\n",mergeFile(1,n));
	}
	return 0;
}

