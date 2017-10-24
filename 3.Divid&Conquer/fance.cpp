#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &h,int left,int right)
{
	if(left==right) return h[left];
	int mid=(left+right)/2;
	int ret=max(solve(h,left,mid),solve(h,mid+1,right));
	int lo=mid,hi=mid+1;
	int height=min(h[lo],h[hi]);
	ret=max(ret,height*2);
	while(left<lo || hi < right)
	{
		if(hi<right &&(lo==left||h[lo-1]<h[hi+1])){
			++hi;
			height=min(height,h[hi]);
		}
		else
		{
			--lo;
			height=min(height,h[lo]);
		}
		ret=max(ret,height*(hi-lo+1));
		
	}
	return ret;
}

int main()
{
	int n;
	int input;
	vector<int> height;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input);
		height.push_back(input);
	}
	cout<<solve(height,0,n)<<endl;
	return 0;
}
