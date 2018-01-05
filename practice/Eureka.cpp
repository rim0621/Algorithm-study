#include<bits/stdc++.h>
using namespace std;


int t[100];

int f(int number)
{
	int an=0;
            for(int i=1;i<44;i++)
             {
                     for(int j=1;j<44;j++)
                     {
                             for(int k=1;k<44;k++)
                               {
                                        if(number==t[i]+t[j]+t[k])
                                        {
                                                an=1;
                                                return an;
                                        }
                                }
                        }
                }

	return an;
}

int main()
{
	for(int i=1;i<=44;i++)
	{
		t[i]=t[i-1]+i;
	}


	int testCase;
	cin>>testCase;
	for(int num=0;num<testCase;num++)
	{
		int number;
		cin>>number;

		cout<<f(number)<<endl;
	}
	return 0;
}
