#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int data;
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
    node *new,*new1,*temp,*start;
    int ele;
    char ans='y';
    printf("\n enter the element\n");
    scanf("%d",&ele);
    new=getnode();
    start=new;
    temp=start;
    new->data=ele;
    new->link=NULL;
    printf("\n do you want to enter more element:y for yes or n for no \n");
    ans=getche();
    while(ans=='y')
    {
        //new1=getnode();
        //if(new1==NULL)
       // {
           // printf("OVERFLOW");
            //exit(1);
        //}
       // else{
        printf("\n enter the element\n");
        scanf("%d",&ele);
        new1=getnode();
        new1->data=ele;
        temp->link=new1;
        temp=new1;
        new1->link=NULL;
        printf("\n do you want to enter more element:y for yes or n for no \n");
        ans=getche();
        //}
    }
    getch();
    return start;
}
node* intersect(node*start,node*start1)
{
    node* ptr;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=start1;
    return start;
}
node* mergingpoint(node* start1,node* start2)
{
    int l1=0,l2=0,d,i;
    node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    while(ptr1!=NULL)
    {
        ptr1=ptr1->link;
        l1++;
    }
    while(ptr2!=NULL)
    {
        ptr2=ptr2->link;
        l2++;
    }
    if(l1>l2)
    {
        d=l1-l2;
        ptr1=start1;
        ptr2=start2;
        for(i=0;i<d;i++)
        {
            ptr1=ptr1->link;
        }

    }
    else if(l2>l1)
    {
         d=l2-l1;
        ptr1=start2;
        ptr2=start1;
        for(i=0;i<d;i++)
        {
            ptr1=ptr1->link;
        }
    }
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1;
        }
        else{
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
    }
    return -1;
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
        printf("%d",ptr->data);
        printf("->");
        ptr=ptr->link;
    }
    printf("NULL");
    }
}
main()
{
    node *start1,*start2,*start3;
    start1=create();
    start2=create();
    start3=create();
    start1=intersect(start1,start3);
    start2=intersect(start2,start3);
    start1=mergingpoint(start1,start2);
    display(start1);



}