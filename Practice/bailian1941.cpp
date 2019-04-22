#include<iostream>
#include<cmath>
#include<stack>
#include<cstring>
#include<map>
using namespace std;
stack<char**> S;
map<int,char**> M;
int main()
{
	//ios::sync_with_stdio(false);
    //cin.tie(0);
	int k;
	char** array=new char*[2];
	for(int i=0;i<2;i++)
	{
		array[i]=new char[4];
	}
	array[0][0]=' ';
	array[0][1]='/';
	array[0][2]='\\';
	array[0][3]=' ';
	array[1][0]='/';
	array[1][1]='_';
	array[1][2]='_';
	array[1][3]='\\';
	S.push(array);
	M[1]=S.top();
	for(int i=2;i<=10;i++)
	{
		char** temp=new char*[(int)pow(2,i)];
		for(int j=0;j<pow(2,i);j++)
		{
			temp[j]=new char[(int)pow(2,i+1)];
		}
		for(int m=0;m<pow(2,i);m++)
		{
			for(int n=0;n<pow(2,i+1);n++)
			{
				temp[m][n]=' ';				
			}
		}
		char** last=S.top();
		for(int m=0;m<pow(2,i-1);m++)
		{
			for(int n=pow(2,i-1);n<pow(2,i)+m+1;n++)
			{
				temp[m][n]=last[m][n-(int)pow(2,i-1)];
			}
		}
		for(int m=pow(2,i-1);m<pow(2,i);m++)
		{
			for(int n=0;n<pow(2,i-1)+m-pow(2,i-1)+1;n++)
			{
				temp[m][n]=last[m-(int)pow(2,i-1)][n];
			}
		}
		for(int m=pow(2,i-1);m<pow(2,i);m++)
		{
			for(int n=pow(2,i);n<pow(2,i)+m+1;n++)
			{
				temp[m][n]=last[m-(int)pow(2,i-1)][n-(int)pow(2,i)];
			}
		}
		S.push(temp);
		M[i]=S.top();
	}
	while(cin>>k)
	{
		if(k==0)
		{
			break;
		}
		else
		{
			char** output=M[k];
			for(int i=0;i<pow(2,k);i++)
			{
				for(int j=0;j<pow(2,k)+i+1;j++)
				{
					cout<<output[i][j];
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}	
}
