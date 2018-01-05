#include<bits/stdc++.h>
using namespace std;

int m[10000][10000];
int d[10000];


int main()
{	
	int n;//node_c
	cin>> n;
	int c;
	cin>>c;
	cout<<"---"<<endl;
	for(int i=0;i<c;i++)
	{
		int node1,node2,cost;
		cin>>node1>>node2>>cost;
		m[node1][node2]=cost;
	}	
	set<int> s;
	deque<int> q;
	for(int i=1;i<=n;i++)
	{
		q.push_back(i);
	}

	//0인 것 은 무한대로(999)
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(m[i][j]==0)
			{
				m[i][j]=999;
			}
		}

	}

	int prenode;
	int min_c=999;
        int node=q.front();
        q.pop_front();
	s.insert(node);
        for(int i=1;i<=n;i++)
        {
		d[i]=m[1][i];
        }
	for(int i=1;i<=n;i++)
	{
                if(min_c>d[i])
                {
			cout<<d[i]<<endl;
                        min_c=d[i];
                        node=i;
                }

	}

	while(!q.empty())
	{
		min_c=999;
		// 큐 확인하기
		for(deque<int>::size_type i=0;i<q.size();++i)
			cout<<q[i]<<" ";
		cout<<endl;
		s.insert(node);
		q.erase(find(q.begin(),q.end(),node));	
			        
		for(deque<int>::size_type i=0;i<q.size();++i)
        	{
                	d[q[i]]=min(d[q[i]],d[node]+m[node][q[i]]);
        	}
		for(deque<int>::size_type i=0;i<q.size();++i)
		{
                        if(min_c>d[q[i]])
                        {
                                min_c=d[q[i]];
                                node=q[i];
                        }

		}
	}
	for(set<int>::iterator iter=s.begin();iter!=s.end();++iter)
		cout<<*iter<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}
	cout<<endl;

	return 0;

}

/*
int m[7][7];
int d[7];
int main()
{	

	m[1][2]=10;
	m[1][3]=30;
	m[1][4]=15;
	m[2][5]=20;
	m[3][6]=5;
	m[4][3]=5;
	m[4][6]=20;
	m[5][6]=20;
	m[6][4]=20;
	vector<int> s;
	deque<int> q;

	for(int i=1;i<7;i++)
	{
		q.push_back(i);
	}

	//0인 것 은 무한대로(999)
	for(int i=1;i<7;i++)
	{
		for(int j=1;j<7;j++)
		{
			if(m[i][j]==0)
			{
				m[i][j]=999;
			}
		}

	}
	int prenode;
	int min_c=999;
        int node=q.front();
        q.pop_front();
	s.push_back(node);
        for(int i=1;i<7;i++)
        {
		d[i]=m[1][i];
        }
	for(int i=1;i<7;i++)
	{
                if(min_c>min(min_c,d[i]))
                {
                        min_c=min(min_c,d[i]);
                        node=i;
                }

	}
	while(!q.empty())
	{
		min_c=999;
		// 큐 확인하기
		for(deque<int>::size_type i=0;i<q.size();++i)
			cout<<q[i]<<" ";
		cout<<endl;
		s.push_back(node);
		q.erase(find(q.begin(),q.end(),node));	
			        
		for(deque<int>::size_type i=0;i<q.size();++i)
        	{
                	d[q[i]]=min(d[q[i]],d[node]+m[node][q[i]]);
        	}
		for(deque<int>::size_type i=0;i<q.size();++i)
		{
                        if(min_c>min(min_c,d[q[i]]))
                        {
                                min_c=min(min_c,d[q[i]]);
                                node=q[i];
                        }

		}
	}
	for(vector<int>::iterator iter=s.begin();iter!=s.end();++iter)
		cout<<*iter<<" ";
	cout<<endl;
	for(int i=1;i<7;i++)
	{
		cout<<d[i]<<" ";
	}
	cout<<endl;

	return 0;

}
*/



/*
#include <stdio.h>
 
#define N 100
#define INF 100000
 
int a[N+1][N+1];
int visit[N+1];
int dist[N+1];
int start, end;
int n,m;
 
// input 값 sample
// 첫번째 라인에는 정점의 개수, 그리고 시작 정점, 도착 정점이 입력
// 두번째 라인에는 정점별 간선의 입력받을 가중치의 개수(m)가 입력된다.
// 세번째 라인부터는 정점별 간선의 입력받을 가중치가 m번이 들어온다.
 

 
 
void input()
{
        int i,j;
        int from,to;
        int w;
        scanf("%d %d %d",&n,&start,&end);
        scanf("%d",&m);
 
        // 각 정점으로 가는 간선의 가중치를 무한대로 초기화한다.(최소값을 구하기위해)
        for ( i =1;i <=n; i++)
                for ( j =1; j <=n; j++)
                        if ( i!= j)
                                a[i][j] = INF;
       
        for ( i =1;i <= m; i++) // 정점에서 정점으로 가는 간선의 가중치가 입력
        {
                scanf("%d %d %d",&from,&to,&w);
                a[from][to] =w;
        }
 
        for ( i =1;i <=n; i++)
                dist[i] = INF;
               
}
 
void dijkstra()
{
        int i,j;
        int min;
        int v;
 
        dist[start] = 0;        // 시작점의 거리 0
 
        for ( i =1;i <=n; i++)
        {
                min = INF;
               
                for ( j =1 ; j <=n; j++)
                {
                        if ( visit[j] == 0 && min > dist[j])    // 갈수 있는 정점중에 가장 가까운 정점 선택
                        {
                                min = dist[j];
                                v = j;
                        }
                }
 
                visit[v] = 1;   // 가장 가까운 정점으로 방문, i정점에서 가장 가까운 최단경로 v
       
                for ( j = 1;j <= n; j++)      
                {
                        if ( dist[j] > dist[v] + a[v][j])       // 방문한 정점을 통해 다른 정점까지의 거리가 짧아지는지 계산하여 누적된값 저장
                                dist[j] = dist[v] + a[v][j];
                }
        }
}
 
 
int main(void)
{
        input();
        dijkstra();
        printf("%d \n",dist[end]);
        return 0;
}




*/
