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
{//�ݹ������ҵ˳��
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
		{//ö������״̬
            dp[i]=INF;//��ʼ��״̬i�Ŀ۷�
            for(int j=n-1;j>=0;j--)
			{//�Ӻ���ǰ��
                int temp1=1<<j;
                if(!(i&temp1))//״̬i��������ҵj��ɵ����
                    continue;
                int temp2=i-temp1;//δ�����ҵj��״̬
                int score=times[temp2]+last[j]-dead[j];//����۷�
                if(score<0)//��С�۷�Ϊ0
                    score=0;
                if(dp[i]>dp[temp2]+score)
				{
                    dp[i]=dp[temp2]+score;//��¼��С�۷�
                    times[i]=times[temp2]+last[j];//����״̬i�����ѵ�ʱ��
                    pre[i]=j;//״̬i��ǰ��
                }
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
        print((1<<n)-1);
    }
    return 0;
}
