#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 1100000
bool prime[MAX];
int T;
int main()
{
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	for(int i=2;i<=sqrt(MAX);i++)
	{
		if(prime[i]==true)
        {
            for(int j=i*i;j<=MAX;j+=i)
            {
            	prime[j]=false;
			}
        }
	}
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int n;
		cin>>n;
		long long count=0;
		int ln;
		for(int j=1;j<=n;j++)
		{
			cin>>ln;
			while(true)
			{
				ln++;
				if(prime[ln])
				{
					count+=ln;
					break;
				}
			}
		}
		cout<<"Case "<<i<<": "<<count<<" Xukha"<<endl;
	}
	return 0;
} 
