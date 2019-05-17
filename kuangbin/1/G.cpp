#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>
#include<cstring>
using namespace std;
string s1,s2,s12,t;
vector<string> V;
map<string,int> M;
int N,C;
void rep(int times)
{
	s12="";
	for(int i=0;i<C;i++)
	{
		s12+=s2[i];
		s12+=s1[i];
	}
	M[s12]++;
	if(s12==t)
	{
		cout<<times<<endl;
		return;
	}
	if(M[s12]>1)
	{
		cout<<-1<<endl;
		return;
	}
	s1="";
	s2="";
	for(int i=0;i<C;i++)
	{
		s1+=s12[i];
		s2+=s12[C+i];
	}
	rep(times+1);
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>C;
		cin>>s1>>s2>>t;
		cout<<i+1<<" ";
		M.clear();
		rep(1);
	}
	return 0;	
} 
