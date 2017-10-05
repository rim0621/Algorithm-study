#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>
using namespace std;

struct Locations
{
        int h,o;
};


bool GreaterO(const Locations& left, const Locations& right)
{
	return left.o<right.o;
}
int main()
{
	Locations lo[100009];
	int numCase;
	int size=0;
	scanf("%d",&numCase);
	
	for(int num=0;num<numCase;num++)
	{
		int o,h,n,d;
		int anwser=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
	                scanf("%d %d",&h,&o);
			if(h>o)
			{
				lo[i].h=o;
				lo[i].o=h;
			}
			else
			{
        	        	lo[i].h=h;
				lo[i].o=o;
			}
		}
		cin>>d;	
		sort(lo,lo+n,GreaterO);
		cout<<"sort"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<lo[i].h<<" "<<lo[i].o<<endl;
		}

   				
		priority_queue<int> q;	
		for(int i=0;i<n;i++)
		{	

			q.push(-lo[i].h);
			while(!q.empty() && -q.top() < lo[i].o-d)
			{
				cout<<q.top()<<endl;
				q.pop();
			}
			size=q.size();
			anwser=max(anwser,size);
		}
		

		
		printf("%d\n",anwser);

	}
	return 0;
}	
