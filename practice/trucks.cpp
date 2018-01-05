#include<iostream>
#include<numeric>
#include<deque>
using namespace std;
int main()
{
	int num_Case;
	cin>>num_Case;
	for(int num=0;num<num_Case;num++)
	{
		int truck_num,bridge_len,bridge_max,weight;
		int anwser=0,flag=1;
		deque<int> trucks;
		cin>> truck_num >> bridge_len >> bridge_max;
	 	deque<int> bridge(bridge_len,0);
		deque<int>::iterator iter;
		for(deque<int>::size_type i=0;i<truck_num;++i)
		{
			cin>>weight;
			trucks.push_back(weight);
		}
		while(!bridge.empty())
		{
                        
			if(trucks.empty())
                        {
                                bridge.pop_front();
                        }
			else if(accumulate(bridge.begin(),bridge.end(),0)+trucks[0]-bridge[0]<=bridge_max)
			{	
				iter=trucks.begin();
				bridge.pop_front();
				bridge.push_back(*iter);
				trucks.pop_front();
			}
			else
			{
                                bridge.pop_front();
                                bridge.push_back(0);

			}
			anwser++;
		}

		
		
		cout<<anwser<<endl;
		
	}
	return 0;
}
