#include "./linkedList.h"
#include <stdio.h>
#include <stdlib.h>


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    LinkedList list;
    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
        printf("false\n");
        return ERROR;
    }
    list->next == NULL;
    *L = list;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList q,p;
    q = *L;
    p = q -> next;
    while(q)
    {
        free(q);
        q = p;
        p = p -> next;
    }

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    q = p -> next;
    p -> next = q;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList q;
    p -> next = q;
    p -> data = *e;
    p -> next = q -> next;
    free(q);
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList p;
    p = L;
    while(p != NULL)
    {
        printf("%d",p->data);
        p = p -> next;
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    LinkedList p;
    p = L;
    int count = 0;
    while(p->data != e)
    {
        p = p -> next;
        count++;
        if(p->data == e)
            return SUCCESS;
    }
    return ERROR;

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LinkedList next;
    LinkedList prev = NULL;

    while((*L) != NULL)
    {
        next = (*L)->next;
        (*L)->next = prev;
        prev = (*L);
        (*L) = next;
    }
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    if(L == NULL)
    {
        return 0;
    }

    LinkedList slow = L->next;

    if(slow == NULL)
    {
        return ERROR;

    }

    LinkedList fast = slow->next;

    while(slow != NULL && fast != NULL)
    {
        if(slow == fast)
        {
            return SUCCESS;
        }

        slow = slow->next;

        fast = fast->next;

        if(fast!=NULL)
        {
            fast = fast->next;
        }
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
   LinkedList newHead = NULL;
   LinkedList node;
   while((*L) != NULL)
   {
       node = (*L);
       (*L) = (*L)->next;

       node->next = newHead;
       newHead = node;
   }
   return newHead;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LinkedList fast = NULL;
    LinkedList low = NULL;
    fast = (*L);
    low = (*L);

    while(fast&&fast->next)
    {
        fast = fast->next->next;
        low = low->next;
    }

    return low;
}

