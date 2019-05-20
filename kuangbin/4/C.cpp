#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
const int M=1005;
int t,n,m,cas=0;
int mmp[M][M],vis[M],d[M];
void dijk()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        d[i]=mmp[1][i];
    vis[0]=1;
    for(int i=1;i<=n;i++)
    {
        int u=-1,m=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&d[j]>m)
            {
                m=d[j];
                u=j;
            }
        }
        vis[u]=1;
        for(int i=1;i<=n;i++)
        {
            if(mmp[u][i])
                d[i]=max(d[i],min(d[u],mmp[u][i]));
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
    	memset(mmp,0,sizeof(mmp));
       	int u,v,w;
       	scanf("%d%d",&n,&m);
       	for(int i=1;i<=m;i++)
       	{
           	scanf("%d%d%d",&u,&v,&w);
           	mmp[u][v]=mmp[v][u]=w;
       	}
       	dijk();
       	printf("Scenario #%d:\n",++cas);
       	printf("%d\n\n",d[n]);
    }
}
