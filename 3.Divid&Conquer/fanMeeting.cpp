#include<bits/stdc++.h>
using namespace std;



void addTo(vector<int>&a, const vector<int>& b, int k){
 
    int len = b.size();
    a.resize(max(a.size(), b.size() + k)); 
    
    for(int i = 0 ; i< len ; i++){
        a[i+k] += b[i];
        if(a[i+k] > 10){//올림
            a[i+k] -= 10;
            a[i+k+1] += 1;
        }
    }
}
 
//a -= b 를 구현한다. a >= b 를 가정한다.
void subFrom(vector<int>&a, const vector<int>& b){
 
    int len = b.size();
    a.resize(max(a.size(), b.size()) + 1);  
 
    for(int i = 0 ; i< len ; i++){
        a[i] -= b[i];
        if(a[i] < 0){//가져오기
            a[i] += 10;
            a[i+1] -= 1;
        }
    }
}
void normalize(vector<int>& num){
	num.push_back(0);
	for(int i=0;i<num.size();++i)
	{
		 if(num[i]<0){
			 int borrow=(abs(num[i])+9)/10;
			 num[i+1]-=borrow;
			 num[i]+=borrow*10;
		 }
		 else
		 {
			 num[i+1]+=num[i]/10;
			 num[i]%=10;
		 }
	}
	if(num.back()==0) num.pop_back();
}
vector<int> multiply(const vector<int>& a,const vector<int>& b)
{
	vector<int> c(a.size()+b.size()+1,0);
	for(int i=0;i<a.size();++i)
	{
		for(int j=0;j<b.size();++j)
		{
			c[i+j]+=a[i]*b[j];
		}
	}
	normalize(c);
	return c;
}
vector<int> karatsuba(const vector<int>& a,const vector<int>& b){
	int an= a.size(), bn=b.size();
	if(an<bn) return karatsuba(b,a);
	if(an==0||bn==0) return vector<int>();
	if(an<=50) return multiply(a,b);
	int half=an/2;
	vector<int> a0(a.begin(),a.begin()+half);
	vector<int> a1(a.begin()+half,a.end());
	vector<int> b0(b.begin(),b.begin()+min<int>(b.size(),half));
	vector<int> b1(b.begin()+min<int>(b.size(),half),b.end());

	vector<int> z2=karatsuba(a1,b1);
	vector<int> z0=karatsuba(a0,b0);
	addTo(a0,a1,0);
	addTo(b0,b1,0);
	vector<int> z1=karatsuba(a0,b0);
	subFrom(z1,z0);
	subFrom(z1,z2);
	vector<int> ret;
	addTo(ret,z0,0);
	addTo(ret,z1,half);
	addTo(ret,z2,half+half);
	return ret;
}

int hugs(const string& members, const string &fans)
{
	int n=members.size(), m=fans.size();
	vector<int> A(n),B(m);
	for(int i=0; i< n; ++i)
		A[i]=(members[i]=='M');
	for(int i=0;i<m;++i)
		B[m-i-1]=(fans[i]=='M');
	vector<int> C=karatsuba(A,B);
	int allHug=0;
	for(int i=n-1;i<m;++i){
		if(C[i]==0)
			++allHug;
	}

	return allHug;
}
int main()
{
	string members;
	string fans;
	cin>>members;
	cin>>fans;
	cout<<hugs(members,fans)<<endl;
	return 0;
}

