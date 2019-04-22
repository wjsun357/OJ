#include<iostream>
using namespace std;
int n=8;
int total=1;
int *c=new int(n+1);
int Array[93];
bool is_ok(int row)
{
    for(int j=1;j!=row;j++)
	{
        if(c[row]==c[j] || row-c[row]==j-c[j] || row+c[row]==j+c[j])
            return false;
    }
    return true;
}
void queen(int row,int number)
{
    if(row==n+1)
    {
    	Array[total++]=number;
	}
    else
        for(int col=1;col!=n+1;col++)
		{
            c[row]=col;
            if(is_ok(row))
            {
            	queen(row+1,10*number+col);
			}
        }
}
int main()
{
    queen(1,0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
    	int x;
    	cin>>x;
    	cout<<Array[x]<<endl;
	}
    return 0;
}
