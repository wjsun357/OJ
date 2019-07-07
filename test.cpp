#include<iostream>
#include<queue>
using namespace std;
int n;
struct data
{
	vector<int> V;
	int num;
};
queue<data>Q;
bool cst(vector<int> array)
{
	for(int i=0;i<n-1;i++)
	{
		if(array[i]>=array[i+1])
		{
			return false;
		}
	}
	return true;
}
void bfs()
{
	while(!Q.empty())
	{
		data temp=Q.front();
		Q.pop();
		if(cst(temp.V))
		{
			cout<<temp.num<<endl;
			return;
		}
		for(int i=0;i<n-1;i++)
		{
			if(temp.V[i]>=temp.V[i+1])
			{
				data temp1=temp;
				data temp2=temp;
				temp1.V[i]-=1;
				temp2.V[i+1]+=1;
				temp1.num+=1;
				temp2.num+=1;
				Q.push(temp1);
				Q.push(temp2);
			}
		}
	}
}
int main()
{
	cin>>n;
	vector<int>V;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		V.push_back(temp);
	}
	data temp;
	temp.num=0;
	temp.V=V;
	Q.push(temp);
	bfs();
} 
