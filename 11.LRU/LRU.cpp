#include<bits/stdc++.h>
using namespace std;

struct MemoryC{
	int use;
	string cityName;
	MemoryC()
	{
		this->use=0;
		this->cityName="";
	}
};
int getExecuteTime(int cacheSize, vector<char> cities)
{
	MemoryC cacheCity[31];
	int ans=0;
	
	if(cacheSize==0)
	{
		for(vector<char>::iterator iter=cities.begin();iter!=cities.end();iter++)
		{
			if(*iter==' ')
			{
				ans++;		
			}
		}
		return (ans+1) * 5;
	}

	int cacheFull=0;
	string name="";
	list<int> order(0,cacheSize);
	vector<char>::iterator iter=cities.begin();
	while(iter!=cities.end())
	{
		if(*iter!=' ')
		{
			name+=*iter;
			iter++;
			if(iter!=cities.end())
				continue;
		}
	

		if(cacheFull!=cacheSize)		//처음 캐시 채우는 부분
		{
			
			cacheCity[cacheFull].cityName=name;
			order.push_back(cacheFull);
			cacheFull++;
			ans+=5;
			name="";
	
		}
		else
		{
			for(list<int>::iterator i=order.begin();i!=order.end();i++)	//hit일경우
			{
				if(cacheCity[*i].cityName==name)
				{
					int tmp=*i;
					order.erase(i);
					order.push_back(tmp);
					ans+=1;
					name="";
					break;
				}
			}
			if(name!="")			//miss일 경우
			{
				int tmp=order.front();
				order.pop_front();
				cacheCity[tmp].cityName=name;
				order.push_back(tmp);
				name="";
				ans+=5;
			}
			
		}
		if(iter!=cities.end())
			iter++;
	}
	return ans;
}

int main()
{
	
	string input;
	getline(cin,input);

	int cacheSize=input[0]-48;
	vector<char> cities;
	for(int i=2;i<input.size();i++)	//입력 맞추기
	{
		if(input[i]==' ' || (input[i]>='A' && input[i]<='z')){

			if(input[i]>='a')
			{
				cities.push_back(input[i]-'a'+'A');
			}
			else
				cities.push_back(input[i]);

		}
	}

	cout<<getExecuteTime(cacheSize,cities)<<endl;
		
	return 0;
}	
 
