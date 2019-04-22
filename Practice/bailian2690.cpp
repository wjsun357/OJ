#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	char c;
	int flag=1;
	while(scanf("%c",&c)!=EOF)
	{
		if(c!=' '&&c!='\t'&&c!='\n'&&c!='\r')
		{
			if(flag==1)
			{
				cout<<(char)toupper(c);
				flag=0;
			}
			else
			{
				cout<<c;
			}
		}
		else
		{
			cout<<c;
			flag=1;
		}
	}
	return 0;
}
