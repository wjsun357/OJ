#include<iostream>
using namespace std;
int n;
int thing[21];
int dp[21][41];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>thing[i];
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=40;j>0;j--)
		{
			if(j-thing[i]>=0)
				dp[i][j]=dp[i-1][j]+dp[i-1][j-thing[i]];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][40];
	return 0;
}
