#define SIZE 9
#include<bits/stdc++.h>
using namespace std;

void floodFill(char fig[][SIZE+1],int x,int y, char oldColor, char newColor)
{
	if(fig[x][y]!=oldColor)
		return ;
	else
	{
		fig[x][y]=newColor;
		//왼,오른,아래,위
		floodFill(fig, x-1,y,oldColor,newColor);
		floodFill(fig, x+1,y,oldColor,newColor);
		floodFill(fig, x,y-1,oldColor,newColor);
		floodFill(fig, x,y+1,oldColor,newColor);
	}	
}

int main()
{
	//why y is +1 ???
	char fig[][SIZE+1]={	
"*********", "*...*...*", "*...*...*","*..*....*", "***...***",
"*....*..*","*...*...*", "*..*....*", "*********"};


	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			cout<<fig[i][j]<<" ";
		}
		cout<<endl;
	}
	floodFill(fig,4,4,'.','+');
	cout<<endl;
        for(int i=0;i<SIZE;i++)
        {
                for(int j=0;j<SIZE;j++)
                {
                        cout<<fig[i][j]<<" ";
                }
                cout<<endl;
        }

	

}
