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
int countCoinExchange(int *coin,int numDiffCoins,int change)
{	//numD=동전종류  change= 거스름돈
	int numComb;
	int N[101][1001];
	for(int i=numDiffCoins;i>0;i--)
		coin[i]=coin[i-1];

	coin[0]=0;
	memset(N,0,sizeof(N));
	for(int i=0;i<=numDiffCoins;i++)
		N[i][0]=1;
	for(int i=1;i<change;i++)
		N[0][i]=0;
	for(int i=1;i<=numDiffCoins;i++)
	{
		for(int j=1;j<=change;j++)
		{
			if(j-coin[i]<0)		//???
				numComb=0;
			else
				numComb=N[i][j-coin[i]];
			N[i][j]=N[i-1][j]+numComb; //??
		}
	}
	for(int i=0;i<=numDiffCoins;i++)
	{
		for(int j=0;j<=change;j++)
		{
			cout<<N[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return N[numDiffCoins][change];

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
	cout<<"==============경우의수=============="<<endl;
	cout<<"개수:"<<countCoinExchange(coin, n,money)<<endl;
	
	return 0;	
}
