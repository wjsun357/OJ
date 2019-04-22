#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		int *array=new int[k];
		for(int j=0;j<k;j++)
		{
			cin>>array[j];
		}
		int flag=0;
		for(int j=0;j<k;j++)
		{
			if(j==0)
			{
				if(array[j]!=array[j+1])
				{
					flag=1;
					cout<<j;	
				}
			}
			else if(j==k-1)
			{
				if(array[j]!=array[j-1])
				{
					if(flag==1)
						cout<<" "<<j;
					else cout<<j;	
				}
			}
			else
			{
				if((array[j-1]>array[j]&&array[j+1]>array[j])||(array[j-1]<array[j]&&array[j+1]<array[j]))
				{
					if(flag==1)
					{
						cout<<" "<<j;
					}
					else
					{
						cout<<j;
						flag=1;
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
