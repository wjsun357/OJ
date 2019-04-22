#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string s;
int length;
bool already[6];
char record[6];
int count=0;
void dfs(int k)
{
	if(count==length)
	{
		record[count-1]=s.at(k);
		for(int i=0;i<length;i++)
		{
			cout<<record[i];
		}
		cout<<endl;
		return;
	}
	else
	{
		record[count-1]=s.at(k);
	}
	for(int i=0;i<length;i++)
	{
		if(already[i]==false)
		{
			already[i]=true;
			count++;
			dfs(i);
			count--;
			already[i]=false;
		}
	}
}
int main()
{
	cin>>s;
	length=s.length();
	for(int i=0;i<6;i++)
	{
		already[i]=false;
	}
	for(int i=0;i<length;i++)
	{
		already[i]=true;
		count++;
		dfs(i);
		count--;
		already[i]=false;
	}
	return 0;
}
