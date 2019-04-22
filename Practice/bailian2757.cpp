#include<iostream>
using namespace std;
int N;
int array[1001];
int dp[1001];
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>array[i];
	}
	for(int i=0;i<1001;i++)
	{
		dp[i]=1;
	}
	dp[0]=0;
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(array[i]>array[j])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int Max=1;
	for(int i=1;i<=N;i++)
	{
		Max=max(Max,dp[i]);
	}
	cout<<Max;
	return 0;
} 
