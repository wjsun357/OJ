#include<iostream>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;
struct layer
{
	layer* array[30];
	string name[30];
	layer* father;
	int type[30];
	int number=1;
	int l=0;
};
stack<layer> S;
string Array[30]; 
int n_Array=0;
int Count=1;
void output(layer* p)
{
	for(int i=0;i<p->l;i++)
	{
		cout<<"|     ";
	}
	cout<<p->name[0]<<endl;
	for(int i=1;i<p->number;i++)
	{
		if(p->array[i]!=NULL)
		{
			output(p->array[i]);
		}
	}
	n_Array=0;
	for(int i=1;i<p->number;i++)
	{
		if(p->array[i]==NULL)
		{
			Array[n_Array++]=p->name[i];
		}
	}
	sort(Array,Array+n_Array);
	for(int i=0;i<n_Array;i++)
	{
		for(int i=0;i<p->l;i++)
		{
			cout<<"|     ";
		}
		cout<<Array[i]<<endl;
	}
}
int main()
{
	string s;
	int flag=1;
	layer temp;
	layer* root;
	temp.father=NULL;
	temp.type[0]=0;
	temp.number=1;
	temp.l=0;
	temp.name[0]="ROOT";
	temp.array[0]=NULL;
	S.push(temp);
	root=&(S.top());
	while(cin>>s)
	{
		if(flag==1)
		{
			if(s.compare("#")==0)
			{
				break;
			}
			else
			{
				flag=0;
				temp.father=NULL;
				temp.type[0]=0;
				temp.number=1;
				temp.l=0;
				temp.name[0]="ROOT";
				temp.array[0]=NULL;
				S.push(temp);
				root=&(S.top());
				cout<<"DATA SET "<<Count<<":"<<endl;
			}
		}
		if(s.compare("*")==0)
		{
			Count++;
			flag=1;
			while(root->father!=NULL)
			{
				root=root->father;
			}
			output(root);
			cout<<endl;
			continue;
		}
		else
		{
			if(s[0]=='f')
			{
				int number=root->number;
				root->name[number]=s;
				root->type[number]=1;
				root->array[number]=NULL;
				root->number++;
			}
			else if(s[0]=='d')
			{
				int number=root->number;
				temp.father=root;
				temp.type[0]=0;
				temp.number=1;
				temp.l=(root->l)+1;
				temp.name[0]=s;
				temp.array[0]=NULL;
				S.push(temp);
				root->name[number]=s;
				root->type[number]=0;
				root->array[number]=&(S.top());
				root->number++;
				root=&(S.top());
			}
			else
			{
				root=root->father;
			}
		}
	}
	return 0;
} 
