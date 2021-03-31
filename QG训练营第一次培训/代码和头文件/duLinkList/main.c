#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"
#include "duLinkedList.c"

void menu(){
    printf("******************************");
    printf("1.创建双向链表\n");
    printf("2.销毁链表\n");
    printf("3.在某结点前插入结点\n");
    printf("4.在某结点后插入结点\n");
    printf("5删除结点\n");
    printf("6遍历链表\n");
    printf("7退出\n");
    printf("******************************");
    printf("请输入你想实现的功能的序号");
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
