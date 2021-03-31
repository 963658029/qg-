#include<stdlib.h>
#include<stdio.h>
#include "./linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L)
{
    int a=1;
    (*L)->data=a;
    (*L)->next=NULL;
    if((*L)->data==1&&(*L)->next==NULL)
    {
        return SUCCESS;
    }
    else return ERROR;

}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L)
{
    LNode *p1,*p2;
    p1=p2=(LinkedList)malloc(sizeof(LNode));
    p1=*L;
    p2=*L;
    while(p1->next!=NULL)
    {
        p1=p1->next;
        free(p2);
        p2=p1;
    }
    free(p1);
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)
{
    q->next=p->next;
    p->next=q;
    if(p->next->data==q->data) return SUCCESS;
    else return ERROR;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e)
{
    LinkedList p1;
    p1=(LinkedList)malloc(sizeof(LNode));
    p1=p;
    if(p->next==NULL)
    {
        *e=p1->data;
        free(p);
        p=NULL;
        if (p==NULL)
        {
            printf("DeleteList data is%d\n",*e);
            return SUCCESS;
        }
        else return ERROR;
    }
    else
    {
        p1=p->next;
        *e=p1->data;
        p->next=p1->next;
        free(p1);
    }

    if(p->next==NULL||p->next->data!=(*e))
    {
        printf("DeleteList data is%d\n",*e);
        return SUCCESS;
    }
    else return ERROR;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void print(ElemType e)
{
    printf("%d\n",e);
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    visit(L->data);
    while(L->next!=NULL)
    {
        L=L->next;
        visit(L->data);
    }
    if(L->next==NULL) printf("travel success£¡\n");
    else printf("travel error£¡\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{
    ElemType i=1;
    if(e==1)
    {
        if(L->data>0&&L->data<1000) return SUCCESS;
        else return ERROR;
    }
    if(e==0)
    {
        return SUCCESS;
    }
    for(; i<e&&L!=NULL&&L->next!=NULL; i++)
    {
        L=L->next;
    }
    if(i==e)
    {
        return SUCCESS;
    }
    else return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L)
{
    LinkedList p1,p2;
    ElemType m,n;
    if((*L)->next!=NULL)
    {
        m=(*L)->data;
        n=(*L)->next->data;
        p1=p2=(LinkedList)malloc(sizeof(LNode));
        p1=*L;
        p2=(*L)->next;
        *L=(*L)->next;
        p1->next=NULL;
        for(; p2->next!=NULL;)
        {
            *L=(*L)->next;
            p2->next=p1;
            p1=p2;
            p2=*L;
        }
        (*L)->next=p1;
        for(; p1->next!=NULL;)
        {
            p1=p1->next;
            p2=p2->next;
        }
        if((p1->data)==m&&(p2->data)==n) return SUCCESS;
        else return ERROR;
    }
    else printf("only one List£¡\n");
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
    LinkedList p1,p2;
    ElemType a=0,k=999;
    if(L->next==NULL) return ERROR;
    else
    {
        p1=p2=(LinkedList)malloc(sizeof(LNode));
        p1=L;
        p2=L->next;
        while(1)
        {
            p1=p1->next;
            if(p2!=NULL&&p2->next!=NULL)
            {
                if(p2->next->next==NULL)  return ERROR;
                else p2=p2->next->next;
            }
            else return ERROR;
            if(p2->data==k&&p1->data==k) return SUCCESS;
            if(p2->data==p1->data) k=p1->data;
            if(a++>200) return ERROR;
        }
    }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L)
{
    LNode *p1,*p2;
    if((*L)->next!=NULL)
    {
        p1=p2=(LNode*)malloc(sizeof(LNode));
        p1=(*L);
        p2=(*L)->next;
        *L=p2;
        p1->next=p2->next;
        p2->next=p1;
        while(p1->next!=NULL)
        {
            p2=p1->next->next;
            if(p2==NULL) break;
            p1->next->next=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p1=p2->next;
        }
    }
    else printf("only one list£¡\n");

    if((*L)->data!=1) printf(" ReverseEven success£¡\n");
    else printf(" ReverseEven  error£¡\n");
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L)
{
    LinkedList p1,p2;
    p1=p2=(LinkedList)malloc(sizeof(LNode));
    p1=p2=*L;
    while(p2!=NULL&&p2->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next->next;
    }
    return p1;
}
