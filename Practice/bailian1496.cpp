#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int C[27][6];
char str[6];
 
void init()
{
    for(int i=0;i<=26;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=5;j++)
        {
            C[i][j] = C[i-1][j]+C[i-1][j-1];
        }
    }
}
 
void work()
{
    int ans = 1;
 
    int len = strlen(str);
    for(int i=1;i<len;i++) 
		if(str[i]<=str[i-1])
    	{
        	puts("0");
        	return;
    	}
 
    for(int i=1;i<len;i++)
        ans += C[26][i];
 
    char ch='a';
    for(int i=0;i<len;i++)
    {
        for(;ch<str[i];ch++)
        {
            ans+=C['z'-ch][len-i-1];
        }
        ch++;
    }
 
    printf("%d\n", ans);
}
 
int main()
{
    init();
    while(~scanf("%s", str))
        work();
}
