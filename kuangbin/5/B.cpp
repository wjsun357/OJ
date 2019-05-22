#include<iostream>
using namespace std;
int m,n,x,sum,parent[30001],a[30001];
void set()
{
    for(int i=0;i<=m;i++)
        parent[i]=i;
}
int find(int a)
{
    if(parent[a]==a)
        return a;
    else
        return parent[a]=find(parent[a]);
}
void Union(int a,int b)
{
    int t1=find(a);
    int t2=find(b);
    if(t1!=t2)
        parent[t1]=t2;
}
int main()
{
    while(cin>>m>>n)
    {
        if(m==0&&n==0)
            return 0;
        set();
        for(int i=0;i<n;i++)
        {
            cin>>x;
            for(int i=0;i<x;i++)
                cin>>a[i];
            for(int j=1;j<x;j++)
                Union(a[j-1],a[j]);
        }
        sum=0;
        for(int i=0;i<m;i++)
            if(find(parent[0])==find(parent[i]))
                sum++;
        cout<<sum<<endl;
    }
}
