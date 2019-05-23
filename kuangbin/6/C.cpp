#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int n;
int father[101];
struct ball
{
	double x,y,z,r;
};
struct dis
{
	int x,y; 
	double len;
};
struct cmp
{
	bool operator()(dis D1,dis D2)
	{
		return D1.len>D2.len;
	}
};
priority_queue<dis,vector<dis>,cmp> S;
int find(int x)
{
	if(father[x]!=x)
	{
		father[x]=find(father[x]);
	}
	return father[x];
}
bool Union(int x,int y)
{
	int px=find(x);
	int py=find(y);
	if(px==py)
	{
		return false;
	}
	else
	{
		father[px]=py;
		return true;
	}
}
int main()
{
	while(scanf("%d",&n))
	{
		if(n==0)
		{
			break;
		}
		vector<ball> V;
		while(!S.empty())
		{
			S.pop();
		}
		ball b;
		b.x=0;b.y=0;b.z=0;b.r=0;
		V.push_back(b);
		for(int i=1;i<=n;i++)
		{
			father[i]=i;
			ball b;
			scanf("%lf %lf %lf %lf",&b.x,&b.y,&b.z,&b.r);
			V.push_back(b);
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dis D;
				D.x=i;
				D.y=j;
				double temp;
				temp=sqrt(pow(V[i].x-V[j].x,2)+pow(V[i].y-V[j].y,2)+pow(V[i].z-V[j].z,2));
				if(temp>V[i].r+V[j].r)
				{
					D.len=temp-V[i].r-V[j].r;
					S.push(D);
				}
				else
				{
					Union(i,j);
				}
			}
		}
		double count=0;
		while(!S.empty())
		{
			dis D=S.top();
			S.pop();
			if(Union(D.x,D.y)==false)
			{
				continue;
			}
			else
			{
				count+=D.len;
			}
		}
		printf("%.3f\n",count);
	}
	return 0;
}
