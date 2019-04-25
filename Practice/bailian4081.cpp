#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int father[10000];
int dep[10000];
int main()
{
	string s;
	int l;
	while(cin>>s)
	{
		int depth=0;
		int MAX_depth=0;
		int count=0;
		int last=0;
		father[0]=-1;
		dep[0]=0;
		l=s.length();
		for(int i=0;i<l;i++)
		{
			if(s[i]=='d')
			{
				depth++;
				count++;
				if(MAX_depth<depth)
				{
					MAX_depth=depth;
				}
				father[count]=last;
				//dep[count]=depth;
				//cout<<last<<" Down to "<<count<<endl;
				last=count;
			}
			else
			{
				depth--;
				//cout<<last<<" up to "<<father[last]<<endl;
				last=father[last];
			}
		}
		cout<<MAX_depth<<" => ";
		for(int i=1;i<=count;i++)
		{
			int flag=0;
			for(int j=i-1;j>=1;j--)
			{
				if(father[i]==father[j])
				{
					flag=1;
					dep[i]=dep[j]+1;
					break;
				}
			}
			if(flag==0)
			{
				dep[i]=dep[father[i]]+1;
			}
			//cout<<father[i]<<endl;
		}
		int MAX=0;
		for(int i=1;i<=count;i++)
		{
			if(MAX<dep[i])
			{
				MAX=dep[i];
			}
		}
		cout<<MAX<<endl;
	}
	return 0;
} 
