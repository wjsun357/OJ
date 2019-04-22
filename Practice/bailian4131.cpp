#include<iostream>
#include<cstring>
using namespace std;
int N,M;
int weight[3500];
int factor[3500];
int dp[13000];
int main()
{
	cin>>N>>M;
	memset(weight,0,sizeof(weight));
	memset(factor,0,sizeof(factor));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=N;i++)
	{
		cin>>weight[i];
		cin>>factor[i];
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=M;j>=0;j--)
		{
			if(j-weight[i]>=0)
			{
				dp[j]=max(dp[j],dp[j-weight[i]]+factor[i]);
			}
		}
	}
	cout<<dp[M];
}
