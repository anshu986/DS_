#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int coefficient;
    int power;
    struct NODE *link;
}node;
node* getnode()
{
    node* n1;
    n1=(node*)malloc(sizeof(node));
    n1->link=NULL;
    return n1;
}
node* create(){
    node *new,*new1,*temp,*start,*ptr1,*ptr2;
    int ele,coef;
    char ans='y';
    printf("\n enter the coefficient\n");
    scanf("%d",&coef);
     printf("\n enter the power\n");
    scanf("%d",&ele);
    new=getnode();
    start=new;
    temp=start;
    new->coefficient=coef;
    new->power=ele;
    new->link=NULL;
    printf("\n do you want to enter more element:y for yes or n for no \n");
    ans=getche();
    while(ans=='y')
    {
        printf("\n enter the coefficient\n");
        scanf("%d",&coef);
        printf("\n enter the power\n");
        scanf("%d",&ele);
        new1=getnode();
        new1->coefficient=coef;
        new1->power=ele;
        if(ele<=temp->power)
        {
            temp->link=new1;
            temp=new1;
            new1->link=NULL;
        }
        else{
           ptr1=start;
            while(ptr1->power>=ele)
            {
                ptr2=ptr1;
                ptr1=ptr1->link;
            }
            if(ptr1==start)
            {
              new1->link=start;
              start=new1;
            }
            else{
                ptr2->link=new1;
                new1->link=ptr1;
            }
            while(ptr1->link!=NULL)
            {
                ptr1=ptr1->link;
            }
            temp=ptr1;

        }
        
        printf("\n do you want to enter more element:y for yes or n for no \n");
        ans=getche();

    }
    getch();
    return start;
}
node* insert(node*head,int coef,int po)
{
    node *ptr=head,*new;
    if(head==NULL)
    {
        head=getnode();
        head->coefficient=coef;
        head->power=po;
        head->link=NULL;
    }
    else{
        while(ptr->link!=NULL)
        {
           ptr= ptr->link;
        }
        new=getnode();
        new->coefficient=coef;
        new->power=po;
        new->link=NULL;
        ptr->link=new;
    }
    return head;
}
node* sub(node* start,node* start1)
{
    node *ptr1,*ptr2,*res,*res1,*head=NULL;
    int c=0;
    ptr1=start;
    ptr2=start1;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->power==ptr2->power)
        {
           head=insert(head,ptr1->coefficient-ptr2->coefficient,ptr1->power);
           ptr1=ptr1->link;
           ptr2=ptr2->link;
        }
        else if(ptr1->power>ptr2->power)
        {
         head=insert(head,ptr1->coefficient,ptr1->power);
         ptr1=ptr1->link;
        }
         else if(ptr1->power<ptr2->power)
        {
            ptr2->coefficient*=-1;
         head=insert(head,ptr2->coefficient,ptr2->power);
         ptr2=ptr2->link;
        }

    }
    if(ptr1!=NULL)
    {
        while(ptr1!=NULL)
        {
         head=insert(head,ptr1->coefficient,ptr1->power);
         ptr1=ptr1->link;
        }
       
    }
    else if(ptr2!=NULL)
    {
        while(ptr2!=NULL)
        {
            ptr2->coefficient*=-1;
        head=insert(head,ptr2->coefficient,ptr2->power);
         ptr2=ptr2->link;

        }
        
    }
    return head;


}
void display(node* start){
    node *ptr;
    ptr=start;
    if(ptr==NULL)
    {
        printf("LINKED LIST IS EMPTY");
    }
    else{
        while(ptr!=NULL)
    {
        printf("%d",ptr->coefficient);
        printf("x^");
        printf("%d",ptr->power);
        printf("->");
        ptr=ptr->link;
    }
    printf("NULL");
    }
}
main()
{
    node *start,*start1,*res;
    start=create();
    display(start);
    start1=create();
    display(start1);
    res=sub(start,start1);
    printf("\n");
    display(res);
}