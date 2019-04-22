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
	for(int i=1;i<=(1<<N)-1;i++)//״̬i 
	{
		for(int j=1,_j=1;j<=N;j++,_j<<=1)//�������е� 
		{
			if(i&_j)//������ﵺ��j��
			{
                for(int k=1,_k=1;k<=N;k++,_k<<=1)//�������е� 
				{
                    if(j!=k&&_k&i)//��k����;�о����ĵ� 
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
