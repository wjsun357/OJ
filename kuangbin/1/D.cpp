#include<iostream>
#include<bitset>
#include<string.h>
#include<cstring>
#include<string>
using namespace std;
int M,N;
int grid[16][16];
int record[16][16];
int flip[16][16];
int Min[16][16];
int main()
{
	cin>>M>>N;
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>grid[i][j];
			flip[i][j]=0;
		}
	}
	int MIN=10000;
	memcpy(record,grid,sizeof(grid));
	for(int i=0;i<=(1<<N)-1;i++)
	{
		memcpy(grid,record,sizeof(record));
		memset(flip,0,sizeof(flip));
		bitset<16> bs(i);
		string s=bs.to_string();
		for(int j=1;j<=N;j++)
		{
			int temp=s[16-N+j-1]-'0';
			if(temp==1)
			{
				flip[1][j]=1;
				grid[1][j]=1-grid[1][j];
				if(j-1>=1)
					grid[1][j-1]=1-grid[1][j-1];
				if(j+1<=N)
					grid[1][j+1]=1-grid[1][j+1];
				if(2<=M)
					grid[2][j]=1-grid[2][j];
			}
		}
		for(int k=2;k<=M;k++)
		{
			for(int j=1;j<=N;j++)
			{
				if(grid[k-1][j]==1)
				{
					flip[k][j]=1;
					grid[k][j]=1-grid[k][j];
					grid[k-1][j]=0;
					if(k+1<=M)
						grid[k+1][j]=1-grid[k+1][j];
					if(j-1>=1)
						grid[k][j-1]=1-grid[k][j-1];
					if(j+1<=N)
						grid[k][j+1]=1-grid[k][j+1];
				}
			}
		}
		int flag=0;
		int count=0;
		for(int k=1;k<=M;k++)
		{
			for(int j=1;j<=N;j++)
			{
				if(grid[k][j]==1)
				{
					flag=1;
					break;
				}
				if(flip[k][j]==1)
				{
					count++;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		if(flag==0)
		{
			if(MIN>count)
			{
				MIN=count;
				memcpy(Min,flip,sizeof(flip));
			}
		}
	}
	if(MIN==10000)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		for(int k=1;k<=M;k++)
		{
			for(int j=1;j<=N;j++)
			{
				if(j==N)
					cout<<Min[k][j]<<endl;
				else cout<<Min[k][j]<<" ";
			}
		}
	}
	return 0;
}
