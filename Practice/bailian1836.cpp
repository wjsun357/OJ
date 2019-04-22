#include<iostream>
#include<cstring>
using namespace std;
int n;
double line[1001];
int L[1001];
int R[1001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>line[i];
	}
	int Max=0;
	//memset(L,1,sizeof(L));
	//memset(R,1,sizeof(R));
	for(int i=0;i<1001;i++)
	{
		L[i]=1;
		R[i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(line[i]>line[j])
			{
				L[i]=max(L[i],L[j]+1);
			}
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(line[i]>line[j])
			{
				R[i]=max(R[i],R[j]+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			Max=max(Max,L[i]+R[j]);
		}
	}
	cout<<n-Max;
	return 0;
}
