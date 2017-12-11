#include<bits/stdc++.h>
using namespace std;

void countCoin(int *coin, int *coinUsed,int *coinLast,int money,int n)
{
	coinUsed[0]=coinLast[0]=0;
	for(int k=1;k<=money;k++)
	{
		int minCoin=k;
		int newCoin=1;
		for(int i=0;i<n;i++)
		{
			if(coin[i]>k)
			{
				continue;
			}
			if(coinUsed[k-coin[i]]+1<minCoin)
			{
				minCoin=coinUsed[k-coin[i]]+1;
				newCoin=coin[i];
			}
		}
		coinUsed[k]=minCoin;
		coinLast[k]=newCoin;
	}
}
void reconstruct(int money,int *coinLast)
{
	if(money>0)
	{
		reconstruct(money-coinLast[money], coinLast);
		printf("%d ",coinLast[money]);
	}
}

int main()
{
	int n;
	int coin[10];
	cout<<"coin 개수:";
	scanf("%d",&n);
	int money;
	cout<<"돈1~500 :";
	cin>>money;
        cout<<"coin 종류:";
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	int coinUsed[500];
	int coinLast[500];

	countCoin(coin,coinUsed,coinLast,money,n);
	for(int i=0;i<=money;i++)
		cout<<coinUsed[i]<<" ";
	cout<<endl;
	for(int i=0;i<=money;i++)
		cout<<coinLast[i]<<" ";
	cout<<endl;

	cout<<"============동전 확인==============="<<endl;
	reconstruct(money,coinLast);
	cout<<endl;
	return 0;	
}
