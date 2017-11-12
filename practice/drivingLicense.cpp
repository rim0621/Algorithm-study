#include<bits/stdc++.h>
using namespace std;
int v[103];
int h[103];
char direct[103];

int main()
{
	int m,n,l,g;
	scanf("%d %d %d %d",&m,&n,&l,&g);
	for(int i=1;i<=m*(n-1);i++)
	{
		scanf("%d",&h[i]);	
	}
	for(int i=1;i<=n*(m-1);i++)
	{
		scanf("%d",&v[i]);
	}
	int x=m*(n-1);
	int y=n*(m-1);
	int c=m+n-2;
	int sum=0;
	while(c!=0)
	{
		if(h[x]<v[y])
		{
			cout<<h[x]<<" ";
			sum+=h[x];
			direct[c]='h';
			x--;
			y--;
			
		}
		else if(h[x]>v[y])
		{
			cout<<v[y]<<" ";
			sum+=v[y];
			direct[c]='v';
			y-=n;
			x=x+1-n;
		}
		else
		{
			if(direct[c+1]=='h')
			{
				cout<<h[x]<<" ";
				sum+=h[x];
				direct[c]='h';
				x--;
				y--;		
			}
			else
			{
				cout<<v[y]<<" ";
				sum+=v[y];
				direct[c]='v';
				y-=n;
				x=x+1-n;
			}
		}
		c--;
	}
	int k=0;
	for(int i=1;i<m+n-2;i++)
	{
		if(direct[i]!=direct[i+1])
			k++;
	}
	cout<<sum<<endl;
	if(sum>g)
		cout<<"-1"<<endl;
	else	
		cout<<(n+m-2)*l+k<<endl;
}
