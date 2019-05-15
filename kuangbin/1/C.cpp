#include<iostream>
#include<queue>
using namespace std;
queue<int> Q;
bool already[100001];
int main()
{
	int N,K;
	cin>>N>>K;
	if(N==K)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<100001;i++)
	{
		already[i]=false;
	}
	already[N]=true;
	Q.push(N);
	Q.push(0);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		int t=Q.front();
		Q.pop();
		if(x+1>=0&&x+1<=100000&&already[x+1]==false)
		{
			already[x+1]=true;
			if(x+1==K)
			{
				cout<<t+1;
				return 0;
			}
			else
			{
				Q.push(x+1);
				Q.push(t+1);
			}
		}
		if(x-1>=0&&x-1<=100000&&already[x-1]==false)
		{
			already[x-1]=true;
			if(x-1==K)
			{
				cout<<t+1;
				return 0;
			}
			else
			{
				Q.push(x-1);
				Q.push(t+1);
			}
		}
		if(2*x>=0&&2*x<=100000&&already[2*x]==false)
		{
			already[2*x]=true;
			if(2*x==K)
			{
				cout<<t+1;
				return 0;
			}
			else
			{
				Q.push(2*x);
				Q.push(t+1);
			}
		}
	}
	return 0;
}
