#include<bits/stdc++.h>
using namespace std;
int findQ(int mazeSize,int number)
{
	
	if(mazeSize/4>=number)
		return 1;
	else if(mazeSize*2/4>=number)
		return 2;
	else if(mazeSize*3/4>=number)
		return 3;
	else if(mazeSize>=number)
		return 4;
	
}
struct Position{
	int y,x;
	Position(){
		this->x=0;
		this->y=0;
	}
	Position(int y,int x ){
		this->x=x;
		this->y=y;
	}
};

Position findPosition(int mazeSize,int number,int sz)
{
	Position p;
	if(sz==2)
	{	
		if(number==1)
			return Position(1,1);
		else if(number==2)
			return Position(2,1);
		else if(number==3)
			return Position(2,2);
		else if(number==4)
			return Position(1,2);
		
	}
	int q=findQ(mazeSize,number);
	if(q==1)
	{
		p=findPosition(mazeSize/4,number,sz/2);
		swap(p.x,p.y);
		return p;
	}
	else if(q==2)
	{
		p=findPosition(mazeSize/4,number-mazeSize/4,sz/2);
		p.y+=(sz/2);
		return p;
	}			
	else if(q==3)
	{
		p=findPosition(mazeSize/4,number-mazeSize*2/4,sz/2);
		p.y+=(sz/2);
		p.x+=(sz/2);
		return p;
	}
	else if(q==4)
	{
		Position tmp=findPosition(mazeSize/4,number-mazeSize*3/4,sz/2);
		p.x+=sz+1-tmp.y;
		p.y+=sz/2+1-tmp.x;
		return p;
	}

}
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int num=0;num<tc;num++)
	{
		int sz,number;
		scanf("%d %d",&sz,&number);
		if(sz==1)
		{
			printf("1 1\n");
			continue;
		}
		int mazeSize=sz*sz;
		Position p=findPosition(mazeSize,number,sz);
		printf("%d %d\n", p.x , p.y);
	}
	return 0;
}
