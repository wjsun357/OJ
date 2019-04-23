#include<iostream>
#include<queue>
using namespace std;
bool map[21][21];
bool vis[21];
int s,e;
queue<int>Q;
void dfs(int l)
{
	queue<int>Q1;
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		if(x==e)
		{
			cout<<s<<" to "<<e<<": "<<l<<endl;
			return;
		}
		else
		{
			for(int i=1;i<=20;i++)
			{
				if(vis[i]==false&&map[x][i]==true)
				{
					vis[i]=true;
					Q1.push(i);
				}
			}
		}
	}
	Q=Q1;
	dfs(l+1);
}
int main()
{
	int number;
	int pos;
	int flag=0;
	int count=0;
	while(cin>>number)
	{
		for(int i=0;i<21;i++)
		{
			for(int j=0;j<21;j++)
			{
				map[i][j]=false;
			}
		}
		for(int i=1;i<=19;i++)
		{
			if(flag==0)
			{
				flag=1;
			}
			else
			{
				cin>>number;
			}
			int pos;
			for(int j=0;j<number;j++)
			{
				cin>>pos;
				map[i][pos]=true;
				map[pos][i]=true;
			}
		}
		count++;
		cout<<"Test Set #"<<count<<endl;
		cin>>number;
		for(int i=0;i<number;i++)
		{
			for(int j=0;j<21;j++)
			{
				vis[j]=false;
			}
			cin>>s>>e;
			while(!Q.empty())
			{
				Q.pop();
			}
			Q.push(s);
			vis[s]=false;
			dfs(0);
		}
		flag=0;
		cout<<endl;
	}
	return 0;
} 
