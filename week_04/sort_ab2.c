/* 12:55 2015-04-07 Tuesday */
#include <stdio.h>
#include <stdlib.h>

typedef int DATATYPE;
typedef struct node
{
    DATATYPE data;
    struct node *next;
}LinkList;

LinkList *Create_LinkList()
{
    LinkList *head;

    head = (LinkList *)malloc(sizeof(LinkList));
    if (NULL == head)
    {
        printf("No free memory!\n");
        return NULL;
    }
    head->next = NULL;
    return head;
}

int Insert_tail_LinkList(LinkList *head,DATATYPE data)
{
    LinkList *p;
    LinkList *new;

    p = head;

    new = (LinkList *)malloc(sizeof(LinkList));
    if (NULL == new)
    {
        printf("No free memory!\n");
        return -1;
    }

    while (p->next)
    {
        p = p->next;
    }

    new->next = NULL;
    new->data = data;
    p->next = new;

    return 0;
}

int Print_LinkList(LinkList *head)
{
    LinkList *L;

    L = head->next;

    while (L)
    {
        printf("%d ",L->data);
        L = L->next;
    }
    return 0;
}

int Sort_ab(LinkList *a,LinkList *b)
{

    LinkList *pa,*pb;
    pa = a->next;
    pb = b->next;
   
    a->next = NULL;
    b->next = NULL;
    free(b);

     
    return 0; 
}

int main()
{
    int i;
    LinkList *q = Create_LinkList();
    LinkList *p = Create_LinkList();
    int a[] = {1,4,6,8,12};
    int b[] = {2,3,9,15};

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        Insert_tail_LinkList(q,a[i]);

    for (i = 0; i < sizeof(b)/sizeof(b[0]); i++)
        Insert_tail_LinkList(p,b[i]);

    Print_LinkList(q);
    printf("\n");
    Print_LinkList(p);
    printf("\n");
    Sort_ab(q,p);
    Print_LinkList(q);
    printf("\n");
    return 0;
}

