#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>
#include<string.h>
#include<iomanip>
using namespace std;
int main()
{
	string s;
	int count=0;
	while(count<=1)
	{
		count++;
		getline(cin,s);
		stack<char>op;
		stack<double>num;
		s="# "+s+" #";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!=' ')
			{
				int temp=0;
				while(true)
				{
					if(s[i]==' ')
					{
						num.push((double)temp);
						break;
					}
					else if(s[i]-'0'>=0&&s[i]-'0'<=9)
					{
						temp*=10;
						temp+=s[i]-'0';
						i++;
						continue;
					}
					else
					{
						if(s[i]=='*'||s[i]=='/')
						{
							while(true)
							{
								if(op.empty())
								{
									op.push(s[i]);
									break;
								}
								char c=op.top();
								if(c=='*'||c=='/')
								{
									double b=num.top();
									num.pop();
									double a=num.top();
									num.pop();
									double cal;
									op.pop();
									if(c=='*')
									{
										cal=a*b;
									}
									else
									{
										cal=a/b;
									}
									num.push(cal);
								}
								else
								{
									op.push(s[i]);
									break;
								}
							}
						}
						else if(s[i]=='+'||s[i]=='-')
						{
							while(true)
							{
								if(op.empty())
								{
									op.push(s[i]);
									break;
								}
								char c=op.top();
								if(c!='#')
								{
									double b=num.top();
									num.pop();
									double a=num.top();
									num.pop();
									double cal;
									op.pop();
									if(c=='*')
									{
										cal=a*b;
									}
									else if(c=='/')
									{
										cal=a/b;
									}
									else if(c=='+')
									{
										cal=a+b;
									}
									else if(c=='-')
									{
										cal=a-b;
									}
									num.push(cal);
								}
								else
								{
									op.push(s[i]);
									break;
								}
							}
						}
						else
						{
							while(true)
							{
								if(op.empty())
								{
									op.push(s[i]);
									break;
								}
								char c=op.top();
								if(c!='#')
								{
									double b=num.top();
									num.pop();
									double a=num.top();
									num.pop();
									double cal;
									op.pop();
									if(c=='*')
									{
										cal=a*b;
									}
									else if(c=='/')
									{
										cal=a/b;
									}
									else if(c=='+')
									{
										cal=a+b;
									}
									else if(c=='-')
									{
										cal=a-b;
									}
									num.push(cal);
								}
								else
								{
									op.push(s[i]);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<num.top()<<endl;
	}
	return 0;
} 
