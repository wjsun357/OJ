#include<iostream>
#include<vector>
using namespace std;
int T,N,M;
vector<int>S,P;
int Next[10001];
void getnext()
{
	int j=0;
	int k=-1;
	Next[0]=-1;
	while(j<M)
	{
		if(k==-1||P[j]==P[k])
		{
			j++;
			k++;
			Next[j]=k;
		}
		else
		{
			k=Next[k];
		}
	}
}
void kmp()
{
	int i=0;
	int j=0;
	while(i<N&&j<M)
	{
		if(j==-1||S[i]==P[j])
		{
			i++;
			j++;
		}
		else
		{
			j=Next[j];
		}
	}
	if(j==M)
	{
		cout<<i-M+1<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
}
int main()
{
	cin>>T;
	for(int i=0;i<T;i++)
	{
		S.clear();
		P.clear();
		cin>>N>>M;
		int temp;
		for(int j=0;j<N;j++)
		{
			cin>>temp;
			S.push_back(temp);
		}
		for(int j=0;j<M;j++)
		{
			cin>>temp;
			P.push_back(temp);
		}
		getnext();
		kmp();
	}
	return 0;
} 
