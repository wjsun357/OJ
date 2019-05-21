#include<iostream>
#include<cstring>
using namespace std;
int N,M;
int beat[101][101];
int main()
{
	cin>>N>>M;
	memset(beat,0,sizeof(beat));
	for(int i=0;i<M;i++)
	{
		int a,b;
		cin>>a>>b;
		beat[a][b]=1;
		beat[b][a]=-1;
	}
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if((beat[k][i]==beat[i][j])&&beat[k][i]!=0)
				{
					beat[k][j]=beat[k][i];
					beat[j][k]=beat[i][k];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		int count=0;
		for(int j=1;j<=N;j++)
		{
			if(beat[i][j]!=0)
			{
				count++;
			}
		}
		if(count==N-1)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
