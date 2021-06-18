#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void Creatlist(LinkList &L)
{//集合的创建
    LinkList p,pre;
    int i,len;
    int flag[100]={0};
    printf("元素个数:\n");
    scanf("%d",&len);
    srand(time(0));
    L=(LinkList)malloc(sizeof(LNode));
    pre=L;
    for(i=0;i<len;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        while(1)
        {
            p->data=rand()%89+10;
            if(!flag[p->data])
            {
                flag[p->data]=1;
                break;
            }
        }
        pre->next=p;
        pre=p;
    }
    pre->next=NULL;
}

void Display(LinkList &L)
{
    LinkList p;
    p=L->next;
    if (!p)
    {
        printf("failed!");
    }
    else
    {
        while(p)
        {
            if (p->data!=0)
                printf("%d ",p->data);
            p=p->next;
        }
    }
    printf("\n");
}

void Insert(LinkList &L,int m)
{
    LinkList p,r;
    r=L;
    while(r->next && r->next->data<m)
        r=r->next;
    p=(LinkList)malloc(sizeof(LNode));
    p->data=m;
    p->next=r->next;
    r->next=p;
}

void Sort(LinkList &L)
{
    LinkList q,r;
    q=L->next;
    L->next=NULL;
    while(q)
    {
        Insert(L,q->data);
        r=q;
        q=q->next;
        free(r);
    }
}

void Merge(LinkList La,LinkList Lb,LinkList &Lc)
{
    LinkList p,q;
    Sort(La);
    Sort(Lb);
    p=La->next;
    q=Lb->next;
    Lc=(LinkList)malloc(sizeof(LNode));
    Lc->next=NULL;
    while(p && q)
    {
        if(p->data<q->data)
        {
            Insert(Lc,p->data);
            p=p->next;
        }
        else if(p->data>q->data)
        {
            Insert(Lc,q->data);
            q=q->next;
        }
        else
        {
            Insert(Lc,p->data);
            p=p->next;
            q=q->next;
        }
    }
    while(p)
    {
        Insert(Lc,p->data);
        p=p->next;
    }
    while(q)
    {
        Insert(Lc,q->data);
        q=q->next;
    }
    printf("两个集合的并集是:\n");
    Display(Lc);
}

void InterList(LinkList La,LinkList Lb,LinkList &Lc)
{
    LinkList cur1,cur2,cur;
    Lc=(LinkList)malloc(sizeof(LNode));
    Lc->next=NULL;
    cur1=La->next;
    cur2=Lb->next;
    cur=Lc;
    while(cur1 && cur2)
    {
        if(cur1->data>cur2->data)
            cur2=cur2->next;
        else if(cur1->data<cur2->data)
            cur1=cur1->next;
        else
        {
            cur->next=(LinkList)malloc(sizeof(LNode));
            cur=cur->next;
            cur->next=NULL;
            cur->data=cur2->data;
            cur1=cur1->next;
            cur2=cur2->next;
        }
    }
    cur->next=NULL;
    if(Lc->next==NULL)
        printf("两个集合交集为空。\n");
    else
    {
        printf("两个集合交集为：\n");
        Display(Lc);
    }
}

void Diffset(LinkList La,LinkList Lb,LinkList &Lc)
{
    LinkList pa,pb,pc,s;
    Lc=La;
    pa=La->next;pb=Lb->next;pc=Lc;
    while(pa&&pb)
    {
        if(pa->data==pb->data)
        {
            s=pa;pa=pa->next;free(s);
            while(pa&&(pa->data==pb->data))
            {
                s=pa;pa=pa->next;free(s);
            }
        }
        else if(pa->data<pb->data)
        {
            pc->next=pa;pc=pa;pa=pa->next;
        }
        else
        {
            s=pb;pb=pb->next;free(s);
        }
    }
    if(!pa)
    {
        while(pb)
        {
            s=pb;pb=pb->next;free(s);
        }
        pc->next=0;
    }
    else
        pc->next=pa;
    free(Lb);
    printf("两个集合的差集是:\n");
    Display(La);
}