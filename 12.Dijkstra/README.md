# 다익스트라 알고리즘 (Dijkstra Algorithm)

> 음의 가중치가 없는 그래프에서 한 노드에서 다른 모든 노드까지의 최단 거리를 구하는 알고리즘이다.

> O(v^2)의 복잡도 이지만 우선순위큐를 사용함으로 O(Elogv)의 시간 복잡도를 가지게 된다.

> E는 간선 v는 노드  // E => 최악의 경우 E번의 탐색한 노드를 집어 넣는 경우가 발생한다.

> 시작점에서 연결되있지 않은 노드도 무한대 크기만큼 연결되어있다가정하고 알고리즘을 수행한다.

* E[][] 는 간선들의 크기를 나타낸다.(그래프)

* D[]는 시작점에서 모든 정점을 가는 최소값을 가지게 된다.

* q는 시작점에서 q에 있는 정점들을 방분한다.

* **D[v]=min(D[v],D[select_v]+E[select_v][v])**

## 풀이

1. 시작점 하나를 잡는다.

2. q에 시작점을 제외한 모든 노드를 넣는다.

3. q가  empty가 될때까지 돌린다.

4. D에 최소 값들을 저장한다. (처음에는 시작점으로 나중에는 가장작아서 선택된 노드들을 기준으로)

5. 최소값이 된 노드를 잡고 큐에서 뺀다.

6. 반복!!!!!!!!!!!!!!!!!

#### 코드

* [깃허브 코드링크](https://github.com/rim0621/Algorithm-study/tree/master/12.Dijkstra)

* [티스토리 알고리즘](http://rim0621.tistory.com/category/SW/Algorithm)

```c++
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

                q.erase(find(q.begin(),q.end(),selectNode));
                // 한번 썻던 노드는 다시 않함으로 삭제

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

```
