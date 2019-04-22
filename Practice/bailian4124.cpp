#include<iostream>
#define INF 1600000
using namespace std;
int N;
int road[17][17];
int dp[1<<16][17];
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>road[i][j];
		}
	}
	for(int i=1;i<=(1<<N)-1;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dp[i][j]=INF;
		}
	}
	dp[1][1]=0;
	for(int i=1;i<=(1<<N)-1;i++)//状态i 
	{
		for(int j=1,_j=1;j<=N;j++,_j<<=1)//遍历所有岛 
		{
			if(i&_j)//如果到达岛是j岛
			{
                for(int k=1,_k=1;k<=N;k++,_k<<=1)//遍历所有岛 
				{
                    if(j!=k&&_k&i)//若k岛是途中经过的岛 
                    {
                    	dp[i][j]=min(dp[i][j],dp[i^_j][k]+road[k][j]);
					}
                }
            }
		}
	}
	cout<<dp[(1<<N)-1][N];
	return 0;
}
