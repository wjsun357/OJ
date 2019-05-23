#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int t,n;
int father[1001];
int price[1001];
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
	cin>>t;
	for(int k=0;k<t;k++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			father[i]=i;
			scanf("%d",&price[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis D;
				D.x=i;
				D.y=j;
				scanf("%d",&D.len);
				D.len+=price[i];
				D.len+=price[j];
				if(i<j)
				{
					S.push(D);
				}
			}
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
	}
	return 0;
}
