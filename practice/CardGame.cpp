#include<bits/stdc++.h>

using namespace std;


int win(deque<int> card,deque<int>::iterator start,deque<int>::iterator back)
{
	int m;
	if(card.size()%2==1&&start==back)
	{
		return *start;
	}
	else if(card.size()%2==0&&start>back)
	{
		return 0;
	}
	m=max(*start+win(card,start+2,back),*back+win(card,start,back-2));
	
	return m;
}


int main()
{
	int numCase;
	scanf("%d",&numCase);
	for(int num=0;num<numCase;num++)
	{
		int n_card,number;
		int myScore=0;
		scanf("%d",&n_card);
		deque<int> card;
		
		for(int i=0;i<n_card;i++)
		{
			scanf("%d",&number);
			card.push_back(number);
		}
		deque<int>::iterator start=card.begin();
		deque<int>::iterator end=card.end()-1;
		
		myScore=win(card,start,end);
		
		cout<<myScore<<endl;

	}
	return 0;

}


