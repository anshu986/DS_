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
node* UNION(node* start,node* start2)
{
    node *p1=start,*p2=start2,*p3,*dummy;
    dummy=getnode();
    p3=dummy;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->link=p1;
            p1=p1->link;
        }
        else if(p1->data>p2->data)
        {
            p3->link=p2;
            p2=p2->link;
        }
        else if(p1->data==p2->data)
        {
            p3->link=p1;
            p1=p1->link;
            p2=p2->link;
        }
        p3=p3->link;
    } 
    if(p1!=NULL)
    {
        p3->link=p1;
    }
    else if(p2!=NULL)
    {
        p3->link=p2;
    }
    return dummy->link;
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
    node *start,*start2;
    start=create();
    start2=create();
    start=UNION(start,start2);
    display(start);

}