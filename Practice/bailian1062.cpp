#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=105;
int d,n;
int a[maxn][maxn];
bool vis[maxn];
int level[maxn];
int dis[maxn];
void Init()
{
    memset(a,0,sizeof(a));
    for(int i=0;i<=n;i++)
    {
        vis[i]=false;
        dis[i]=INF;
        level[i]=0;
    }
}
int Dijkstra()
{
    for(int i=1;i<=n;i++)
        dis[i]=a[0][i];
    for(int i=1;i<=n;i++)
    {
        int minn=INF;
        int p=-1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<minn)
                minn=dis[p=j];
        }
        if(p==-1)
            break;
        vis[p]=true;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&a[p][j]>0&&dis[j]>dis[p]+a[p][j])
            {
                dis[j]=dis[p]+a[p][j];
            }
        }
    }
    return dis[1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("data/1062.txt","r",stdin);
    while(cin>>d>>n)
    {
        Init();
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            a[0][i]=x;
            level[i]=y;
            while(z--)
            {
                int p,q;
                cin>>p>>q;
                a[p][i]=q;
            }
        }
        int maxlv;
        int ans=INF;
        for(int i=1;i<=n;i++)
        {
            maxlv=level[i];
            //枚举交易网络中的最高等级
            for(int j=1;j<=n;j++)
            {
                if(level[j]>maxlv||maxlv-level[j]>d)
                    vis[j]=true;
                else
                    vis[j]=false;
            }
            for(int j=1;j<=n;j++)
            {
            	if(abs(level[j]-level[1])>d)
            		vis[j]=true;
			}
            int minn=Dijkstra();
            if(minn<ans)
                ans=minn;
        }
        cout<<ans<<endl;
    }
    return 0;
}
