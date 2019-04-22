#include<iostream>
#include<iomanip>
using namespace std;
int N,K,Max;
int cable[10001];
int cut(int left,int right)
{
	int l=(left+right)/2;
	if(l<1)
		return 0;
	int count=0;
	for(int i=1;i<=N;i++)
	{
		count+=cable[i]/l;
	}
	if(count>=K)
	{
		if(l+1==right)
			return l;
		else
			cut(l,right);
	}
	else
	{
		cut(left,l);
	}
}
int main()
{
	cin>>N>>K;
	Max=0;
	double temp;
	for(int i=1;i<=N;i++)
	{
		cin>>temp;
		cable[i]=temp*100;
		Max=max(Max,cable[i]);
	}
	double result=cut(0,Max+1)/100.0;
	cout<<setiosflags(ios::fixed) << setprecision(2)<<result;
	return 0;	
}
 
