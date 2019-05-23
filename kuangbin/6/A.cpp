#include<iostream>
#include<queue>
using namespace std;
int n;
struct road
{
	int x;
	int y;
	int length;
};
struct cmp
{
	bool operator()(road a,road b) 
	{
		return a.length>b.length; 
	}
};
int father[27];
priority_queue<road,vector<road>,cmp> Q;
int find(int x)
{
	if(father[x]!=x)
	{
		father[x]=find(father[x]);
	}
	return father[x];
}
bool Union(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
	{
		return false;
	}
	else
	{
		father[fx]=fy;
		return true;
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
		while(!Q.empty())
		{
			Q.pop();
		}
		for(int i=1;i<=n;i++)
		{
			father[i]=i;
		}
		for(int i=1;i<=n-1;i++)
		{
			int k;
			char c;
			road r;
			cin>>c>>k;
			r.x=c-'A'+1;
			for(int j=0;j<k;j++)
			{
				cin>>c;
				r.y=c-'A'+1;
				cin>>r.length;
				if(r.x!=r.y)
					Q.push(r);
			}
		}
		int count=0;
		while(!Q.empty())
		{
			road r=Q.top();
			Q.pop();
			if(Union(r.x,r.y)==false)
			{
				continue;
			}
			else
			{
				count+=r.length;
			}
		}
		cout<<count<<endl;
	}
	return 0;	
}
