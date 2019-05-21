#include<iostream>
#include<vector>
#define INF 1000000
using namespace std;
int F,N,M,W;
struct edge
{
	int s;
	int e;
	int t;
};
vector<edge>Edge;
int dis[501];
void bf()
{
	for(int i=1;i<=N;i++)
	{
		dis[i]=INF;
	}
	dis[1]=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<Edge.size();j++)
		{
			edge e=Edge[j];
			if(dis[e.e]>dis[e.s]+e.t)
			{
				dis[e.e]=dis[e.s]+e.t;
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
	cin>>F;
	for(int i=0;i<F;i++)
	{
		while(!Edge.empty())
		{
			Edge.pop_back();
		}
		cin>>N>>M>>W;
		for(int j=0;j<M;j++)
		{
			edge e1,e2;
			cin>>e1.s>>e1.e>>e1.t;
			e2.e=e1.s;
			e2.s=e1.e;
			e2.t=e1.t;
			Edge.push_back(e1);
			Edge.push_back(e2);
		}
		for(int j=0;j<W;j++)
		{
			edge e;
			cin>>e.s>>e.e>>e.t;
			e.t*=-1;
			Edge.push_back(e);
		}
		bf();
	}
	return 0;
}
