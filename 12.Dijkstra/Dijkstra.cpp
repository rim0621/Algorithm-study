#include<iostream>
#include <deque>
#include<string.h>
#include<algorithm>
#define INF 1e9
using namespace std;
int D[50];
int E[50][50];

void Dijkstra(deque<int> order,int numberOfV);

int main()
{
	int n,m;
	cout<<"number of v : ";	cin>>n;
	cout<<"number of e:  "; cin>>m;

	//연결 안되있는 것은 무한대로 초기화
	
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<=50;j++)
		{
			E[i][j]=INF;
		}
		D[i]=INF;
	}



	//연결되있는
	int node1,node2,w;
	cout<<"connect node and weight : "<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>node1>>node2>>w;
		E[node1][node2]=w;
		E[node2][node1]=w;
	}
	deque<int> q;
	for(int i=1;i<=n;i++)
	{
		q.push_back(i);
	}
	Dijkstra(q,n);
	return 0;
}

void Dijkstra(deque<int> order,int n)
{
	deque<int> q=order;

	//시작점 선택
	int selectNode=q.front();

	//첫번째 D세팅
	for(int i=1;i<=n;i++)
	{
		D[i]=E[selectNode][i];
	}
	
	while(!q.empty())
	{
		//최소값 노드
		int min_Node,min_Value=INF;
			
                q.erase(find(q.begin(),q.end(),selectNode)); // 한번 썻던 노드는 다시 않함으로 삭제

		// 최소구하기
		for(deque<int>::size_type i=0;i<q.size();++i)
		{
			D[q[i]]=min(D[q[i]],D[selectNode]+E[selectNode][q[i]]);

			//다음 번의 기준이 될노드
			if(D[q[i]]<min_Value)
			{
				min_Node=q[i];
				min_Value=D[q[i]];
			}
		}
		
		selectNode=min_Node;	

	}	
	
	for(int i=1;i<=n;i++)
	{
		cout<<D[i]<<" ";
	}
	cout<<endl;

}
