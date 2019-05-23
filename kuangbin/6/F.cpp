#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
int N;
string truck[2001];
bool vis[2001];
int dis[2001][2001];
int low[2001];
int main()
{
	while(cin>>N)
	{
		if(N==0)
		{
			break;
		}
		for(int i=1;i<=N;i++)
		{
			cin>>truck[i];
			vis[i]=false;
		}
		for(int i=1;i<=N-1;i++)
		{
			for(int j=i+1;j<=N;j++)
			{
				int count=0;
				for(int k=0;k<7;k++)
				{
					if(truck[i][k]-truck[j][k]!=0)
					{
						count++;
					}
				}
				dis[i][j]=dis[j][i]=count;
			}
		}
		vis[1]=true;
		for(int i=1;i<=N;i++)
		{
			low[i]=dis[1][i];
		}
		int count=0;
		for(int k=1;k<=N-1;k++)
		{
			int Min=10;
			int e;
			for(int i=1;i<=N;i++)
			{
				if(vis[i]==false&&Min>low[i])
				{
					Min=low[i];
					e=i;
				}
			}
			count+=low[e];
			vis[e]=true;
			for(int i=1;i<=N;i++)
			{
				if(vis[i]==false&&low[i]>dis[e][i])
				{
					low[i]=dis[e][i];
				}
			}
		}
		cout<<"The highest possible quality is 1/"<<count<<"."<<endl;
	}
	return 0;
}
