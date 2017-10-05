#include<bits/stdc++.h>
using namespace std;

int f(int H,int W, int N)
{
	int i=1;
      for(int w=1;w<=W;w++)
      {
           for(int h=1;h<=H;h++)
           {
               if(i==N)
               {
                   return 100*(N-((w-1)*H))+w;
               }
		i++;	

           }
		
      }
}

int main()
{
	int testCase;
	scanf("%d",&testCase);
	for(int num=0;num<testCase;num++)
	{
		int H, W, N;
		scanf("%d %d %d",&H,&W,&N);
	
		cout<<f(H,W,N)<<endl;

	}
	return 0;
}
