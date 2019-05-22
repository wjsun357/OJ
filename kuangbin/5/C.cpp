#include<iostream>
#include<cstring>
using namespace std;
int T,N,M;
int father[1001];
bool yes[1001];
int find(int x)
{
	if(father[x]!=x)
	{
		father[x]=find(father[x]);
	}
	return father[x];
}
void Union(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		father[fx]=fy;
	}
}
int main()
{
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N>>M;
		for(int j=1;j<=N;j++)
		{
			father[j]=j;
			yes[j]=false;
		}
		for(int j=0;j<M;j++)
		{
			int a,b;
			cin>>a>>b;
			Union(a,b);
		}
		for(int j=1;j<=N;j++)
		{
			yes[find(j)]=true;
		}
		int count=0;
		for(int j=1;j<=N;j++)
		{
			if(yes[j]==true)
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
