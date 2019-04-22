#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
struct S
{
	int l;
	string s;
	bool operator < (const S &x) const
	{
		return l<x.l;
	}
};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int COUNT=0;
		S* Array=new S[n];
		string s;
		getline(cin,s);
		for(int i=0;i<n;i++)
		{
			getline(cin,s);
			if(s.compare("stop")==0)
			{
				break;
			}
			else
			{
				S temp;
				temp.l=s.length();
				temp.s=s;
				Array[COUNT++]=temp;
			}
		}
		sort(Array,Array+COUNT);
		for(int i=0;i<COUNT;i++)
		{
			cout<<Array[i].s<<endl;
		}
	}
	return 0;
}
