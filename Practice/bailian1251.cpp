#include<iostream>
using namespace std;
int n;
int map[27][27];
int father[27];
int findfather(int x)
{
	if(x==father[x])
	{
		return x;
	}
	father[x]=findfather(father[x]);
	return father[x];
}
int main()
{
	while(cin>>n)
	{
		if(n==0)
		{
			break;
		}
		else
		{
			for(int i=1;i<=26;i++)
			{
				father[i]=i;
				for(int j=1;j<=26;j++)
				{
					map[i][j]=-1;
				}
			}
			for(int i=1;i<=n-1;i++)
			{
				int s,e,number,l;
				char x;
				cin>>x>>number;
				s=x-'A'+1;
				for(int j=1;j<=number;j++)
				{
					cin>>x;
					e=x-'A'+1;
					cin>>l;
					map[s][e]=l;
					map[e][s]=l;
				}
			}
			int count=n;
			int total=0;
			while(count!=1)
			{
				count--;
				int MIN=1000;
				int ri,rj;
				for(int i=1;i<=n-1;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						if(map[i][j]!=-1&&(findfather(i)!=findfather(j)))
						{
							if(map[i][j]<MIN)
							{
								MIN=map[i][j];
								ri=i;
								rj=j;
							}
						}
					}
				}
				father[findfather(rj)]=findfather(ri);
				total+=map[ri][rj];
			}
			cout<<total<<endl;
		}
	}
	return 0;
}
