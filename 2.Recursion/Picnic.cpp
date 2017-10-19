/*
	완전 탐색(경우의수 다구하고) 하면서 조건에 맞으면 방법 추가
*/
#include<bits/stdc++.h>
using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool taken[10])
{
	int fristFree=-1;
	for( int i=0; i<n;++i)
	{
		if(!taken[i]){	// 짝을 아직 찾이 못했으면
			fristFree=i;
			break;
		}
	}
	if(fristFree==-1) return 1; //모든학생이 짝을 찾으면 한가지 방법 찾음
	int ret=0;
	for(int pairWith=fristFree+1;pairWith<n; ++pairWith)
	{
		if(!taken[pairWith] && areFriends[fristFree][pairWith])	//짝을 찾지 못했고 둘이 친구라면
		{
			taken[fristFree]=taken[pairWith]=true;
			ret+=countPairings(taken);
			taken[fristFree]=taken[pairWith]=false; //다른 방법을 찾기 위해 다시 원상태로
		}
	}
	return ret; //쌍의 방법이 아니면 0을 반환.. 마지막에는 방법수 반환
}

int main()
{
	int m,f1,f2;
	bool taken[10];
	for(int i=0;i<n;i++)
	{
		taken[i]=i;
	}
	memset(areFriends,false,sizeof(areFriends));
	memset(taken,false,sizeof(taken));
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&f1,&f2);
		areFriends[f1][f2]=true;
		areFriends[f2][f1]=true;
	}
	printf("%d\n",countPairings(taken));
}
