#include<iostream> 
#include<cstdio> 
using namespace std; 
int father[50000]; 
int find(int x) 
{ 
	if(father[x]==x)	
		return father[x]; 
	father[x]=find(father[x]); 
	return father[x]; 
} 
int main() 
{ 
	int n,m,now=0; 
	while(cin>>n>>m&&m!=0&&n!=0) 
	{ 
		int ans=0;	
		now++; 
		for(int i=1;i<=n;i++)	
			father[i]=i; 
		for(int i=1;i<=m;i++) 
		{ 
			int x,y;
			cin>>x>>y; 
			father[find(x)]=find(y); 
		} 
		for(int i=1;i<=n;i++) 
			if(father[i]==i)	
				ans++; 
		cout<<"Case "<<now<<": "<<ans<<endl;
	} 
	return 0; 
}
