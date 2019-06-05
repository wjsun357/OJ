#include<iostream>
using namespace std;
int T,N,M;
int array_N[1000001];
int array_M[10001];
int Move[2000005];
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>N>>M;
		for(int i=-1000000;i<=1000000;i++)
		{
			Move[i+1000001]=M;
		}
		int k;
		for(int i=1;i<=N;i++)
		{
			cin>>array_N[i];
		}
		for(int i=1;i<=M;i++)
		{
			cin>>array_M[i];
		}
		for(int i=1;i<=M-1;i++)
		{
			Move[array_M[i]+1000001]=M-i;
		}
		int s=M;
		int flag=0;
		while(s<=N)
		{
			int count=0;
			while(count<M&&array_M[M-count]==array_N[s-count])
			{
				count++;
			}
			if(count==M)
			{
				flag=1;
				cout<<s-count+1<<endl;
				break;
			}
			else
			{
				s+=Move[array_N[s]+1000001];
			}
		}
		if(flag==0)
		{
			cout<<-1<<endl;
		}
	}
}//https://blog.csdn.net/u011564456/article/details/20862555 
//https://www.cnblogs.com/zhangtianq/p/5839909.html
//https://www.cnblogs.com/yjiyjige/p/3263858.html#!comments 
