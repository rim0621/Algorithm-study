#include<bits/stdc++.h>
using namespace std;
void fixheap(int *input,int n,int j)
{
    int parent=input[j];
   
     while(parent>min(input[j*2],input[j*2+1]) &&( j*2<=n || j*2+1<=n))
    {
       cout<<parent <<" "<<input[j*2]<<" "<<input[j*2+1]<<endl;
       int child;
       if(input[j*2+1] == 0||input[j*2]<input[j*2+1])
       {
              child=0;//l
       }
       else
       {
             child=1;//r
       }
       if(child==0 && input[j*2]<parent)
       {
          input[j]=input[j*2];
          input[j*2]=parent;
          parent=input[j*2];
         j=j*2;
       }
        else if(child==1 && input[j*2+1]<parent)
        {
           input[j]=input[j*2+1];
           input[j*2+1]=parent;
           parent=input[j*2+1];
           j=j*2+1;
        }

    }

}

int main()
{
	int n=11;
	int input[11]={0,3,5,2,7,11,6,8,14,1,4};
	for(int i=1;i<n;i++)
		cout<<input[i]<<" ";
	cout<<endl;
	for(int i=n/2;i>0;i--)
	{
		fixheap(input,n,i);
	}
	for(int i=1;i<n;i++)
		cout<<input[i]<<" ";
	cout<<endl;

	return 0;
}
