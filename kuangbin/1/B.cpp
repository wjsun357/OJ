#include<iostream>
#include<queue>
int L,R,C;
char maze[31][31][31];
bool already[31][31][31];
int sx,sy,sz;
int go[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
using namespace std;
queue<int> Q;
void bfs()
{
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		int y=Q.front();
		Q.pop();
		int z=Q.front();
		Q.pop();
		int t=Q.front();
		Q.pop();
		for(int i=0;i<6;i++)
		{
			int mx=x+go[i][0];
			int my=y+go[i][1];
			int mz=z+go[i][2];
			int mt=t+1;
			if(mx>=1&&mx<=L&&my>=1&&my<=R&&mz>=1&&mz<=C&&already[mx][my][mz]==false&&maze[mx][my][mz]!='#')
			{
				if(maze[mx][my][mz]=='E')
				{
					cout<<"Escaped in "<<mt<<" minute(s)."<<endl;
					return;
				}
				already[mx][my][mz]=true;
				Q.push(mx);
				Q.push(my);
				Q.push(mz);
				Q.push(mt);
			}
		}
	}
	cout<<"Trapped!"<<endl;
}
int main()
{
	while(cin>>L>>R>>C)
	{
		if(L==0&&R==0&&C==0)
		{
			break;
		}
		for(int i=1;i<=L;i++)
		{
			for(int j=1;j<=R;j++)
			{
				for(int k=1;k<=C;k++)
				{
					cin>>maze[i][j][k];
					already[i][j][k]=false;
					if(maze[i][j][k]=='S')
					{
						sx=i;sy=j;sz=k;
					}
				}
			}
		}
		while(!Q.empty())
		{
			Q.pop();
		}
		Q.push(sx);
		Q.push(sy);
		Q.push(sz);
		Q.push(0);
		bfs();
	}
	return 0;
}
