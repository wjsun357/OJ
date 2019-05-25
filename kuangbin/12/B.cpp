#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int array[1000000];
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		memset(array,0,sizeof(array));
		int n;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&array[i]);
		}
		sort(array,array+N);
		printf("%d\n",array[(N-1)/2]);
	}
	return 0;
}//https://www.cnblogs.com/kuangbin/archive/2011/07/30/2122217.html
