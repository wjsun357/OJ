#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int Maxn=1000;
int f[Maxn],vis[Maxn];
string s;
int p[Maxn],w1[Maxn],w0[Maxn];
bool used[Maxn];
int dp[Maxn][Maxn];
int Find(int x)
{
    if(x!=f[x])
	{
        int k=f[x];
        f[x]=Find(f[x]);
        vis[x]=(vis[x]+vis[k])%2;
    }
    return f[x];
}
int main()
{
    int n,p1,p2,a,b;
    while(scanf("%d%d%d",&n,&p1,&p2)&&n+p1+p2!=0)
	{
        memset(dp,0,sizeof(dp));
        int t=0;
        for(int i=0;i<=p1+p2;i++) 
        {
        	f[i]=i; 
			vis[i]=0;
			w1[i]=0;
			w0[i]=0;
			used[i]=false;
		}
        while(n--)
		{
            cin>>a>>b>>s;
            int ta=Find(a);
            int tb=Find(b);
            if(ta!=tb)
			{
                f[ta]=tb;
                if(s[0]=='y') 
					vis[ta]=(vis[a]+vis[b])%2;
                else 
					vis[ta]=(vis[a]+vis[b]+1)%2;
            }
        }
        // 求出每个集合包括两个小集合的个数
        int cnt=1;
        for(int i=1;i<=p1+p2;i++)
		{
            if(!used[i])
			{
                int t=Find(i);
                for(int j=i;j<=p1+p2;j++)
				{
                    if(Find(j)==t&&!used[j])
					{
                        used[j]=true;
                        if(!vis[j]) 
							w0[cnt]++;//w0为与根相同 
                        else 
							w1[cnt]++;//w1为与根不同 
                    }
                }
                p[cnt]=t; // 将集合的根结点存起来
                cnt++;
            }
        }
        dp[0][0]=1;//前i个大集合中，能得到和为j的组合数 
        for(int i=1;i<cnt;i++)//对于每个大集合 
		{
            int Min=min(w0[i],w1[i]);//选取较少的小集合数以缩小范围 
            for(int j=p1;j>=Min;j--)
			{
                if(dp[i-1][j-w0[i]]) 
					dp[i][j]+=dp[i-1][j-w0[i]];
                if(dp[i-1][j-w1[i]]) 
					dp[i][j]+=dp[i-1][j-w1[i]];
            }
        }
        if(dp[cnt-1][p1]!=1)
		{
            printf("no\n");
            continue;
        }
        int ans[1000];
        int num=0;
        int flag=p1;
        for(int i=cnt-1;i>=1;i--)
		{
            if(dp[i-1][flag-w0[i]]==1)
			{
                for(int j=1;j<=p1+p2;j++)
                  	if(Find(j)==p[i]&&vis[j]==0) 
				  		ans[num++]=j;
                flag-=w0[i];
            }
            else
			{
                for(int j=1;j<=p1+p2;j++)
                  	if(Find(j)==p[i]&&vis[j]==1) 
					  	ans[num++]=j;
                flag-=w1[i];
            }
        }
        sort(ans,ans+num);
        for(int i=0;i<num;i++) 
			printf("%d\n",ans[i]);
        cout<<"end\n";
    }
    return 0;
}
