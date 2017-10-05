#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int v[999999];
int main()
{
	int testCase;
	scanf("%d",&testCase);
	for(int num=0;num<testCase;num++)
	{
		int n,a,m;
		int cnt=0;
		scanf("%d %d",&n,&a);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		sort(v,v+n);
		int s=0;
		int e=n-1;
		m=abs(a-(v[0]+v[n-1]));
		while(!(e<=s))
		{
			if(m==abs(a-(v[s]+v[e])))
			{
				cnt++;
			}
			else if(m>abs(a-(v[s]+v[e])))
			{	
				m=abs(a-(v[s]+v[e]));
				cnt=1;
			}
			
				if(v[s]+v[e]>a)
				{
					e--;	
				}
				else
					s++;
					
			

		}
		printf("%d\n",cnt);


	}
	return 0;
}
