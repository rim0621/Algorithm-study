#include<bits/stdc++.h>
using namespace std;

bool f(int d[],int n)
{
	int number=1;
	int i=1;
	int c=0;
	int dd=d[1];
	while(number<1000)
	{
		

                if(n==i)
                {
			d[i]=abs(d[i]-dd);
			dd=d[1];
	                for(int j=1;j<=n;j++)
        	        {
                	        if(d[j]==0)
                        	{
                                	c++;
                        	}
		                if(c==n)
        		        {
                        		return true;
                		}

                	}

                        i=1;
                        c=0;
                }
		else
		{
	                d[i]=abs(d[i]-d[i+1]);


                	i++;
                	number++;

		}
		

		
	}
	


	return false;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int num=0;num<tc;num++)
	{
		int d[16];
		memset(d,0,sizeof(d));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&d[i]);
		}

		if(f(d,n))
			cout<<"ZERO"<<endl;
		else
			cout<<"LOOP"<<endl;
	}
}
