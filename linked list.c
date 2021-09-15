//#include<iostream>
#include<malloc.h>
#include<conio.h>
#include<stdio.h>     //implementing link list using C
//using namespace std;

struct node{
        int info;
        struct node*next;
};

typedef struct node NODE;
NODE *start=NULL,*ptr,*temp,*temp1;

void insertbeg(int x);
void insertend(int x);
void insertaft(int x,int y);
void insertbef(int x,int y);
void deletebeg();
void deleteend();
void deletespec(int y);
void traverse();

int main()
{
int ch1,ch2,x,y;
//clrscr();
do
{
        printf("\n\tLinked List Operations");
        printf("\n\t1.Insert Beg");
        printf("\n\t2.Insert End");
        printf("\n\t3.Insert Spec After");
        printf("\n\t4.Insert Spec Before");
        printf("\n\t5.Delete Beg");
        printf("\n\t6.Delete End");
        printf("\n\t7.Delete Spec");
        printf("\n\t8.Traverse");
        printf("\n\tEnter Your Choice: ");
        scanf("%d",&ch1);
        switch(ch1)
        {
                case 1:printf("\n\t enter element : ");
                scanf("%d",&x);
                insertbeg(x);
                break ;

                case 2: printf("\n\t enter element : ");
                scanf("%d",&x);
                insertend(x);
                break ;

                case 3: printf("\n\t enter element to be insert: ");
                scanf("%d",&x);
                printf("\n\t enter after which element : ");
                scanf("%d",&y);
                insertaft(x,y);
                break ;

                case 4: printf("\n\t enter element to be insert: ");
                scanf("%d",&x);
                printf("\n\t enter before which element : ");
                scanf("%d",&y);
                insertbef(x,y);
                break ;

                case 5:deletebeg();
                break;

                case 6:deleteend();
                break;

                case 7:printf("\n\t enter element : ");
                scanf("%d",&y);
                deletespec(y);
                break ;

                case 8: traverse();
                break ;
                default: printf("\n\t Invalid Choice");
                }
        printf("\n\t press 9 to continue....");
        scanf("%d",&ch2);
//clrscr();
}while(ch2==9);

return 0;

}

void insertbeg(int x)
{
        ptr=(NODE*)malloc(sizeof(NODE));
        ptr->info=x;
        if(start==NULL)
        {
                ptr->next=NULL;
        }
        else {
                ptr->next=start;
        }
        start=ptr;
}

void insertend(int x)
{
        ptr=(NODE*)malloc(sizeof(NODE));
        ptr->info=x;
        temp=start;
        if(start==NULL)
        {
                ptr->next=NULL;
                start=ptr;
        }
        else{
        while(temp->next!=NULL){
                temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
        }
}

void insertbef(int x,int y)
{
        ptr=(NODE*)malloc(sizeof(NODE));
        ptr->info=x;
        if(start->next==NULL)
        {
                if(start->info==y){
                        ptr->next=start;
                        start=ptr;
                }
                else{
                        printf("\nelement not found");
                }
        }
        else if(start->info==y){
                        ptr->next=start;
                        start=ptr;
                }
        else{
                temp=start;
                while(temp->info!=y){
                        temp1=temp;
                        temp=temp->next;
                }
                if(temp==NULL) {printf("\nelement not found");}
                ptr->next=temp;
                temp1->next=ptr;
                }
       /* else {
                ptr->next=start;
        }*/
}
void insertaft(int x,int y){
        ptr=(NODE*)malloc(sizeof(NODE));
        ptr->info=x;

        temp=start;
        while(temp->info!=y){
                temp=temp->next;
        }
        if(temp==NULL) {printf("\nelement not found");}
        else {ptr->next=temp->next;
        temp->next=ptr;}


}
void deletebeg()
{
        int x;
        ptr=(NODE*)malloc(sizeof(NODE));
        if(start==NULL) {printf("\nlist is empty");}
        else{
                ptr=start;
                x=ptr->info;
                if(start->next==NULL){
                        start=NULL;
                }
                start=ptr->next;
                printf("\ndeleted element is :%d",x);
                free(ptr);
        }
}
void deleteend(){
        int x;
        ptr=(NODE*)malloc(sizeof(NODE));
        if(start==NULL) {printf("\nlist is empty");}
        else{
                temp=start;
                while(temp->next!=NULL){
                        temp1=temp;    //two pointer method
                        temp=temp->next;
        }
        ptr=temp;
        x=ptr->info;
        temp1->next=NULL;
        printf("\ndeleted element is :%d",x);
        free(ptr);

        }
}
void deletespec(int y)
{
        int x;
        ptr=(NODE*)malloc(sizeof(NODE));
        if(start==NULL) {printf("\nlist is empty");}
        else {
                ptr=start;

        }
}
void traverse()
{
        if(start==NULL) printf("\nlist is empty");
        else{
               temp=start;
               while(temp!=NULL)
               {
                       printf("[\ninfo=%d add=%u :next add=%u]",temp->info,temp,temp->next);
                       temp=temp->next;
               }
        }
}

void reversell()
{
        int i=1;
        while(i==1){
                temp=start;
                while(temp->next!=NULL){
                        temp->next=temp1;
                        temp1->next=NULL;
                        i=1;}
        }
}
