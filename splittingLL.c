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
node* split(node* start)
{
    node *start1, *ptr;
    int ele;
    printf("\nENTER THE ELEMENT AT WHICH THE LIST IS TO BE SPLITTED");
    scanf("%d",&ele);
    ptr=start;
    while(ptr->data!=ele&&ptr!=NULL)
    {
        ptr=ptr->link;
    }
    start1=ptr->link;
    ptr->link=NULL;
    return start1;
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
    display(start);
    start2=split(start);
    printf("LL 1\n");
    display(start);
    printf("\nLL 2\n");
    display(start2);

}