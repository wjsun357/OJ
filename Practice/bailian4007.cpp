#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int N;
int Min(int a,int b,int c)
{
	if(a>b)
	{
		if(b>c)
		{
			return c;
		}
		else
		{
			return b;
		}
	}
	else
	{
		if(a>c)
		{
			return c;
		}
		else
		{
			return a;
		}
	}
}
int main()
{
	cin>>N;
	string s1,s2;
	for(int i=1;i<=N;i++)
	{
		cin>>s1>>s2;
		int l1=s1.length();
		int l2=s2.length();
		int F[l1+1][l2+1];
		memset(F,0,sizeof(F));
		for(int i=0;i<=l1;i++)
		{
			F[i][0]=i;
		}
		for(int i=0;i<=l2;i++)
		{
			F[0][i]=i;
		}
		for(int m=1;m<=l1;m++)
		{
			for(int n=1;n<=l2;n++)
			{
				if(s1.at(m-1)==s2.at(n-1))
				{
					F[m][n]=F[m-1][n-1];
				}
				else
				{
					F[m][n]=Min(F[m-1][n],F[m][n-1],F[m-1][n-1])+1;
				}
			}
		}
		cout<<F[l1][l2]<<endl;
	}
}
