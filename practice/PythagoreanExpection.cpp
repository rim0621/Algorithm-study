#include<bits/stdc++.h>
using namespace std;



struct Team{
	int w,l;
	Team()
	{
		this->w=0;
		this->l=0;
	}
};


int f(Team t)
{	
	if(t.w==0 && t.l==0)
	{
		int s=0;
		return s;
	}
	float a=pow(t.w,2)/(pow(t.w,2)+pow(t.l,2))*1000;
	int b=a;
	return b;
}


int main()
{
	int tc;
	scanf("%d",&tc);
	for(int num=0;num<tc;num++)
	{
		Team t[1004];
		int weight[1004];
		int n,m,t1,t2,g1,g2;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d %d",&t1,&t2,&g1,&g2);
			t[t1].w+=g1;
			t[t1].l+=g2;
			t[t2].w+=g2;
			t[t2].l+=g1;
		
		} 
		
		for(int i=1;i<=n;i++)
		{
			weight[i]=f(t[i]);
		}
		sort(weight+1,weight+n+1);
		
		cout<<weight[n]<<endl;
		cout<<weight[1]<<endl;


	}
	return 0;
}
