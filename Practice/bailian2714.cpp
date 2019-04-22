#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double count=0;
	int age;
	for(int i=0;i<n;i++)
	{
		cin>>age;
		count+=age;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<count/n;
	return 0;
}
