#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int N,Q;
int father[101];
struct dis
{
	int x,y,len; 
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
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		father[i]=i;
		for(int j=1;j<=N;j++)
		{
			dis D;
			D.x=i;
			D.y=j;
			scanf("%d",&D.len);
			if(i<j)
			{
				S.push(D);
			}
		}
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		Union(x,y);
	}
	int count=0;
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
	printf("%d\n",count);
	return 0;
}
