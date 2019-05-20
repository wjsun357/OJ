#include<iostream>
#include<cstring>
#define INF 0x7FFFFFF
using namespace std;
bool vis[1001];
int field[1001][1001];
int len[1001];
int T,N;
void dij()
{
	vis[1]=true;
	len[1]=0;
	for(int i=2;i<=N;i++)
	{
		if(field[1][i]!=-1)
		{
			len[i]=field[1][i];
		}
	}
	for(int k=2;k<=N;k++)
	{
		int MIN=INF;
		int pos=0;
		for(int i=2;i<=N;i++)
		{
			if(len[i]!=INF&&vis[i]!=true&&len[i]<MIN)
			{
				MIN=len[i];
				pos=i;
			}
		}
		if(pos==N) 
			return;
		vis[pos]=true;
		for(int i=2;i<=N;i++)
		{
			if(field[pos][i]!=-1&&vis[i]!=true)
			{
				if(field[pos][i]+len[pos]<len[i])
				{
					len[i]=field[pos][i]+len[pos];
				}
			}
		}
	}
}
int main()
{
	cin>>T>>N;
	int x,y,z;
	for(int i=0;i<1001;i++)
	{
		vis[i]=false;
		len[i]=INF;
		for(int j=0;j<1001;j++)
		{
			field[i][j]=-1;
		}
	}
	for(int i=0;i<T;i++)
	{
		cin>>x>>y>>z;
		if(field[x][y]!=-1)
		{
			field[x][y]=min(z,field[x][y]);
			field[y][x]=field[x][y];
		}
		else
		{
			field[x][y]=z;
			field[y][x]=z;
		}
	}
	dij();
	cout<<len[N];
	return 0;
} 
