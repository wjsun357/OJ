#include<iostream>
#include<cstring>
using namespace std;
int N;
int tall[101];
int Left[101];
int Right[101];
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>tall[i];
	}
	memset(Left,0,sizeof(Left));
	memset(Right,0,sizeof(Right));
	for(int i=1;i<101;i++)
	{
		Left[i]=1;
		Right[i]=1;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(tall[j]<tall[i])
			{
				Left[i]=max(Left[i],1+Left[j]);
			}
		}
	}
	for(int i=N;i>=1;i--)
	{
		for(int j=N;j>i;j--)
		{
			if(tall[i]>tall[j])
			{
				Right[i]=max(Right[i],1+Right[j]);
			}
		}
	}
	int MAX=0;
	for(int i=1;i<=N;i++)
	{
		MAX=max(MAX,Left[i]+Right[i]-1);
	}
	cout<<N-MAX;
	return 0;	
} 
