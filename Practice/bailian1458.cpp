#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		int l1=s1.length();
		int l2=s2.length();
		int dp[l1+1][l2+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=l1;i++)
		{
			for(int j=1;j<=l2;j++)
			{
				if(s1.at(i-1)==s2.at(j-1))
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		cout<<dp[l1][l2]<<endl;
	}
}
