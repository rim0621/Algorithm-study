#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

class Locations
{
	int h,o;
 public:
	explicit Locations (int tmp_h ,int tmp_o)
	{
		if(tmp_h>tmp_o)
		{
			this->h=tmp_o;
			this->o=tmp_h;
		}
		else
		{
			this->h=tmp_h;
			this->o=tmp_o;
		}

	}
	int  getH() const {return h;}
	int  getO() const {return o;}
};

vector<Locations> FindCondinate(vector<Locations> lo, int d)
{	
	vector<Locations>::iterator iter=lo.begin();

	while(iter!=lo.end())
	{
		if(!(abs((*iter).getO()-(*iter).getH())>d))
			iter++;
		else
			lo.erase(iter);
	}
	return lo;

}
bool lessH(const Locations& left, const Locations& right)
{
	return left.getH()<right.getH();
}


int findMax(vector<Locations> lo,vector<Locations>::iterator iter_tmp,int d)
{
	int count=0;
	vector<Locations>::iterator iter=lo.begin();
	
//	cout<<"========================="<<endl;
//        cout<<"L: "<<(*iter_tmp).getH()<<" "<<(*iter_tmp).getH()+d<<endl;

		while(iter!=lo.end())
		{
	 		if((*iter_tmp).getH()<=(*iter).getH() && (*iter_tmp).getH()+d>=(*iter).getO())
			{
				count++;
//				cout<<(*iter).getH()<<","<<(*iter).getO()<<" c:"<<count<<endl;
			}
			iter++;
		}
	
	return count;
	
}

int main()
{
	int numCase;
	cin>>numCase;
	
	for(int num=0;num<numCase;num++)
	{
		vector<Locations> lo;
		int o,h,n,d;
		int anwser=0;
		int pre=NULL;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
	                scanf("%d %d",&h,&o);
        	        lo.push_back(Locations(h,o));
		}
		scanf("%d",&d);	
		lo=FindCondinate(lo,d);
		sort(lo.begin(),lo.end(),lessH);
		if(lo.empty())
		{
			cout<<"0"<<endl;
		}
		else
		{	
			for(vector<Locations>::iterator iter=lo.begin();iter!=lo.end();++iter)
			{
				if(pre!=(*iter).getH())
				{
					anwser=max(anwser,findMax(lo,iter,d));
					pre=(*iter).getH();
				}	
			}		
			printf("%d\n",anwser);
		}

	}

	
	return 0;
}

