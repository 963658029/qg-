#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"
#include "duLinkedList.c"

void menu(){
    printf("1创建\n");
    printf("2销毁\n");
    printf("3头插法\n");
    printf("4尾插法\n");
    printf("5删除\n");
    printf("6遍历\n");
    printf("7退出\n");
    printf("请输入1--7:");
}

int main()
{
    int choice,num = 0;
    DuLinkedList head;
    head = NULL;
    do{
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                if(InitList_DuL(&head))
                {
                    printf("成功");
                }
                else
                {
                    printf("失败");
                }
                break;
            }
            case 2:
            {
                DestroyList_DuL(&head);
                printf("链表销毁成功");
                break;
            }
            case 3:
            {

                if(head == NULL)
                {

                    printf("没有链表");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据:");
                        scanf("%d",&newNode->data);
                        if(InsertBeforeList_DuL(head,newNode))
                        {
                            printf("数据插入成功\n");
                        }
                        else
                        {
                            printf("数据插入失败\n");
                        }
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
            }
            case 4:
            {
                if(head == NULL)
                {
                    printf("没有找到链表");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据:");
                        scanf("%d",&newNode->data);
                        if(InsertAfterList_DuL(head,newNode))
                        {
                            printf("成功\n");
                        }
                        else
                        {
                            printf("失败\n");
                        }
                    }
                    else
                    {
                        printf("失败\n");
                    }
                }
                break;

            }
            case 5:
            {
                if(head == NULL)
                {
                    printf("没有链表");
                }
                else
                {
                    printf("输入删除的数据:");
                    scanf("%d",&num);
                    if(DeleteList_DuL(head,&num))
                    {
                        printf("删除成功");
                    }
                    else
                    {
                        printf("删除失败");
                    }
                }
                break;
            }
            case 6:
            {
                if(head == NULL)
                {
                    printf("没有链表\n");

                }
                else if(head->next == NULL)
                {
                    printf("当前列表为空\n");
                }
                else
                {
                    TraverseList_DuL(head);
                }
                printf("\n");
                break;
            }

        }

    }while(choice == 7);
    return 0;
}
