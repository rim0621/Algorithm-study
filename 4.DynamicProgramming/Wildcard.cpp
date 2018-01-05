#include<bits/stdc++.h>
using namespace std;

bool match(const string& w, const string &s)
{
	int pos=0;
	while(pos<s.size() && pos < w.size() && (w[pos]=='?' || w[pos]==s[pos]))
	{
		++pos;
	}
	if(pos==w.size())
		return pos==s.size();	//끝에 도달해서 끝난 경우 대응.
	if(w[pos]=='*') // 뒷 문자들 확인해봐야....
	{
		for(int skip=0;pos+skip<=s.size();++skip)
		{
			if(match(w.substr(pos+1),s.substr(pos+skip)))
				return true;
		}
	}
	return false;
}


int main()
{
	string w,s;
	cin>>w;
	int n;
	cin>>n;
	vector<string> input;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		input.push_back(s);
	}

	for(int i=0;i<n;i++)
	{
		if(match(w,input[i]))
		{
			cout<<input[i]<<endl;
		}
	}
	
	return 0;
	
	
}
