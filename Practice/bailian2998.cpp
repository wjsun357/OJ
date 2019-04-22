#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
string str1;
int Count;
struct data
{
	string name;
	string day;
	string time;
	double cost;
	string total;
	bool operator < (const data &x) const
	{
		if(cost==x.cost)
		{
			if(day.compare(x.day)==0)
			{
				return time.compare(x.time)<0;
			}
			return day.compare(x.day)<0;
		}
		else
		{
			return cost<x.cost;
		}
	}
};
data Array[10000];
void split()
{
	data d;
	d.total=str1;
	int n=0;
    char *cstr,*p;
    cstr=new char[str1.size()+1];
    cstr=strcpy(cstr,str1.c_str());
    p=strtok(cstr," ");
    while(p!=NULL)
	{
		n++;
		if(n==1)
		{
			d.name=p;
		}
		if(n==2)
		{
			d.day=p;	
		}
		if(n==3)
		{
			d.time=p;
		}
		if(n==4)
		{
			string s=p;
			d.cost=atof((s.substr(0,s.length()-3)).c_str());
		}
        p=strtok(NULL," ");
    }
    Array[Count]=d;
    Count++;
}
int main()
{
	Count=0;
	while(getline(cin,str1))
	{
		if(str1.empty())
		{
			break;
		}
		split();
	}
	sort(Array,Array+Count);
	for(int i=0;i<Count;i++)
	{
		cout<<Array[i].total<<endl;
	}
	return 0;	
} 
