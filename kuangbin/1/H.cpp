#include<iostream>
#include<stack>
#include<map>
#include<cstring>
#include<string.h>
#include<queue>
#include<sstream>
using namespace std;
struct data
{
	int vi;
	int vj;
	int times;
	string order;
};
queue<data>Q;
map<string,int>M;
int A,B,C;
void bfs()
{
	while(!Q.empty())
	{
		data D=Q.front();
		Q.pop();
		int vi=D.vi;
		int vj=D.vj;
		int times=D.times;
		string order=D.order;
		if(vi==C||vj==C)
		{
			cout<<times<<endl;
			for(int i=0;i<order.size();i++)
			{
				if(order[i]=='1')
				{
					cout<<"FILL(1)"<<endl;
				}
				else if(order[i]=='2')
				{
					cout<<"FILL(2)"<<endl;
				}
				else if(order[i]=='3')
				{
					cout<<"DROP(1)"<<endl;
				}
				else if(order[i]=='4')
				{
					cout<<"DROP(2)"<<endl;
				}
				else if(order[i]=='5')
				{
					cout<<"POUR(1,2)"<<endl;
				}
				else if(order[i]=='6')
				{
					cout<<"POUR(2,1)"<<endl;
				}
			}
			return;
		}
		stringstream ss;
		ss<<vi<<"+"<<vj;
		M[ss.str()]++;
		if(M[ss.str()]<=1)
		{
			if(A>vi)
			{
				data D;
				D.vi=A;
				D.vj=vj;
				D.times=times+1;
				D.order=order+"1";
				Q.push(D);
			}
			if(B>vj)
			{
				data D;
				D.vi=vi;
				D.vj=B;
				D.times=times+1;
				D.order=order+"2";
				Q.push(D);
			}
			if(vi>0)
			{
				data D;
				D.vi=0;
				D.vj=vj;
				D.times=times+1;
				D.order=order+"3";
				Q.push(D);
			}
			if(vj>0)
			{
				data D;
				D.vi=vi;
				D.vj=0;
				D.times=times+1;
				D.order=order+"4";
				Q.push(D);
			}
			if(vi>0&&B-vj>0)
			{
				if(vi>=B-vj)
				{
					data D;
					D.vi=vi-(B-vj);
					D.vj=B;
					D.times=times+1;
					D.order=order+"5";
					Q.push(D);
				}
				else
				{
					data D;
					D.vi=0;
					D.vj=vi+vj;
					D.times=times+1;
					D.order=order+"5";
					Q.push(D);
				}
			}
			if(vj>0&&A-vi>0)
			{
				if(vj>=A-vi)
				{
					data D;
					D.vi=A;
					D.vj=vj-(A-vi);
					D.times=times+1;
					D.order=order+"6";
					Q.push(D);
				}
				else
				{
					data D;
					D.vi=vi+vj;
					D.vj=0;
					D.times=times+1;
					D.order=order+"6";
					Q.push(D);
				}
			}
		}	
	}
	cout<<"impossible"<<endl;
}
int main()
{
	cin>>A>>B>>C;
	data D;
	D.vi=0;
	D.vj=0;
	D.times=0;
	D.order="";
	Q.push(D);
	bfs();
}
