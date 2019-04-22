#include<iostream>
using namespace std;
bool year(int x)
{
	if(x%4==0)
	{
		if(x%100==0)
		{
			if(x%400==0)
			{
				return true;
			}
			return false;
		}
		return true;
	}
}
int main()
{
	int ay,am,ad,by,bm,bd;
	int count=0;
	cin>>ay>>am>>ad>>by>>bm>>bd;
	int month1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int month2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	if(by>ay)
	{
		int month[12];
		if(year(ay))
		{
			count+=month2[am-1]-ad;
			for(int i=am;i<12;i++)
			{
				count+=month2[i];
			}
		}
		else 
		{
			count+=month1[am-1]-ad;
			for(int i=am;i<12;i++)
			{
				count+=month1[i];
			}
		}
		for(int i=ay+1;i<by;i++)
		{
			if(year(i))
			{
				count+=366;
			}
			else count+=365;
		}
		if(year(by))
		{
			for(int i=0;i<=bm-2;i++)
			{
				count+=month2[i];
			}
		}
		else 
		{
			for(int i=0;i<=bm-2;i++)
			{
				count+=month1[i];
			}
		}
		count+=bd;
		cout<<count; 
	}
	else
	{
		if(bm>am)
		{
			if(year(by))
			{
				count+=month2[am-1]-ad;
				for(int i=am;i<=bm-2;i++)
				{
					count+=month2[i];
				}
			}
			else
			{
				count+=month1[am-1]-ad;
				for(int i=am;i<=bm-2;i++)
				{
					count+=month1[i];
				}
			}
			count+=bd;
			cout<<count;
		}
		else
		{
			cout<<bd-ad;
		}
	}
	return 0;
}
