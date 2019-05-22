#include<iostream>
#include<stdio.h>
using namespace std;
int N,K;
int find(int x,int* father)
{
	if(father[x]!=x)
	{
		father[x]=find(father[x],father);
	}
	return father[x];
}
void Union(int x,int y,int* father)
{
	int px=find(x,father);
	int py=find(y,father);
	if(px!=py)
	{
		father[py]=px;
	}
}
int main()
{
	scanf("%d %d",&N,&K);
	int count=0;
	int* father=new int[3*N+1];
	for(int i=0;i<3*N+1;i++)
	{
		father[i]=i;
	}
	for(int i=0;i<K;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if((a!=1&&a!=2)||b>N||c>N)
		{
			count++;
			continue;
		}
		if(a==1)
		{
			if(find(b,father)==find(c+N,father)||find(b,father)==find(c+2*N,father)||find(b+N,father)==find(c,father)||find(b+N,father)==find(c+2*N,father)||find(b+2*N,father)==find(c,father)||find(b+2*N,father)==find(c+N,father))
			{
				count++;
			}
			else
			{
				Union(b,c,father);
				Union(b+N,c+N,father);
				Union(b+2*N,c+2*N,father);
			}
		}
		else
		{
			if(find(b,father)==find(c+2*N,father)||find(b,father)==find(c,father)||find(b+N,father)==find(c,father)||find(b+N,father)==find(c+N,father)||find(b+2*N,father)==find(c+2*N,father)||find(b+2*N,father)==find(c+N,father))
			{
				count++;
			}
			else
			{
				Union(b,c+N,father);
				Union(b+N,c+2*N,father);
				Union(b+2*N,c,father);
			}
		}
	}
	printf("%d",count);
	return 0;
} 
