#include<iostream>
#include<cstdio>
#include<cstring>
#define N 15
#define INF 0x3f3f3f3f
using namespace std;
char str[20][101];
int dp[1<<N],pre[1<<N],times[1<<N];
int dead[N],last[N];
void print(int x)
{//递归输出作业顺序
    if(!x)
        return;
    print(x-(1<<pre[x]));
    printf("%s\n",str[pre[x]]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s%d%d",&str[i],&dead[i],&last[i]);
        memset(times,0,sizeof(times));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<(1<<n);i++)
		{//枚举所有状态
            dp[i]=INF;//初始化状态i的扣分
            for(int j=n-1;j>=0;j--)
			{//从后向前找
                int temp1=1<<j;
                if(!(i&temp1))//状态i不存在作业j完成的情况
                    continue;
                int temp2=i-temp1;//未完成作业j的状态
                int score=times[temp2]+last[j]-dead[j];//计算扣分
                if(score<0)//最小扣分为0
                    score=0;
                if(dp[i]>dp[temp2]+score)
				{
                    dp[i]=dp[temp2]+score;//记录最小扣分
                    times[i]=times[temp2]+last[j];//到达状态i所花费的时间
                    pre[i]=j;//状态i的前驱
                }
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
        print((1<<n)-1);
    }
    return 0;
}
