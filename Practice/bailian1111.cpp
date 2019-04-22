#include<iostream>
using namespace std;
char grid[21][21];
bool map[21][21];
int r,c;
int go[9][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
int loc[4][2]={0,1,0,-1,1,0,-1,0};
void findall(int x,int y)
{
	map[x][y]=true;
	for(int i=0;i<9;i++)
	{
		int xx=x+go[i][0];
		int yy=y+go[i][1];
		if(xx>=1&&xx<=r&&y>=1&&yy<=c&&grid[xx][yy]=='X'&&map[xx][yy]==false)
		{
			findall(xx,yy);
		}
	}
}
int my_length(int x,int y)
{
	int total=4;
	for(int i=0;i<4;i++)
	{
		int xx=x+loc[i][0];
		int yy=y+loc[i][1];
		if(xx>=1&&xx<=r&&y>=1&&yy<=c&&map[xx][yy]==true)
		{
			total-=1;
		}
	}
	return total;
}
int main()
{
	int x,y;
	while(true)
	{
		cin>>r>>c>>x>>y;
		if(r==0&&c==0&&x==0&&y==0)
		{
			break;
		}
		else
		{
			for(int i=1;i<=20;i++)
			{
				for(int j=1;j<=20;j++)
				{
					grid[i][j]='.';
				}
			}
			for(int i=1;i<=20;i++)
			{
				for(int j=1;j<=20;j++)
				{
					grid[i][j]='.';
					map[i][j]=false;
				}
			}
			for(int i=1;i<=r;i++)
			{
				for(int j=1;j<=c;j++)
				{
					cin>>grid[i][j];
				}
			}
			findall(x,y);
			int length=0;
			for(int i=1;i<=r;i++)
			{
				for(int j=1;j<=c;j++)
				{
					if(map[i][j]==true)
					{
						length+=my_length(i,j);
					}
				}
			}
			cout<<length<<endl;
		}
	}
}
