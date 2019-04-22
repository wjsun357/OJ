#include<iostream>
using namespace std;
int board[20][20];
bool cango[26];
int R,C;
int go[4][2]={0,1,0,-1,1,0,-1,0};
int Max=0;
void dfs(int x,int y,int dis)
{
	for(int i=0;i<4;i++)
	{
		if(x+go[i][0]>=0&&x+go[i][0]<R&&y+go[i][1]>=0&&y+go[i][1]<C)
		{
			int c=board[x+go[i][0]][y+go[i][1]];
			if(cango[c]==true)
			{
				cango[c]=false;
				dfs(x+go[i][0],y+go[i][1],dis+1);
				cango[c]=true;
			}
		}
	}
	if(dis>Max)
	{
		Max=dis;
	}
}
int main()
{
	cin>>R>>C;
	char character;
	for(int i=0;i<26;i++)
		cango[i]=true;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin>>character;
			board[i][j]=character-'A';
		}
	}
	cango[board[0][0]]=false;
	dfs(0,0,1);
	cout<<Max;
	return 0;
}
