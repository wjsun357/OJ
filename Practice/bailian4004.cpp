#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,t;
void get_sum(int x,int pos,int array[],int *p)
{
	if(x==t)
	{
		(*p)++;
		return;
	}
	for(int i=pos+1;i<n;i++)
	{
		int sum=x+array[i];
		if(sum<t)
		{
			get_sum(sum,i,array,p);
		}
		else if(sum==t)
		{
			(*p)++;
			//return;
		}
		else
		{
			return;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&t);
	int array[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	sort(array,array+n);
	int count=0;
	int *p=&count;
	for(int i=0;i<n;i++)
		get_sum(array[i],i,array,p);
	cout<<count;
	return 0;
}
/*
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int n,t;
	int num[25];
	int dp[20010];
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=t;j>=0;j--)
		{
			if(dp[j]>0)
				dp[j+num[i]] += dp[j];
		}
	}
	cout<<dp[t]<<endl;
	return 0;
}
*/
