#include<bits/stdc++.h>
using namespace std;

int t[10005];

int main()
{
	int n;
	scanf("%d",&n);
	for( int num=0;num<n;num++)
	{
		int number;
		scanf("%d",&number);
		for(int i=2;i<=number;i++)
		{
			t[i]=i;
		}

		for(int i=2; i<=number;i++)
		{
			if(t[i]==0)
				continue;
			for(int j=i+i;j<=number;j+=i)
			{
				t[j]=0;
			}
		}


		int i=number/2;
		int j=number/2;
		while(1<i || j>number+1)
		{
			if(t[i]+t[j]==number)
			{
				break;
			}
			else if(t[i]+t[j]==0)
			{
				j++;
				i--;
			}
			else if(t[i]==0)
			{
				i--;
			}
			else if(t[j]==0)
			{
				j++;
			}
			else if(t[i]+t[j]<number)
			{
				j++;
			}
			else if(t[i]+t[j]>number)
			{
				i--;
			}
		}

		cout<<t[i]<<" "<<t[j]<<endl;
	}

	return 0;
}
