#include<bits/stdc++.h>
using namespace std;
int INF=999;
int SWITCH=10;
int CLOCKS=16;
const char linked[10][17]={
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."

};

bool check12(vector<int>& clock)
{	
	for(vector<int>::size_type i=0;i<clock.size();++i)
	{
		if(clock[i]!=12)
		{
			return false;
		}
	}
	return true;
}
void pushSwtch(vector<int>& clocks,int swtch){
	for(int c=0;c<CLOCKS;c++)
	{
		if(linked[swtch][c]=='x'){		
			clocks[c]+=3;
			if(clocks[c]==15) clocks[c]=3;
		}
	}
}
int solveSwtch(vector<int>& clocks,int swtch)
{
	if(swtch==SWITCH) 
		return check12(clocks) ? 0 : INF;
	int ret=INF;
	for(int cnt=0;cnt<4;++cnt)
	{
		ret=min(ret,cnt+solveSwtch(clocks,swtch+1));
		pushSwtch(clocks,swtch);
	}
	return ret;
	
}

int main()
{
	int input;
	vector<int> clock;
	for(int i=0;i<16;i++)
	{
		scanf("%d",&input);
		clock.push_back(input);
	}

	printf("%d",solveSwtch(clock,0));
	return 0;

}
