/*
#include<iostream>
using namespace std;
int n;
int ans[100];
bool Find;
void dfs(int num,int l)
{
	if(Find==true||l>20)
	{
		return;
	}
	else
	{
		if(num==0)
		{
			for(int i=0;i<=l;i++)
			{
				cout<<ans[i];
			}
			cout<<endl;
			Find=true;
			return;
		}
		else
		{
			ans[l+1]=1;
			dfs((10*num+1)%n,l+1);
			ans[l+1]=0;
			dfs((10*num)%n,l+1);
		}
	}
}
int main()
{
	while(cin>>n)
	{
		if(n==0)
		{
			break;
		}
		else
		{
			Find=false;
			ans[0]=1;
			dfs(1%n,0);
		}
	}
	return 0;
}
*/
# include <stdio.h>
# include <queue>
using namespace std;
int m;
void BFS(long long x)
{
    queue<long long>Q;
    Q.push(x);
    while(Q.size()) 
    {
        long long  y = Q.front();
        Q.pop();
        if(y%m == 0)
        {
            printf("%lld\n",y);
            return;
        }
        Q.push(y*10);
        Q.push(y*10+1);
    }
}
int main(void)
{
    while(~scanf("%d",&m),m)
    {
        BFS(1);
    }   
    return 0;
} 

