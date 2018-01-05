#include<bits/stdc++.h>
#include<list>
using namespace std;
list<int> Number(int n,int number)
{
	
	list<int> l;
	while(number>0)
	{
		l.push_front(number%n);
		number=number/n;	
	}
	return l;
	
}
bool Palindrome(list<int> l)
{
	int i=0;
	list<int>::iterator start=l.begin();
	list<int>::iterator end=l.end();
	end--;	
	while(i<(l.size()/2)+1)
	{
		if(*start!=*end)
			return false;

		start++;
		end--;
		i++;
	}
	return true;
}
int main()
{
	int testCase;
	scanf("%d",&testCase);
	for(int num=0;num<testCase;num++)
	{
		int input;
		list<int> l;
		bool flag=1;
		scanf("%d",&input);
		for(int i=2;i<=64;i++)
		{
			l=Number(i,input);
			if(Palindrome(l)){
				cout<<"1"<<endl;
				flag=0;
				break;
			}	
			
		}
		if(flag)
		{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
