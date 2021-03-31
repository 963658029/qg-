#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "linkedList.c"

int main()
{
    int i = 0;
    LinkedList head;
    printf("******************************");
    printf("1.创建链表");
    printf("2.销毁链表");
    printf("3.插入一个结点");
    printf("4.删除某结点");
    printf("5.遍历并输出链表");
    printf("6.反转链表");
    printf("7.判断链表是否成环");
    printf("7.判断链表是否成环");
    printf("8.调换奇偶顺序");
    printf("9.找中间结点");
    printf("10.退出");
    printf("******************************");
    printf("输入你想实现的功能的序号:");



    while(1)
    {
        scanf("%d",&i);
        switch(i)
        {
        case 1:
        {
            if(InitList(&head))
                printf("成功");
            else
                printf("失败");
            break;
        }
        case 2:
        {
            DestroyList(&head);
            break;
        }
        case 3:
        {
            LinkedList p = NULL;
            LinkedList q = NULL;
            p->data == 1;
            q->data == 2;
            InsertList(p, q);
            break;
        }
        case 4:
        {
            int b = 0;
            DeleteList(head->next, &b);
            break;
        }
        case 5:
        {
            TraverseList(head,0);
            break;
        }
        case 6:
        {
            int c = 0;
            SearchList(head,c);
            break;
        }
        case 7:
        {
            ReverseList(&head);
            break;
        }
        case 8:
        {
            IsLoopList(head);
            break;
        }
        case 9:
        {
            ReverseEvenList(&head);
            break;
        }
        case 10:
        {
            FindMidNode(&head);
            break;
        }
        }

    }
    return 0;

}
