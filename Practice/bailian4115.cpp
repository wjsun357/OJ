#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int M,N,T,Min;
int sx,sy,ex,ey;
char map[200][200];
bool already[200][200][10];
int go[4][2]={0,1,0,-1,1,0,-1,0};
struct step
{
	int x;
	int y;
	int energy;
	int time;
};
queue<step> Q;
int bfs()
{
	while(Q.empty()==false)
	{
		step S=Q.front();
		Q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=S.x+go[i][0];
			int yy=S.y+go[i][1];
			int ee=S.energy;
			int tt=S.time;
			if(xx>=1&&xx<=M&&yy>=1&&yy<=N)
			{
				step temp;
				temp.x=xx;
				temp.y=yy;
				temp.energy=ee;
				temp.time=tt+1;
				if(map[xx][yy]=='#')
				{
					if(ee>=1)
					{
						if(already[xx][yy][ee-1]==false)
						{
							temp.energy-=1;
							Q.push(temp);
							already[xx][yy][ee-1]=true;
						}
					}
				}
				else if(map[xx][yy]=='*')
				{
					if(already[xx][yy][ee]==false)
					{
						Q.push(temp);
						already[xx][yy][ee]=true;
					}
				}
				else if(map[xx][yy]=='+')
				{
					return tt+1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	cin>>M>>N>>T;
	memset(map,'x',sizeof(map));
	memset(already,false,sizeof(already));
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='@')
			{
				sx=i;
				sy=j;
			}
			else if(map[i][j]=='+')
			{
				ex=i;
				ey=j;
			}
		}
	}
	already[sx][sy][T]=true;
	step S;
	S.x=sx;
	S.y=sy;
	S.energy=T;
	S.time=0;
	Q.push(S);
	cout<<bfs();
	return 0;	
} 
