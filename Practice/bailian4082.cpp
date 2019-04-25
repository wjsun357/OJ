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
{     //生成一个新的结点，并将其孩子结点置为NULL
    tree[loc].lchild = NULL;
    tree[loc].rchild = NULL;
    return &tree[loc++];
}
node *build()
{      //该题输入为伪满二叉树的前序遍历，利用0、1标志来识别外结点和内结点
    scanf("%s",temp);
    node *p = create();
    p->x = temp[0];
    if(temp[1] == '0' && p->x != '$')
	{
    //if(loc != n)    //因为已经给出01标志了，并且是伪满二叉树，所以这道题目的n(树的结点个数)信息冗余。
        p->lchild = build();
    //if(loc != n)
        p->rchild = build();
    }
    return p;
}
void Print(node *p)
{ //输出该树的镜像翻转
    stack<node *> s;
    queue<node *> Q;
    while(p != NULL)
	{   //此处是关键，根据“左孩子右兄弟”的特点，一直向右遍历，将树同一层的结点都放在栈内
        //printf("push:%c.",p->x);
        if(p->x != '$')
       		s.push(p);
        p = p->rchild;
    }
    while(!s.empty())
	{  //将栈内的结点依次弹出，压入队列，完成镜像翻转的功能
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
			{   //同理，上面是处理根节点的，因为那时队列还为空，这里是处理剩下的全部结点
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
