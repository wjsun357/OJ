#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int N,M,S;double V;
double exchange[101][101];
double cost[101][101];
double dis[101];
int count;
struct data
{
	int a;
	int b;
	double r;
	double c;
};
vector<data>edge;
void bf()
{
	for(int i=1;i<=N;i++)
	{
		dis[i]=0;
	}
	dis[S]=V;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<edge.size();j++)
		{
			data e=edge[j];
			if(dis[e.b]<(dis[e.a]-e.c)*e.r)
			{
				dis[e.b]=(dis[e.a]-e.c)*e.r;
				if(i==N)
				{
					cout<<"YES"<<endl;
					return;
				}
			}
		}
	}
	cout<<"NO"<<endl;
}
int main()
{
	scanf("%d %d %d %lf",&N,&M,&S,&V);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		data e1,e2;
		scanf("%lf %lf %lf %lf",&e1.r,&e1.c,&e2.r,&e2.c);
		e1.a=a;
		e1.b=b;
		e2.a=b;
		e2.b=a;
		edge.push_back(e1);
		edge.push_back(e2);
	}
	bf();
	return 0;
}
