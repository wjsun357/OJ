#include<iostream>
using namespace std;
int N,M,K,C,R;
int cost[100];
int blood[100];
int dp[1000][500];
int main()
{
	cin>>N>>M>>K;
	C=0;
	R=M;
	for(int i=1;i<=K;i++)
	{
		cin>>cost[i]>>blood[i];
	}
	for(int m=1;m<=K;m++)
	{
		for(int i=N;i>=1;i--)
		{
			for(int j=M;j>=1;j--)
		 	{
                if(cost[m]<=i&&blood[m]<=j)
                {
                	dp[i][j]=max(dp[i][j],dp[i-cost[m]][j-blood[m]]+1);
				}
                else
                {
                	dp[i][j]=dp[i][j];
				}
            }	
		}
	}
    for(int i=0;i<=M;i++)
    {
    	for(int j=0;j<=N;j++)
    	{
    		if(dp[j][i]==dp[N][M])
			{
                printf("%d %d\n",dp[N][M],M-i);
                return 0;
            }
		}
	}
}
