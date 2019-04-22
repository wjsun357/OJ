#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int L,R,C;
int sx,sy,sz;
char maze[31][31][31];
bool already[31][31][31];
int go[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
struct step
{
	int x;
	int y;
	int z;
	int time;
};
queue<step> Q;
int bfs()
{
	while(!Q.empty())
	{
		step s=Q.front();
		Q.pop();
		int x=s.x;
		int y=s.y;
		int z=s.z;
		int t=s.time;
		for(int i=0;i<6;i++)
		{
			step next;
			int xx=x+go[i][0];
			int yy=y+go[i][1];
			int zz=z+go[i][2];
			if(xx>=1&&xx<=L&&yy>=1&&yy<=R&&zz>=1&&zz<=C&&!already[xx][yy][zz])
			{
				if(maze[xx][yy][zz]=='E')
				{
					return t+1;
				}
				else if(maze[xx][yy][zz]=='.')
				{
					next.x=xx;
					next.y=yy;
					next.z=zz;
					next.time=t+1;
					Q.push(next);
					already[xx][yy][zz]=true;
				}
			}
		}
	}
	return -1;
}
int main()
{
	while(cin>>L>>R>>C)
	{
		memset(already,false,sizeof(already));
		while(!Q.empty())
		{
			Q.pop();
		}
		if(L==0&&R==0&&C==0)
		{
			break;
		}
		else
		{
			for(int i=1;i<=L;i++)
			{
				for(int j=1;j<=R;j++)
				{
					for(int k=1;k<=C;k++)
					{
						cin>>maze[i][j][k];
						if(maze[i][j][k]=='S')
						{
							sx=i;
							sy=j;
							sz=k;
						}
					}
				}
			}
			step start;
			start.x=sx;
			start.y=sy;
			start.z=sz;
			start.time=0;
			already[sx][sy][sz]=true;
			Q.push(start);
			int n=bfs();
			if(n==-1)
			{
				cout<<"Trapped!"<<endl;
			}
			else
			{
				cout<<"Escaped in "<<n<<" minute(s)."<<endl;
			}
		}
	}
	return 0;
}
