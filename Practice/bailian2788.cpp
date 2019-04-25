#include<iostream>
using namespace std;
long long m,n;
long long count=0;
void check(long long low,long long high)
{
	if(low>n)
	{
		return;
	}
	else if(high>n)
	{
		count+=n-low+1;
		return;
	}
	else
	{
		count+=high-low+1;
		check(2*low,2*high+1);
	}
}
int main()
{
	while(cin>>m>>n)
	{
		if(m==0&&n==0)
		{
			break;
		}
		else
		{
			count=0;
			check(m,m);
			cout<<count<<endl;
		}
	}
	return 0;
}
