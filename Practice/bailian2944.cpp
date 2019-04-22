#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<string.h>
using namespace std;
string s;
queue<string> Q;
int count=0;
map<string,string> M;
void split()
{
	char *cstr,*p;
	cstr=new char[s.size()+1];
	cstr=strcpy(cstr,s.c_str());
	p=strtok(cstr," ");
	while(p!=NULL)
	{
		Q.push(p);
		count++;
		p=strtok(NULL," ");
	}
}
int main()
{
	getline(cin,s);
	split();
	string s1,s2;
	cin>>s1>>s2;
	M[s1]=s2;
	while(!Q.empty())
	{
		count--;
		string s=Q.front();
		Q.pop();
		if(M.find(s)==M.end())
		{
			cout<<s;
		}
		else
			cout<<M[s];
		if(count!=0)
		{
			cout<<" ";
		}
	}
	return 0;
}
