#include<iostream>
#include<string>
#include<string.h>
using namespace std;
struct number
{
	int array[40];
	int length=0;
};
void product(number n1,number n2)
{
	int total[80];
	for(int i=0;i<80;i++)
	{
		total[i]=0;
	}
	int array1[81];
	int array[81];
	for(int i=0;i<81;i++)
	{
		array[i]=0;
	}
	int carry1=0;
	for(int i=0;i<n1.length;i++)
	{
		carry1=0;
		int begin=i;
		for(int j=0;j<81;j++)
		{
			array1[j]=0;
		}
		for(int j=0;j<n2.length;j++)
		{
			array1[begin]=(n1.array[i]*n2.array[j]+carry1)%10;
			carry1=(n1.array[i]*n2.array[j]+carry1)/10;
			begin++;
		}
		array1[i+n2.length]=carry1;
		int carry2=0;
		for(int j=0;j<81;j++)
		{	
			int SUM=carry2+array[j]+array1[j];
			array[j]=SUM%10;
			carry2=SUM/10;
		}
	}
	int flag=0;
	for(int i=80;i>=0;i--)
	{
		if(flag==0&&array[i]!=0)
		{
			flag=1;
		}
		if(flag==1)
		{
			cout<<array[i];
		}
	}
}
int main()
{
	string s1,s2;
	number n1,n2;
	cin>>s1>>s2;
	int l1,l2;
	l1=s1.length();
	l2=s2.length();
	for(int i=l1-1;i>=0;i--)
	{
		n1.array[n1.length]=s1.at(i)-'0';
		n1.length++;	
	}
	for(int i=l2-1;i>=0;i--)
	{
		n2.array[n2.length]=s2.at(i)-'0';
		n2.length++;	
	}
	product(n1,n2);
} 
