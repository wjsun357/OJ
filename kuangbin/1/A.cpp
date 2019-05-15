#include<iostream>
using namespace std;
int n,k;
int count;
char chess[9][9];
bool already[9][9];
void dfs(int x,int y,int number)
{
	for(int i=1;i<=n;i++)
	{
		if(already[x][i]==true)
		{
			if(y!=i)
			{
				return;
			}
		}
		if(already[i][y]==true)
		{
			if(x!=i)
			{
				return;
			}
		}
	}
	if(number==k)
	{
		count++;
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(i==x)
		{
			for(int j=y+1;j<=n;j++)
			{
				if(chess[i][j]=='#')
				{
					already[i][j]=true;
					dfs(i,j,number+1);
					already[i][j]=false;
				}
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(chess[i][j]=='#')
				{
					already[i][j]=true;
					dfs(i,j,number+1);
					already[i][j]=false;
				}
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
			break;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>chess[i][j];
				already[i][j]=false;
			}
		}
	 	count=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(chess[i][j]=='#')
				{
					already[i][j]=true;
					dfs(i,j,1);
					already[i][j]=false;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
} 
