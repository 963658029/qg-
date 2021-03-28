#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "linkedList.c"

int main()
{
    int i = 0;
    LinkedList head;
    scanf("%d",&i);

    /*1 创建新链表   2 插入  3 删除  4 遍历  5 搜索  6 搜索某个数  7 反转 8 判断是否有环 9反转 10 找到中间 */
    switch(i)
    {
        case 1:
        {
            if(InitList(&head))
                printf("成功");
            else
                printf("失败");
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
        }
        case 7:
        {
            ReverseList(&head);
        }
        case 8:
        {
            IsLoopList(head);
        }
        case 9:
        {
            ReverseEvenList(&head);
        }
        case 10:
        {
            FindMidNode(&head);
        }
    }

    return 0;

}
