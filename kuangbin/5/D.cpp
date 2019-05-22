#include<stdio.h> 
#include<iostream>
#define MAX 200005 
using namespace std;
int father[MAX],v[MAX],n,m;
int Find(int x)
{
    if(father[x]==x)
        return x;
    int k=Find(father[x]);
    v[x]+=v[father[x]];//对v[x]进行更新
    return father[x]=k;
}
int main()
{
    int i,j,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0;
        for(i=0;i<=n;i++)
        {
            father[i]=i;
            v[i]=0;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a--;//为什么要减一？你知道了区间1-5，和6-10的和，如果你不把6减1,你如何进行下面的更新呢？
            int x=Find(a);
            int y=Find(b);
            if(x!=y)//如果发现两个根节点不相同，则进行更新
            {
                father[y]=x;
                v[y]=v[a]-v[b]+c;//由式子：v[y]=v[a]-(v[b]-c)，化简而得，自己可以画个图推一下，并不难。
            }
            else//如果根节点相同了，我们就可以进行判断了
            {
                if(v[b]-v[a]!=c)//v[b]-v[a]根据之前的条件得到的区间a-b的和，如果这个值并不等于C证明与前面矛盾。
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}//https://blog.csdn.net/qq_41619547/article/details/81487831
