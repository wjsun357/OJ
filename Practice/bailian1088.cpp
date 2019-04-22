#include<iostream>
#include<cstring>
using namespace std;
int R,C;
int map[101][101];
int length[101][101];
int go[4][2]={0,1,0,-1,1,0,-1,0};
int cal(int x,int y)
{
	if(length[x][y]!=-1)
	{
		return length[x][y];
	}
	int MAX=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+go[i][0];
		int yy=y+go[i][1];
		if(xx>=1&&xx<=R&&yy>=1&&yy<=C&&map[xx][yy]<map[x][y])
		{
			MAX=max(cal(xx,yy)+1,MAX);
		}
	}
	length[x][y]=MAX;
	return MAX;
}
int main()
{
	cin>>R>>C;
	memset(length,-1,sizeof(length));
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			cin>>map[i][j];
		}
	}
	int maxx=-1;
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			maxx=max(cal(i,j),maxx);
		}
	}
	cout<<maxx;
	return 0;
}
