#include<bits/stdc++.h>
using namespace std;
//모두 연결되어있는 그래프... 
//전체 간선에 대하여 가장 작은 가중치를 갖는 간선부터 차례로 최소비용 그래프에 붙이고, 삽입된 간선의 개수가 정점의 개수보다 1만큼 작아지면 최소비용그래프 종료
//미리.. 사이클 생기는 곳을 알아야 되듯..
int main()
{
	int c[]={4,2,10,7,12,15,18,20,9,13,8}; 
	int CYCLE[]={0,0,0,0,0,1,0};//1  사이클이 생기므로...
	int N=7; //node
	int E=11; // edge
	int tmp;

	cout<<"-----start-----"<<endl;
	for(int i=0;i<E;i++)
		cout<<c[i]<<" ";
	cout<<endl;

	for(int i=0;i<E-1;i++)	//내림차순 정렬
	{
		for(int j=i+1;j<E;j++)
		{
			if(c[i]>c[j])
			{
				tmp=c[i];
				c[i]=c[j];
				c[j]=tmp;
			}
		}
	}
	cout<<"-----chage-----"<<endl;
	for(int i=0;i<E;i++)
		cout<<c[i]<<" ";
	cout<<endl;

	int L=1;
	int K=0;
	int T=0;
	cout<<"-----make-----"<<endl;
	while(L<=(N-1)){		//
		if(CYCLE[K]==0)
		{
			cout<<c[K]<<" ";
			T=T+c[K];
			L+=1;
		}
		K+=1;
	}
	cout<<endl;
	cout<<"sum= "<<T<<endl;
	return 0;
}
