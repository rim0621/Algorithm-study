#include<bits/stdc++.h>
using namespace std;

int number[12];

int  divied(int n)
{
	memset(number,0,sizeof(number));
	int i=0;
	while(n!=0)
	{
		number[i]=n%10;
		n=n/10;
		i++;
	}
	return i;
}
int findHappyNumber(int i)
{
	int n=0;
	for(int j=0;j<i;j++)
	{
		n+=pow(number[j],2);
	}
	return n;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int x=0;x<tc;x++){
		int n,count;
		int flag=0;
		scanf("%d",&n);
		set<int> s;
		set<int>::iterator iter;
		while(n!=1){
			s.insert(n);
			count=divied(n);
			n=findHappyNumber(count);
			iter=s.find(n);
			if(iter!=s.end())
			{
				printf("UNHAPPY\n");
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("HAPPY\n");
		}
	}
	return 0;
}
