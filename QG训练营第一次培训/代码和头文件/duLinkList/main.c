#include<stdio.h>
#include<stdlib.h>
#include "./duLinkedList.h"
#include "./duLinkedList.c"

void menu();
void kaitou();

void main()
{
    kaitou();
    system("pause");
    ElemType number,flag;
    DuLinkedList head;
    head=(DuLinkedList)malloc(sizeof(DuLNode));
    menu();
    while(1)
    {
        scanf("%d",&number);
        while(number<1||number>11)
        {
            printf("没有这个功能，是不是搞事情？请重新输入：");
            fflush(stdin);
            scanf("%d",&number);
        }

        if(number==1)
        {
            int a;
            if(head->data>0&&head->data<1000) printf("执行一次exe只能创建一次链表，或者先执行销毁！\n");
            else
            {
                a=InitList_DuL(&head);
                if(a==1)
                {
                    flag=1;
                    printf("创建成功！\n");
                }
                else printf("创建失败！\n");
            }
        }

        if(number==2)
        {
            if(head->data>1000||head->data<1) printf("该指针不是一个指向链表的指针！\n");
            else
            {
                DestroyList_DuL(&head);
                if(head->data>1000||head->data<1)
                {
                    printf("销毁成功！\n");
                    flag=0;
                }
                else printf("销毁失败！\n");
            }
        }

        if(number==3)
        {
            DuLNode *i,*storage;
            ElemType a,c,d;
            i=storage=(DuLinkedList)malloc(sizeof(DuLNode));
            printf("请输入数据：");
            scanf("%d",&(i->data));
            while(i->data<1||i->data>1000)
            {
                printf("输入数据要大于1小于1000，请重新输入数据：");
                fflush(stdin);
                scanf("%d",&(i->data)) ;
            }
            printf("请输入插入在第几个结点前：");
            scanf("%d",&c);
            while(c<1||c>1000)
            {
                printf("输入数据要大于1小于1000，请重新输入数据：");
                fflush(stdin);
                scanf("%d",&c) ;
            }
            if(c>flag) printf("插入失败！没有这么多的结点！\n");
            else
            {
                storage=head;
                for(d=1; d<c; d++) storage=storage->next;
                a=InsertBeforeList_DuL(storage,i);
                if(a==1)
                {
                    if(flag++==1) head=i;
                    printf("插入成功！\n");
                }
                else printf("插入失败！\n");
            }
        }

        if(number==4)
        {
            DuLNode *i,*storage;
            ElemType a,c,d;
            i=storage=(DuLinkedList)malloc(sizeof(DuLNode));
            printf("请输入数据：");
            scanf("%d",&(i->data));
            while(i->data<1||i->data>1000)
            {
                printf("输入数据要大于1小于1000，请重新输入数据：");
                fflush(stdin);
                scanf("%d",&(i->data)) ;
            }
            printf("请输入插入第几个结点后：");
            scanf("%d",&c);
            while(c<1||c>1000)
            {
                printf("输入数据要大于1小于1000，请重新输入数据：");
                fflush(stdin);
                scanf("%d",&c) ;
            }
            if(c>flag) printf("插入失败！没有这么多的结点！\n");
            else
            {
                storage=head;
                for(d=1; d<c; d++) storage=storage->next;
                a=InsertAfterList_DuL(storage,i);
                if(a==1)
                {
                    flag++;
                    printf("插入成功！\n");
                }
                else printf("插入失败！\n");
            }
        }

        if(number==5)
        {
            ElemType a,b,c,e;
            DuLNode *d;
            d=(DuLinkedList)malloc(sizeof(DuLNode));
            d=head;
            printf("请输入要删除结点的位置：");
            scanf("%d",&b);
            while(b<1||b>1000)
            {
                printf("输入数据要大于1小于1000，请重新输入数据：");
                fflush(stdin);
                scanf("%d",&b) ;
            }
            if(b>flag) printf("删除失败！没有那么多的结点！\n");
            else
            {
                if(b==1) head=head->next;
                for(c=1; c<b; c++) d=d->next;
                a=DeleteList_DuL(d,&e);
                if(a==1) printf("删除成功！\n");
                else printf("删除失败！\n");
            }
        }

        if(number==6)
        {
            if(head->data>0&&head->data<1000)
            {
                TraverseList_DuL(head,&print);
            }
            else printf("该指针不是一个指向链表的指针！\n");
        }

        if(number==7) break;

        system("pause");
        menu();
    }
}


void kaitou()
{
    {
        int  i, j, k, l, m;
        char c=3;

        for (i=1; i<=5; i++)
            printf("\n");

        for (i=1; i<=3; i++)
        {
            for (j=1; j<=32-2*i; j++)  printf(" ");
            for (k=1; k<=4*i+1; k++)  printf("%c", c);
            for (l=1; l<=13-4*i; l++)  printf(" ");
            for (m=1; m<=4*i+1; m++)  printf("%c", c);
            printf("\n");
        }

        for (i=1; i<=3; i++)
        {
            for (j=1; j<=24+1; j++)   printf(" ");
            for (k=1; k<=29; k++)   printf("%c", c);
            printf("\n");
        }

        for (i=7; i>=1; i--)
        {
            for (j=1; j<=40-2*i; j++)  printf(" ");
            for (k=1; k<=4*i-1; k++)  printf("%c", c);
            printf("\n");
        }

        for (i=1; i<=39; i++)    printf(" ");

        printf("%c\n", c);

        for (i=1; i<=2; i++)    printf("\n");

        printf("                             欢迎查看Qg作业!\n\n\n");
    }
}


void menu()
{
        system("cls");
        puts("\n\n\t\t\t*****************QG第一周作业******************\n\n");
        puts("\t\t\t\t\t1. 创建双向链表 \n");
        puts("\t\t\t\t\t2. 销毁链表 \n");
        puts("\t\t\t\t\t3. 头插法\n ");
        puts("\t\t\t\t\t4. 尾插法\n ");
        puts("\t\t\t\t\t5. 删除结点\n ");
        puts("\t\t\t\t\t6. 遍历链表\n ");
        puts("\t\t\t\t\t7. 退出\n ");
        puts("\n\n\t\t            ******************************************\n");
        printf("Chiose your number(1-7):[ ]\b\b");
}
