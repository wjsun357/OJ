#include<iostream>
#include<cstring>
#define INF 100000000
using namespace std;
int dis1[1001];
int dis2[1001];
bool vis[1001];
int road1[1001][1001];
int road2[1001][1001];
int N,M,X;
void dij()
{
	for(int i=1;i<=N;i++)
	{
		vis[i]=false;
	}
	vis[X]=true;
	for(int i=1;i<=N;i++)
	{
		if(road1[X][i]!=INF)
		{
			dis1[i]=road1[X][i];
		}
	}
	for(int k=2;k<=N;k++)
	{
		int pos=-1;
		int Min=INF;
		for(int i=1;i<=N;i++)
		{
			if(vis[i]==false&&dis1[i]<Min)
			{
				Min=dis1[i];
				pos=i;
			}
		}
		vis[pos]=true;
		for(int i=1;i<=N;i++)
		{
			if(vis[i]==false&&dis1[pos]+road1[pos][i]<dis1[i])
			{
				dis1[i]=dis1[pos]+road1[pos][i];
			}
		}
	}
	for(int i=1;i<=N;i++)
	{
		vis[i]=false;
	}
	vis[X]=true;
	for(int i=1;i<=N;i++)
	{
		if(road2[X][i]!=INF)
		{
			dis2[i]=road2[X][i];
		}
	}
	for(int k=2;k<=N;k++)
	{
		int pos=-1;
		int Min=INF;
		for(int i=1;i<=N;i++)
		{
			if(vis[i]==false&&dis2[i]<Min)
			{
				Min=dis2[i];
				pos=i;
			}
		}
		vis[pos]=true;
		for(int i=1;i<=N;i++)
		{
			if(vis[i]==false&&dis2[pos]+road2[pos][i]<dis2[i])
			{
				dis2[i]=dis2[pos]+road2[pos][i];
			}
		}
	}
	int Max=0;
	for(int i=1;i<=N;i++)
	{
		if(i!=X)
		{
			if(Max<dis1[i]+dis2[i])
			{
				Max=dis1[i]+dis2[i];
			}
		}
	}
	cout<<Max<<endl;
}
int main()
{
	cin>>N>>M>>X;
	int a,b,t;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			road1[i][j]=INF;
			road2[i][j]=INF;
		}
		road1[i][i]=0;
		road2[i][i]=0;
		dis1[i]=INF;
		dis2[i]=INF;
	}
	for(int i=0;i<M;i++)
	{
		cin>>a>>b>>t;
		road1[a][b]=t;
		road2[b][a]=t;
	}
	dij();
}
