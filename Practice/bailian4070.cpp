#include<iostream>
using namespace std;
int n;
int count;
int array[8];
bool vis[8];
void dfs(int k)
{
	if(count==0)
	{
		array[n-count-1]=k;
		for(int i=0;i<n;i++)
		{
			if(i==n-1)
				cout<<array[i];
			else
				cout<<array[i]<<" ";
		}
		cout<<endl;
		return;
	}
	else
	{
		array[n-count-1]=k;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			vis[i]=true;
			count--;
			dfs(i);
			count++;
			vis[i]=false;
		}
	}
}
int main()
{
	while(cin>>n)
	{
		if(n==0)
		{
			break;
		}
		else
		{
			count=n;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<8;j++)
				{
					vis[j]=false;
				}
				count--;
				vis[i]=true;
				dfs(i);
				count++;
			}
		}
	}
	return 0;
} 
