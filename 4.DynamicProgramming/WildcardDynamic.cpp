#include<bits/stdc++.h>
using namespace std;

int cache[101][101];

bool matchMemoized(string &W, string &S,int w, int s)
{
	int& ret=cache[w][s];
	if( ret!=-1) return ret;
	
	while(s<S.size() && w< W.size() &&(W[w]=='?'||W[w]==S[s]))
	{
		w++;
		s++;
	}
	if(w==W.size()) return ret=(s==S.size());
	if(W[w]=='*')
	{
		for(int skip=0;skip+s<=S.size();++skip)
		{
			if(matchMemoized(W,S,w+1,s+skip))
				return ret=1;
		}
	}
	return ret=0;
}


int main()
{
	string W,S;
        cin>>W;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
		memset(cache,-1,sizeof(cache));
                cin>>S;
                if(matchMemoized(W,S,0,0))
                {
                        cout<<S<<endl;
                }
               
        }

        return 0;


}

