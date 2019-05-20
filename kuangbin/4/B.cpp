#include<iostream>
#include<queue>
#include<cmath>
#include<stdio.h>
using namespace std;
struct point
{
	double x;
	double y;
};
point stones[201];
double dis[201][201];
bool vis[201];
int n;
priority_queue<double,vector<double>,greater<double> > Q;
double minjump;
bool bfs()
{
	queue<int>Q1;
	Q1.push(1);
	vis[1]=true;
	while(!Q1.empty())
	{
		int p=Q1.front();
		Q1.pop();
		for(int i=2;i<=n;i++)
		{
			if(dis[p][i]<=minjump&&vis[i]==false)
			{
				if(i==2)
				{
					return true;
				}
				else
				{
					Q1.push(i);
					vis[i]=true;
				}
			}
		}
	}
	return false;
}
int main()
{
	int count=0;
	while(cin>>n)
	{
		if(n==0)
		{
			break;
		}
		count++;
		for(int i=1;i<=n;i++)
		{
			point p;
			cin>>p.x>>p.y;
			stones[i]=p;
		}
		while(!Q.empty())
		{
			Q.pop();
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				//int tempi=(int)(sqrt(pow(stones[i].x-stones[j].x,2)+pow(stones[i].y-stones[j].y,2))*1000);
				//double tempd=tempi/1000.0;
				dis[i][j]=sqrt(pow(stones[i].x-stones[j].x,2)+pow(stones[i].y-stones[j].y,2));
				dis[j][i]=dis[i][j];
				Q.push(dis[i][j]);
			}
		}
		double pre=-1;
		bool flag;
		while(!Q.empty())
		{
			minjump=Q.top();
			Q.pop();
			if(minjump!=pre)
			{
				for(int i=1;i<=n;i++)
				{
					vis[i]=false;
				}
				pre=minjump;
				flag=bfs();
				if(flag==true)
				{
					printf("Scenario #%d\nFrog Distance = %.3f\n\n",count,minjump);
					break;
				}
			}
		}
		/*
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",count,dis[1][2]);
		*/
	}
	return 0;
}
