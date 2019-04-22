#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
char mi[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char ming[26]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
map<char,char> M;
int main()
{
	for(int i=0;i<26;i++)
	{
		M[mi[i]]=ming[i];
	}
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(M.find(c)==M.end())
		{
			cout<<c;
		}
		else cout<<M[c];
	}
	return 0;	
} 
