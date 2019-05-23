#include<iostream>
using namespace std;
int P,R;
int network[51][51];
bool vis[51];
int main()
{
	while(cin>>P)
	{
		if(P==0)
		{
			break;
		}
		cin>>R;
		for(int i=1;i<=P;i++)
		{
			for(int j=1;j<=P;j++)
			{
				network[i][j]=10000;
			}
			vis[i]=false;
		}
		for(int i=0;i<R;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			network[a][b]=min(network[a][b],c);
			network[b][a]=network[a][b];
		}
		vis[1]=true;
		int count=0;
		for(int k=1;k<=P-1;k++)
		{
			int Min=10000;
			int s,e;
			for(int i=1;i<=P;i++)
			{
				if(vis[i]==true)
				{
					for(int j=1;j<=P;j++)
					{
						if(vis[j]==false&&network[i][j]<Min)
						{
							Min=network[i][j];
							s=i;
							e=j;
						}	
					}	
				}
			}
			count+=network[s][e];
			vis[e]=true;
		}
		cout<<count<<endl;
	}
	return 0;
}
