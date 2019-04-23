#include<iostream>
#include<map>
#include<string>
#include<string.h>
using namespace std;
int number;
int M,N,P;
map<string,int> Map;
int Route[31][31];
int main()
{
	cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
	cin>>number;
	for(int o=1;o<=number;o++)
	{
		cout<<"DATA SET "<<o<<endl<<endl;
		cin>>M>>N>>P;
		string s;
		for(int p=0;p<31;p++)
		{
			for(int q=0;q<31;q++)
			{
				Route[p][q]=-1;
			}
		}
		for(int p=1;p<=M;p++)
		{
			cin>>s;
			Map[s]=p;
		}
		string beg,end;
		for(int p=1;p<=N;p++)
		{
			cin>>beg>>end;
			Route[Map[beg]][Map[end]]=1;
			Route[Map[end]][Map[beg]]=1;
		}
		for(int k=1;k<=M;k++)
		{
			for(int i=1;i<=M-1;i++)
			{
				for(int j=i+1;j<=M;j++)
				{
					if(Route[i][k]==-1||Route[k][j]==-1)
					{
						continue;
					}
					else
					{
						if(Route[i][j]==-1)
						{
							Route[i][j]=Route[i][k]+Route[k][j];
							Route[j][i]=Route[i][j];
						}
						else
						{
							if(Route[i][j]>Route[i][k]+Route[k][j])
							{
								Route[i][j]=Route[i][k]+Route[k][j];
								Route[j][i]=Route[i][j];
							}
						}
					}
				}
			}
		}
		for(int p=0;p<31;p++)
		{
			Route[p][p]=0;
		}
		int n;
		for(int p=1;p<=P;p++)
		{
			cin>>n>>beg>>end;
			if(Route[Map[beg]][Map[end]]!=-1)
			{
				cout<<"$"<<100*n*Route[Map[beg]][Map[end]]<<endl;
			}
			else
			{
				cout<<"NO SHIPMENT POSSIBLE"<<endl;
			}
		}
		cout<<endl;
	}
	cout<<"END OF OUTPUT";
	return 0;	
} 
