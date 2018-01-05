/*
	1.블록이 3칸 짜리니깐 3의배수만 
	2. 블로의 수 n을 얻은뒤, 답을 생성하는 과정을 n조각으로 나눠 한 조각에 한블록.
	3. 맨 위를 기준으로 블록을 4가지 형태로 놓는다.
*/
#include<bits/stdc++.h>
using namespace std;
const int coverType[4][3][2]={
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
// 놓을수 있나 확인
bool check(vector<vector<int> >& board,int y,int x,int type,int delta)
{
	bool ok=true;
	for(int i=0;i<3;++i)
	{
		const int ny=y+coverType[type][i][0];
		const int nx=x+coverType[type][i][1];
		if(ny<0||ny>=board.size() || nx<0||nx>=board[0].size()) //board size over
			ok=false;
		else if((board[ny][nx]+=delta)>1)	// chage 0->1
			ok=false;
	}
	return ok;
}

int cover(vector<vector<int> >& board){
	int y=-1,x=-1;
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[i].size();j++)
		{
			if(board[i][j]==0) //빈곳이 있다면 그 위치를 반환
			{
				y=i;
				x=j;
				break;
			}	
			if(y!=-1) break;	//???
		}
	}
	if(y==-1) return 1;	//빈곳이 없을시 방법
 	int ret=0;
	for(int type=0;type<4;++type)
	{
		if(check(board,y,x,type,1))
			ret+=cover(board);
		check(board,y,x,type,-1);	//원상복귀
	}
	return ret;
}

int main()
{
	int h=0,w=0;
	char state1;
	vector<int > v;
	vector<vector<int> > board;
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{	
			cin>>state1;
			if(state1=='.')
				v.push_back(0);
			else
				v.push_back(1);
		}
		board.push_back(v);
		v.clear();
	}
	printf("%d\n",cover(board));

}
