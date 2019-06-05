#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAXN 1000050
char s[MAXN];
char t[MAXN];
int l1,l2;
int nxt[MAXN];
void getnxt()
{
	int j,k;
	j=0;
	k=-1;
	nxt[0]=-1;
	while(j<l2)
	{
		if(k==-1||t[j]==t[k])
		{
			nxt[++j]=++k;
		}
		else k=nxt[k];
	}
 } 
int kmpcount()
{
	int ans=0;
	int i=0;
	int j=0;
	if(l1==1&&l2==1)
	{
		if(s[0]==t[0])
		return 1;
		else return 0;
	}
	getnxt();
	for(i=0;i<l1;i++)
	{
		while(j>0&&s[i]!=t[j])
		{
			j=nxt[j];
		}
		if(s[i]==t[j])
		{
			j++;
		}
		if(j==l2)
		{
			ans++;
			j=nxt[j];
		}
	}
	return ans;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>t>>s;
		l1=strlen(s);
		l2=strlen(t);
		cout<<kmpcount()<<endl;
	}
	return 0;
}
