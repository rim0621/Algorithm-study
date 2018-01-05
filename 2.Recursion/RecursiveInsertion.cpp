#include<bits/stdc++.h>
using namespace std;

void insert(int data[],int size,int value)
{
	if(size==0)
	  data[size]=value;
	else
	{
	  if(data[size-1]<value)
		data[size]=value;
	  else
	  {
		data[size]=data[size-1];
		insert(data,size-1,value);
	  }
	}
}


int main()
{
	int data[]={0,1,3,5,6,8,9};
	int dataSize=10;
	insert(data,dataSize,2);
	insert(data,dataSize,7);
	insert(data,dataSize,4);
	
	for(int i=0;i<dataSize;i++)
		cout<<data[i]<<" ";
	cout<<endl;
	return 0;
}
