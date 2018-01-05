#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int original[1<<21];
int max_node[1<<21];
int min_sum[1<<21];

int main()
{	
	int numcase;
	cin>>numcase;
  for(int num=0;num<numcase;num++){
	int level=0;
	cin>>level;
	for(int i=2;i<=(1<<level+1)-1;i++)
	{
		scanf("%d",&original[i]);
	}
	
	for(int i=(1<<level);i>0;i--)
	{			
		max_node[i]=max(max_node[i+i]+original[i+i],max_node[i+i+1]+original[i+i+1]);
		min_sum[i]=min_sum[i+i]+min_sum[i+i+1]+max_node[i]-max_node[i+i]+max_node[i]-max_node[i+i+1];
	}
	for (int a=1;a<(1<<level);a++)
       {
        	cout<<min_sum[a]<<"  "<<a<<endl;
       } 	
 }

	
	return 0;
}

