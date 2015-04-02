/* 19:28 2015-04-02 Thursday */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int DATATYPE;
typedef struct
{
    DATATYPE data[MAX]; 
    int n;
}SeqList;

SeqList * Create_SeqList();
int Insert_SeqList(SeqList *L,int data);
int Printf_SeqList(SeqList *L);
int Delete_SeqList(SeqList *L,int data);
int Modifi_SeqList(SeqList *L,int n,int data);
int IsEmpty_SeqList(SeqList *L);
int IsFull_SeqList(SeqList *L);
int Sort_SeqList(SeqList *L);

int main()
{
    SeqList *L;
    int i;
    DATATYPE s[]={1,45,3,2,5,1,9};

    L = Create_SeqList();

    printf("Insert_SeqList......\n");
    for (i = 0; i < sizeof(s)/sizeof(s[0]); i++)
    {
        Insert_SeqList(L,s[i]);
    }

    printf("Printf_SeqList.......\n");
    Printf_SeqList(L);

    printf("Delete_SeqList.......\n");
    Delete_SeqList(L,1);
    printf("Printf_SeqList.......\n");
    Printf_SeqList(L);

    printf("Modifi_SeqList.......\n");
    Modifi_SeqList(L,3,99);
    printf("Printf_SeqList.......\n");
    Printf_SeqList(L);

    printf("Sort_SeqList.......\n");
    Sort_SeqList(L);
    printf("Printf_SeqList.......\n");
    Printf_SeqList(L);



    return 0;
}

SeqList * Create_SeqList()
{
    SeqList * L;
    L = (SeqList *)malloc(sizeof(SeqList));
    if (L == NULL)
        printf("Full Memery");
    L->n = 0;
    return L;
}

int IsEmpty_SeqList(SeqList *L)
{
    if (L->n != 0)
        return 0;

    printf("Is Empty SeqList\n");
    return 1;
}

int IsFull_SeqList(SeqList *L)
{
    if (L->n <= MAX)
        return 0;
    printf("Is Full SeqList\n");
    return 1;
}

int Insert_SeqList(SeqList *L,int data)
{
    if (IsFull_SeqList(L))    
    {
        return -1;
    }

    L->data[L->n] = data;
    L->n++;
    return 0;
}
int Printf_SeqList(SeqList *L)
{
    if(IsEmpty_SeqList(L))
    {
        return -1;
    }
    int i;

    for (i = 0; i < L->n; i++)
    {
        printf("%d  ",L->data[i]);
    }
    printf("\n");
    return 0;
}

int Delete_SeqList(SeqList *L,int data)
{
    if (IsEmpty_SeqList(L))
    {
        return -1;
    }

    int i,j;

    for (i = 0; i < L->n; i++)
    {
        if (L->data[i] == data)
        {
            for (j = i+1; j < L->n; j++)
            {
                L->data[j-1] = L->data[j];
            }
            L->n--;
        } 
    }
    return 0;
}


int Modifi_SeqList(SeqList *L,int n,int data)
{
    if (!(n >= 0 && n <= L->n))
    {
        printf("Invalid n:%d...[0-%d]\n",n,L->n);
        return -1;
    }
    L->data[n-1] = data;
    return 0;
}

int Sort_SeqList(SeqList *L)
{
    if (IsEmpty_SeqList(L))
    {
        return -1;
    }
    int i,j;

    for (i = 0; i < L->n; i++)
    {
        for (j = i+1; j < (L->n); j++)
            if (L->data[i] > L->data[j])
            {
                L->data[i] ^= L->data[j];
                L->data[j] ^= L->data[i];
                L->data[i] ^= L->data[j];
            }
    }
    return 0;
}

int Delete_Repeat_SeqList(SeqList *L)
