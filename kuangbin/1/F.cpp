#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;
vector<int> V;
queue<int> Q;
int x,y,NUM;
bool vis[10000];
void isprime()
{
	for(int i=1000;i<=9999;i++)
	{
		int flag=0;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			V.push_back(i);
		}
	}
}
int main()
{
	isprime();
	cin>>NUM;
	for(int i=0;i<NUM;i++)
	{
		cin>>x>>y;
		memset(vis,false,sizeof(vis));
		while(!Q.empty())
		{
			Q.pop();
		}
		vis[x]=true;
		Q.push(x);
		Q.push(0);
		while(!Q.empty())
		{
			int xx=Q.front();
			Q.pop();
			int tt=Q.front();
			Q.pop();
			if(xx==y)
			{
				cout<<tt<<endl;
				break;
			}
			else
			{
				stringstream ss;
				ss<<xx;
				string s=ss.str();
				for(int j=0;j<4;j++)
				{
					s=ss.str();
					for(int k=0;k<=9;k++)
					{
						s[j]=k+'0';
						vector<int>::iterator it = find(V.begin(), V.end(), atoi(s.c_str()));
						if(vis[atoi(s.c_str())]==false&&it!=V.end())
						{
							vis[atoi(s.c_str())]=true;
							Q.push(atoi(s.c_str()));
							Q.push(tt+1);
						}
					}
				}
			}
		}
	}
	return 0;	
} 
