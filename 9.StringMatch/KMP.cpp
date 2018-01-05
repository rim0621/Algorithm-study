#include<bits/stdc++.h>
using namespace std;

vector<int> getFail(string pattern)
{
  vector<int> fail(pattern.size(),0); //크기, 초기화0
  int j=0;
  for(int i=1;i<pattern.size();i++)
  {
     while(j > 0 && pattern[i]!=pattern[j])
        j = fail[j-1];
     if(pattern[i]==pattern[j])
 	fail[i]=++j;
    
  }
  return fail;
}

vector<int> kmp(string sentance, string pattern)
{
  int n = sentance.size();
  int m= pattern.size();
  vector<int> fail,ans;
  fail=getFail(pattern);
  int j=0;
  

  cout<<"fail check"<<endl;
  for(int i=0;i<fail.size();i++)
  {
    cout<<fail[i]<<" ";
  }
   cout<<endl;

  for(int i=0;i<n;i++)
  {
    while(j>0 && sentance[i] != pattern[j])
	j=fail[j-1];	//	j=pattern[j-1];
	
    if(sentance[i]==pattern[j])
    {
  	if(j==m-1)	//패턴이랑 길이가 똑같고 다 매칭될때
	{
	  ans.push_back(i-j);
	  j= fail[j];		//??
	}
	else
	   j++;
    }
  }
  return ans;
}

int main()
{
  string sentance;
  string pattern;
  cout<<"문장:";
  cin>>  sentance;
  cout<<"패턴:";
  cin>> pattern;
  vector<int> ans=kmp(sentance,pattern);
  for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
  cout<<endl;
  return 0;  
}
