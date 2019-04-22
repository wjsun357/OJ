#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N,K;
bool already[200000];
struct pos
{
	int x;
	int t;
};
queue<pos> Q;
int dfs()
{
	while(!Q.empty())
	{
		pos now=Q.front();
		Q.pop();
		int x=now.x;
		int t=now.t;
		if(x>=0&&x<200000)
		{
			pos temp;
			temp.x=x+1;
			temp.t=t+1;
			if(temp.x==K)
			{
				return temp.t;
			}
			else if(temp.x<200000&&already[temp.x]==false)
			{
				already[temp.x]=true;
				Q.push(temp);				
			}
			temp.x=x-1;
			temp.t=t+1;
			if(temp.x==K)
			{
				return temp.t;
			}
			else if(temp.x<200000&&already[temp.x]==false)
			{
				already[temp.x]=true;
				Q.push(temp);				
			}
			temp.x=2*x;
			temp.t=t+1;
			if(temp.x==K)
			{
				return temp.t;
			}
			else if(temp.x<200000&&already[temp.x]==false)
			{
				already[temp.x]=true;
				Q.push(temp);				
			}
			
		}
	}
}
int main()
{
	cin>>N>>K;
	if(K<=N)
	{
		cout<<N-K;
	}
	else
	{
		memset(already,false,sizeof(already));
		pos P;
		P.x=N;
		P.t=0;
		already[N]=true;
		Q.push(P);
		cout<<dfs();
	}
	return 0;
}
