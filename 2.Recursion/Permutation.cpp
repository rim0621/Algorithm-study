#include<bits/stdc++.h>
using namespace std;
void permuteString(string str,int begin,int end)
{

	int range=end-begin;
	if(range==1)
		cout<<str<<endl;
	else
	{
		for(int i=0; i<range;i++)
		{
			swap(str[begin],str[begin+i]);
			permuteString(str,begin+1,end);
			swap(str[begin],str[begin+i]);// 바껴있으니깐 다음 껄 위해새 다시 원상복귀.
		}
	}
}


int main()
{
	string str="abcd";
	permuteString(str,0,str.size());
}
