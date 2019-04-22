#include<iostream>
#include<map>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
string str;
queue<string> Q;
map<string,int> M;
string s_array[32]={"negative","zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred","thousand","million"};
int i_array[32]={-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000};
void split()
{
    char *cstr,*p;
    cstr = new char[str.size()+1];
    cstr = strcpy(cstr,str.c_str());
    p = strtok(cstr," ");//空格作为分隔符 
    while (p != NULL)
	{
        Q.push(p);
        p = strtok(NULL," ");//第一次调用后再次调用要将字符串参数置空 
    }
}
int main()
{
	for(int i=0;i<32;i++)
	{	
		M[s_array[i]]=i_array[i];
	}
	while(getline(cin,str))
	{
		if(str.empty())
		{
			break;
		}
		while(!Q.empty())
		{
			Q.pop();
		}
		string s;
		split();
		int flag=0;
		int number=0;
		int temp=0;
		while(!Q.empty())
		{
			s=Q.front();
			Q.pop();
			if(flag!=-1)
			{
				flag=M[s];
			}
			if(M[s]>=1)
			{
				if(M[s]==100)
				{
					temp*=M[s];
				}
				else if(M[s]==1000||M[s]==1000000)
				{
					temp*=M[s];
					number+=temp;
					temp=0;
				}
				else
				{
					temp+=M[s];
				}
			}
		}
		number+=temp;
		if(flag==-1)
		{
			number*=-1;
		}
		cout<<number<<endl;
	}
	return 0;
}
