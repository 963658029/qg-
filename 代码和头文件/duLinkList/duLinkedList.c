#include "./duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));
    if(List == NULL)
    {
        printf("内存分配失败\n");
        return ERROR;
    }
    List->next = NULL;
    List->prior = NULL;
    *L = List;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList temp;
    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if(p->next == NULL)
    {
        q->next = q;
        q->prior = p;
    }
    else{
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
        return SUCCESS;
    }
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    DuLinkedList posNode = p->next;
    DuLinkedList posNodeFront = p;

    if(p->next = NULL)
    {
        printf("链表为空");
        return ERROR;
    }
    else
    {

        while(posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("找不到数据");
                return ERROR;
            }
        }
    }
    if(posNode->next != NULL)
    {
        posNodeFront->next = posNode->next;
        posNode->next->prior = posNodeFront;
    }
    else
    {
        posNodeFront->next = NULL;
    }
    free(posNode);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList head)
{
    DuLNode *pl=head,*pf=head;
    if(head== NULL)
    {
        printf("link not found\n");
        return;
    }
    else
    {
        pf=head->prior;
        do
        {
            if(pl==pf)
            {
                printf("%d\n",pl->data);
                break;
            }
            printf("%d\n",pl->data);
            printf("%d\n",pf->data);
            pl=pl->next;
            pf=pf->prior;
        }
        while(pl->prior!=pf);
    }


}

