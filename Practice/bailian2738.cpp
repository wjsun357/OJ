#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
using namespace std;
struct number
{
	int left[105]; 
	int right[105];
	int lsize;
	int rsize;
};
void ADD(number n1,number n2)
{
	int carry=0;
	int rstore[105];
	int lstore[105];
	memset(rstore,0,sizeof(rstore));
	memset(lstore,0,sizeof(lstore));
	for(int i=104;i>=0;i--)
	{
		rstore[i]=(n1.right[i]+n2.right[i]+carry)%10;
		carry=(n1.right[i]+n2.right[i]+carry)/10;
	}
	for(int i=104;i>=0;i--)
	{
		lstore[i]=(n1.left[i]+n2.left[i]+carry)%10;
		carry=(n1.left[i]+n2.left[i]+carry)/10;
	}
	int pos=104;
	for(int i=0;i<=104;i++)
	{
		if(lstore[i]!=0)
		{
			pos=i;
			break;
		}		
	}
	for(int i=pos;i<=104;i++)
	{
		cout<<lstore[i];
	}
	cout<<'.';
	for(int i=104;i>=0;i--)
	{
		if(rstore[i]!=0)
		{
			pos=i;
			break;
		}		
	}
	for(int i=0;i<=pos;i++)
	{
		cout<<rstore[i];
	}
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int l1,l2;
	l1=s1.length();
	l2=s2.length();
	int pos1,pos2;
	number n1,n2;
	memset(n1.left,0,sizeof(n1.left));
	memset(n1.right,0,sizeof(n1.right));
	memset(n2.left,0,sizeof(n2.left));
	memset(n2.right,0,sizeof(n2.right));
	for(int i=0;i<l1;i++)
	{
		if(s1.at(i)=='.')
		{
			pos1=i;
			break;
		}
	}
	for(int i=0;i<l1;i++)
	{
		if(i<pos1)
		{
			n1.left[104-(pos1-1-i)]=s1.at(i)-'0';
			n1.lsize++;
		}
		else if(i>pos1)
		{
			n1.right[i-pos1-1]=s1.at(i)-'0';
			n1.rsize++;
		}
	}
	for(int i=0;i<l2;i++)
	{
		if(s2.at(i)=='.')
		{
			pos2=i;
			break;
		}
	}
	for(int i=0;i<l2;i++)
	{
		if(i<pos2)
		{
			n2.left[104-(pos2-i-1)]=s2.at(i)-'0';
			n2.lsize++;
		}
		else if(i>pos2)
		{
			n2.right[i-pos2-1]=s2.at(i)-'0';
			n2.rsize++;
		}
	}
	ADD(n1,n2);
} 
