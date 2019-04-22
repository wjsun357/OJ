#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
int count=0;
struct node
{
	node* left;
	node* right;
	double value;
};
stack<node> store;
void Pre(node* N)
{
	count--;
	if(count!=0)
	{
		cout<<N->value<<" ";
	}
	else cout<<N->value;
	if(N->left!=NULL)
	{
		Pre(N->left);
	}
	if(N->right!=NULL)
	{
		Pre(N->right);
	}
}
void build(node* N,double x)
{
	if(x>N->value)
	{
		if(N->right==NULL)
		{
			node tmp;
			node* p;
			tmp.left=NULL;
			tmp.right=NULL;
			tmp.value=x;
			store.push(tmp);
			p=&(store.top());
			N->right=p;
		}
		else
		{
			build(N->right,x);
		}
	}
	else if(x<N->value)
	{
		if(N->left==NULL)
		{
			node tmp;
			node* p;
			tmp.left=NULL;
			tmp.right=NULL;
			tmp.value=x;
			store.push(tmp);
			p=&(store.top());
			N->left=p;
		}
		else
		{
			build(N->left,x);
		}
	}
}
int main()
{
	double x;
	vector<double>tree;
	//while(cin>>x)
	while(scanf("%lf",&x)!=EOF)
	{
		count++;
		tree.push_back(x);
		//if(cin.get()=='\n') 
			//break;
	}
	node* begin;
	node tmp;
	tmp.left=NULL;
	tmp.right=NULL;
	tmp.value=tree[0];
	begin=&tmp;
	for(int i=1;i<tree.size();i++)
	{
		build(begin,tree[i]);
	}
	Pre(begin);
	return 0;	
}
