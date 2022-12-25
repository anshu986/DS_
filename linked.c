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
node* insertf(node* start){
    node *n2;
    int ele;
    n2=getnode();
    printf("\n enter the element\n");
    scanf("%d",&ele);
    n2->link=start;
    start=n2;
    n2->data=ele;
    return start;
}
node* insertl(node* start){
    node *ptr,*n3;
    int ele;
    printf("\n enter the element\n");
    scanf("%d",&ele);
    n3=getnode();
    ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=n3;
    n3->link=NULL;
    n3->data=ele;

    return start;

}
node* insertm(node* start){
    node *new,*ptr,*ptr1;
    int ele,key;
    new=getnode();
    printf("\n enter the key after which the node is to be inserted\n");
    scanf("%d",&key);
    printf("\n enter the element\n");
    scanf("%d",&ele);
    ptr=start;
    while(ptr->data!=key&&ptr!=NULL)
    {
        ptr=ptr->link;
    }
    if(ptr==NULL)
    {
        printf("KEY NOT PRESENT");
        exit(0);
    }
    else{
        new->data=ele;
        ptr1=ptr->link;
        new->link=ptr1;
        ptr->link=new;
    }

return start;
}
node* deletef(node* start)
{
    node *ptr;
    ptr=start;
    start=ptr->link;
    ptr->link=NULL;
    free(ptr);
return start;
}
node* deletel(node* start){
    node *ptr,*temp;
    ptr=start;
    while(ptr->link!=NULL)
    {
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=NULL;
return start;
}
node* deletem(node* start){
    node *ptr,*temp;
    int key;
    printf("\n enter the key after which the node is to be deleted\n");
    scanf("%d",&key);
    ptr=start;
    while(ptr->data!=key&&ptr!=NULL)
    {
        ptr=ptr->link;
    }
    temp=ptr->link;
    ptr->link=temp->link;
    temp->link=NULL;
    free(temp);
return start;

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
    int ch;
    char ans='y';
    node *start;
    while(ans=='y')
    {
     printf("Enter \n 1 to create \n 2 to insert at front\n 3 to insert at last\n 4 to insert at middle\n 5 to delete at front\n 6 to delete at last\n 7 to delete at middle");
    scanf("%d",&ch);
     switch(ch){
        case 1:
        start=create();
        display(start);
        break;
        case 2:
        start=insertf(start);
        display(start);
        break;
        case 3:
        start=insertl(start);
        display(start);
        break;
        case 4:
        start=insertm(start);
        display(start);
        break;
        case 5:
        start=deletef(start);
        display(start);
        break;
        case 6:
        start=deletel(start);
        display(start);
        break;
        case 7:
        start=deletem(start);
        display(start);
        break;

    }
    printf("\nDo you want to continue?\n");
    ans=getche();
    }
   

}