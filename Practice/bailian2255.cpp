#include<iostream>
using namespace std;
struct node
{
	char value;
	node* left;
	node* right;
};
node array[10000];
int count=0;
void post(node* N)
{
	if(N->left!=NULL)
	{
		post(N->left);
	}
	if(N->right!=NULL)
	{
		post(N->right);
	}
	cout<<N->value;
}
node *create()
{
	array[count].left=array[count].right=NULL;
	return &array[count++];
}
node* build(string pre,string mid)
{
	node* p=create();
	if(pre.length()==1)
	{
		p->value=pre[0];
		//cout<<"MID is "<<pre[0]<<", no left or right"<<endl;
		return p;
	}
	else if(pre.length()==0)
	{
		return NULL;	
	}
	else
	{
		char middle=pre[0];
		int pos;
		for(int i=0;i<mid.length();i++)
		{
			if(mid[i]==middle)
			{
				pos=i;
				break;
			}
		}
		//cout<<"MID is "<<middle<<endl;
		//cout<<"LEFT is "<<pre.substr(1,pos)<<endl;
		//cout<<"RIGHT is "<<pre.substr(1+pos,pre.length()-pos-1)<<endl;
		p->value=middle;
		p->left=build(pre.substr(1,pos),mid.substr(0,pos));
		p->right=build(pre.substr(1+pos,pre.length()-pos-1),mid.substr(pos+1,mid.length()-pos-1));
		return p;
	}
}
int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		count=0;
		node *p=build(s1,s2);
		post(p);
		cout<<endl;
	}
	return 0;	
} 
