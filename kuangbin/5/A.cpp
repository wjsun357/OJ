#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<vector>
using namespace std;
int N,D;
struct point
{
	int x,y;
};
point P[1005];
int father[1005];
vector<int>already;
int find(int x)
{
	if(father[x]==x)
	{
		return x;
	}
	else return father[x]=find(father[x]);
}
int main()
{
	scanf("%d%d",&N,&D);
	for(int i=1;i<=N;i++)
	{
		point p;
		scanf("%d%d",&p.x,&p.y);
		P[i]=p;
		father[i]=i;
	}
	char c;
	while(scanf(" %c",&c)!=EOF)
	{
		if(c=='O')
		{
			int p;
			cin>>p;
			already.push_back(p);
			for(int i=0;i<already.size()-1;i++)
			{
				if(sqrt(double(pow(P[already[i]].x-P[p].x,2)+pow(P[already[i]].y-P[p].y,2)))<=D)
				{
					int pp=find(p);
					int pi=find(already[i]);
					if(pp!=pi)
					{
						father[pi]=pp;
					}
				}
			}
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			int pa=find(a);
			int pb=find(b);
			if(pa==pb)
			{
				printf("SUCCESS\n");
			}
			else
			{
				printf("FAIL\n");
			}
		}
	}
} 
