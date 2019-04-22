#include<iostream>
#include<cstring>
using namespace std;
int n,k;
char chess[10][10];
bool placex[10];
bool placey[10];
int count=0;
void dfs(int x,int y,int left)
{
	if(left<0)
		return;
	if(left==0)
	{
		count++;
		return;
	}
	for(int i=x;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(chess[i][j]=='#'&&placex[i]==false&&placey[j]==false)
			{
				placex[i]=true;
				placey[j]=true;
				dfs(i,j,left-1);
				placex[i]=false;
				placey[j]=false;
			}
		}
	}
}
int main()
{
	while(cin>>n>>k)
	{
		if(n==-1&&k==-1)
		{
			return 0;
		}
		else
		{
			count=0;
			memset(placex,false,sizeof(placex));
			memset(placey,false,sizeof(placey));
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					cin>>chess[i][j];
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(chess[i][j]=='#')
					{
						placex[i]=true;
						placey[j]=true;
						dfs(i,j,k-1);//放在i，j点，还需放num-1个
						placex[i]=false;
						placey[j]=false;
					}
				}
			}
			cout<<count<<endl;
		}
	}
}
