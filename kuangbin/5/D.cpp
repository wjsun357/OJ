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
    v[x]+=v[father[x]];//��v[x]���и���
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
            a--;//ΪʲôҪ��һ����֪��������1-5����6-10�ĺͣ�����㲻��6��1,����ν�������ĸ����أ�
            int x=Find(a);
            int y=Find(b);
            if(x!=y)//��������������ڵ㲻��ͬ������и���
            {
                father[y]=x;
                v[y]=v[a]-v[b]+c;//��ʽ�ӣ�v[y]=v[a]-(v[b]-c)��������ã��Լ����Ի���ͼ��һ�£������ѡ�
            }
            else//������ڵ���ͬ�ˣ����ǾͿ��Խ����ж���
            {
                if(v[b]-v[a]!=c)//v[b]-v[a]����֮ǰ�������õ�������a-b�ĺͣ�������ֵ��������C֤����ǰ��ì�ܡ�
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}//https://blog.csdn.net/qq_41619547/article/details/81487831
