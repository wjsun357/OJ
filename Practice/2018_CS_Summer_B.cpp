#include<iostream>
#include<string.h>
using namespace std;
bool isP(string s)
{
	int len=s.length();
	const char* x=s.c_str();
	for(int i=0;i<len/2;i++)
	{
		if(x[i]!=x[len-1-i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int maxlen=0;
		string maxs;
		char s[100];
		string news;
		cin>>s;
		for(int j=0;j<strlen(s)-1;j++)
		{
			for(int k=j+1;k<strlen(s);k++)
			{
				news=s;
				news=news.substr(j,k-j);
				if(isP(news))
				{
					if(k-j>maxlen)
					{
						maxs=news;
						maxlen=k-j;
					}
				}
			}
		}
		cout<<maxs<<endl;
	}
	return 0;
}
