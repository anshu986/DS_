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
node* mul(node* start,node* start1)
{
    node *ptr1,*ptr2,*res,*res1,*head=NULL;
    ptr1=start;
    ptr2=start1;
    while(ptr1!=NULL)
    { ptr2=start1;
        while(ptr2!=NULL)
        {
            head=insert(head,ptr1->coefficient*ptr2->coefficient,ptr1->power+ptr2->power);
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    return head;
}
node* sorting(node* start)
{
    node *p1,*p2,*ele,*i,*j;
    int temp;
    for(i=start;i->link!=NULL;i=i->link)
    {
        for(j=i->link;j!=NULL;j=j->link)
        {
            if(i->power<j->power)
            {
                temp=i->power;
                i->power=j->power;
                j->power=temp;
                temp=i->coefficient;
                i->coefficient=j->coefficient;
                j->coefficient=temp;
            }
        }
    }
    return start;
}
node* add_res(node*head)
{
    int sum,power;
    node *ptr,*ptr2,*temp;
    ptr=head->link;
    temp=head;
    while(ptr!=NULL)
    {
        if(temp->power==ptr->power)
        {
            temp->coefficient+=ptr->coefficient;
            temp->link=ptr->link;
            ptr=ptr->link;
        }
        else{
            temp=ptr;
            ptr=ptr->link;
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
    res=mul(start,start1);
    printf("\n");
    display(res);
    start=sorting(res);
    printf("\n");
    display(start);
    printf("\n final answer");
    start=add_res(start);
    display(start);
    
}