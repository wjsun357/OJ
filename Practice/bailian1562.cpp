#include<iostream>
using namespace std;
int m,n;
int count=0;
char grid[100][100];
int judge[100][100];
int map[9][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
void oil(int x,int y)
{
	if(judge[x][y]==1&&grid[x][y]=='@')
	{
		for(int i=0;i<9;i++)
		{
			if(x+map[i][0]>=0&&x+map[i][0]<100&&y+map[i][1]>=0&&y+map[i][1]<100)
			{
				if(judge[x+map[i][0]][y+map[i][1]]==0&&grid[x+map[i][0]][y+map[i][1]]=='@')
				{
					judge[x+map[i][0]][y+map[i][1]]=1;
					oil(x+map[i][0],y+map[i][1]);
				}
			}
		}
	}
	else if(judge[x][y]==0&&grid[x][y]=='@')
	{
		count++;
		judge[x][y]=1;
		for(int i=0;i<9;i++)
		{
			if(x+map[i][0]>=0&&x+map[i][0]<100&&y+map[i][1]>=0&&y+map[i][1]<100)
			{
				if(judge[x+map[i][0]][y+map[i][1]]==0&&grid[x+map[i][0]][y+map[i][1]]=='@')
				{
					judge[x+map[i][0]][y+map[i][1]]=1;
					oil(x+map[i][0],y+map[i][1]);
				}
			}
		}
	}
}
int main()
{
	while(true)
	{
		cin>>m;
		cin>>n;
		count=0;
		if(m==0)
			break;
		else
		{
			for(int i=0;i<100;i++)
			{
				for(int j=0;j<100;j++)
				{
					grid[i][j]='*';
					judge[i][j]=0;
				}
			}
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					cin>>grid[i][j];
					//scanf("%c",&grid[i][j]);
				}
			}
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					oil(i,j);
				}
			}
			cout<<count<<endl;
		}
	}
	return 0;
}
