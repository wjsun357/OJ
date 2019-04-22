#include<iostream>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
queue<int> Q1;
queue<int> Q2;
int flag=0;
void div(int k)
{
	int number=0;
	int top=0;
	Q2=Q1;
	while(!Q2.empty())
	{
		number=10*number+Q2.front();
		Q2.pop();
		top=number/k;
		number=number-top*k;
	}
	if(number==0)
	{
		if(flag==0)
		{
			flag=1;
			cout<<k;
		}
		else
		{
			cout<<" "<<k;
		}
	}
}
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		Q1.push(s[i]-'0');
	}
	for(int i=2;i<=9;i++)
	{
		div(i);
	}
	if(flag==0)
	{
		cout<<"none";
	}
	return 0;
}
