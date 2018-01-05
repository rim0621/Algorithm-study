#include<bits/stdc++.h>
using namespace std;

int testCase, n_case;

struct Node{
        int x,y;
};



bool Less(Node const &a, Node const &b)
{	
	if(a.x!=b.x)
	{
		return a.x < b.x;
	}
	else
		return a.y < b.y;

}
bool Greater(Node const &a, Node const &b)
{
	return a.y > b.y;
}

int main()
{	
	cin>>testCase;
	for (int num=0;num<testCase;num++){
		scanf("%d", &n_case);
		Node *node=(Node*)malloc(sizeof(Node)*n_case);
		int *n=(int*)malloc(sizeof(int)*n_case);
		for(int i=0;i<n_case;i++)
		{
			scanf("%d %d", &node[i].x, &node[i].y);
		}

		sort(node,node+n_case,Less);
		
		int count=1;
		int tmp;
		for(int i=0;i<n_case;i++)
		{
		  
			tmp=i;
			while(node[tmp].x!=0&&node[tmp].x==node[tmp+1].x)
			{
				count++;
				tmp++;
			}
			if(count>1)
			{
				
				if(node[i].y!=node[tmp-count].y)
				{
					sort(node+i,node+i+count,Greater);
				}	
			}
			count=1;
			i=tmp;
		}
	
		int M;
		scanf("%d",&M);
	        for (int i=0;i<M;i++){
        	  	 scanf("%d", &n[i]);
		}
		for(int i=0;i<M;i++){
	                 printf("%d %d\n", node[n[i]-1].x, node[n[i]-1].y);

		}  	
	}
	
	return 0;
}
