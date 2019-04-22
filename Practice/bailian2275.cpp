#include<iostream>
#include<algorithm>
using namespace std;
int N;
int main()
{
	while(cin>>N)
	{
		if(N==0)
		{
			break;
		}
		else
		{
			if(N==1)
			{
				int x;
				cin>>x;
				cout<<0<<endl;
				continue;
			}
			int *array=new int[N];
			int *record=new int[2*N-3];
			for(int i=0;i<2*N-3;i++)
			{
				record[i]=-1;
			}
			int Count=0;
			for(int i=0;i<N;i++)
			{
				cin>>array[i];
			}
			for(int i=N-1;i>=1;i--)
			{
				int MAX=-1;
				int POS=-1;
				for(int j=0;j<=i;j++)
				{
					if(array[j]>MAX)
					{
						POS=j;
						MAX=array[j];
					}
				}
				if(POS!=i)
				{
					if(POS==0)
					{
						reverse(array,array+i+1);
						record[Count++]=i+1;
					}
					else
					{
						reverse(array,array+POS+1);
						record[Count++]=POS+1;
						reverse(array,array+i+1);
						record[Count++]=i+1;
					}
				}
			}
			cout<<Count;
			for(int i=0;i<Count;i++)
			{
				cout<<" "<<record[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
