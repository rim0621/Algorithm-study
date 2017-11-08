#include<bits/stdc++.h>
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
	
	if(cache[i][j]!=0)
		return cache[i][j];

	cache[i][j]=999999999;
	for(int start=i; start<=j-1;start++)
	{
		cache[i][j]=min(cache[i][j],mergeFile(i,start)+mergeFile(start+1,j)+sum[j]-sum[i-1]);
	}
	return cache[i][j];
}

int main()
{
	int numCase;
	scanf("%d",&numCase);
	for(int excute=0;excute<numCase;excute++)
	{
		
		
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

