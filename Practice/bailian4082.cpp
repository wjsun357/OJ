#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    char x;
    node *lchild;
    node *rchild;
}tree[1002];
int loc,n;
char temp[3];
node* create()
{     //����һ���µĽ�㣬�����亢�ӽ����ΪNULL
    tree[loc].lchild = NULL;
    tree[loc].rchild = NULL;
    return &tree[loc++];
}
node *build()
{      //��������Ϊα����������ǰ�����������0��1��־��ʶ��������ڽ��
    scanf("%s",temp);
    node *p = create();
    p->x = temp[0];
    if(temp[1] == '0' && p->x != '$')
	{
    //if(loc != n)    //��Ϊ�Ѿ�����01��־�ˣ�������α�������������������Ŀ��n(���Ľ�����)��Ϣ���ࡣ
        p->lchild = build();
    //if(loc != n)
        p->rchild = build();
    }
    return p;
}
void Print(node *p)
{ //��������ľ���ת
    stack<node *> s;
    queue<node *> Q;
    while(p != NULL)
	{   //�˴��ǹؼ������ݡ��������ֵܡ����ص㣬һֱ���ұ���������ͬһ��Ľ�㶼����ջ��
        //printf("push:%c.",p->x);
        if(p->x != '$')
       		s.push(p);
        p = p->rchild;
    }
    while(!s.empty())
	{  //��ջ�ڵĽ�����ε�����ѹ����У���ɾ���ת�Ĺ���
        Q.push(s.top());
        s.pop();
    }
    while(!Q.empty())
	{
        p = Q.front();
        Q.pop();
        printf("%c ",p->x);
        if(p->lchild != NULL)
		{
            p = p->lchild;
            while(p != NULL)
			{   //ͬ�������Ǵ�����ڵ�ģ���Ϊ��ʱ���л�Ϊ�գ������Ǵ���ʣ�µ�ȫ�����
                //printf("push:%c\n",p->x);
                if(p->x != '$')
                	s.push(p);
                p = p->rchild;
            }
            while(!s.empty())
			{
                Q.push(s.top());
                s.pop();
            }
        }
    }
    return;
}
int main()
{
    loc = 0;
    scanf("%d",&n);
    node *root;
    root = build();
    Print(root);
    return 0;
}
