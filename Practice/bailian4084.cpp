#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int v,a;
	cin>>v>>a;
	int** lianjie=new int* [v];
	for(int i=0;i<v;i++)
	{
		lianjie[i]=new int[v];
	}
	int* rudu=new int[v];
	for(int i=0;i<v;i++)
	{
		rudu[i]=0;
		for(int j=0;j<v;j++)
		{
			lianjie[i][j]=0;
		}
	}
	int s,e;
	for(int i=0;i<a;i++)
	{
		cin>>s>>e;
		if(lianjie[s-1][e-1]==1)
		{
			continue;
		}
		else
		{
			lianjie[s-1][e-1]=1;
			rudu[e-1]++;
		}
	}
	for(int i=0;i<v;i++)
	{
		int POINT=0;
		for(int j=0;j<v;j++)
		{
			if(rudu[j]==0)
			{
				POINT=j;
				break;
			}
		}
		rudu[POINT]=9999;
		for(int j=0;j<v;j++)
		{
			if(j==POINT)
				continue;
			if(lianjie[POINT][j]==1)
			{
				//lianjie[POINT][j]=0;
				rudu[j]--;
			}
		}
		if(i==v-1) cout<<"v"<<POINT+1;
		else cout<<"v"<<POINT+1<<" ";
	}
	return 0;
}
