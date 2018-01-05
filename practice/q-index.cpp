#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;


int main()
{
	int numCase;
	cin>>numCase;
	for(int num=0;num<numCase;num++)
	{
		int qindex,number;
		deque<int> dq;
		deque<int> tmp;
		cin>>qindex;
		for(int i=0;i<qindex;i++)
		{
			cin>>number;
			dq.push_back(number);
		}
 		sort(dq.begin(),dq.end(),greater<int>());
		deque<int>::reverse_iterator riter=dq.rbegin();
		int index=qindex;
		while(riter!=dq.rend())
		{
			if(*riter>=index)
			{
				cout<<index<<endl;
				break;
			}		
			else
			{
				index--;
				riter++;
			}		
		}
		if(riter==dq.rend())
			cout<<"0"<<endl;
	        		
	}	
	return 0;
}
