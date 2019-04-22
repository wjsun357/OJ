#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int n,t;
int main()
{
	cin>>n;
	priority_queue<int,vector<int>,greater<int>>Q;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		Q.push(t);
	}
	int ans=0;
	int a,b;
	while(Q.size()>1)
	{
		a=Q.top();
		Q.pop();
		b=Q.top();
		Q.pop();
		ans=ans+a+b;
		Q.push(a+b);
	}
	cout<<ans<<endl;
	return 0;
}

