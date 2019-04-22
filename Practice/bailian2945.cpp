#include<iostream>
using namespace std;
int k;
int height[26];
int dp[26];
int main()
{
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>height[i];
	}
	for(int i=0;i<26;i++)
	{
		dp[i]=1;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(height[j]>=height[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int MAX=0;
	for(int i=1;i<=k;i++)
	{
		MAX=max(MAX,dp[i]);
	}
	cout<<MAX;
	return 0;	
} 
