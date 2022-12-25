#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int data;
    struct NODE *Llink;
    struct NODE *Rlink;
}node;
node* getnode()
{
    node* n1;
    n1=(node*)malloc(sizeof(node));
    n1->Rlink=NULL;
    n1->Llink=NULL;
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
    new->Rlink=NULL;
    printf("\n do you want to enter more element:y for yes or n for no \n");
    ans=getche();
    while(ans=='y')
    {
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
        temp->Rlink=new1;
        new1->Llink=temp;
        temp=new1;
        new1->Rlink=NULL;
        temp->Llink=
        printf("\n do you want to enter more element:y for yes or n for no \n");
        ans=getche();
        //}
    }
    getch();
    return start;
}
node* insertf(node* start){
    node *n2,*ptr;
    int ele;
    n2=getnode();
    printf("\n enter the element\n");
    scanf("%d",&ele);
    ptr=start;
    ptr->Llink=n2;
    n2->Rlink=start;
    start=n2;
    n2->data=ele;
    n2->Llink=NULL;
    return start;
}
node* insertl(node* start){
    node *ptr,*n3;
    int ele;
    printf("\n enter the element\n");
    scanf("%d",&ele);
    n3=getnode();
    ptr=start;
    while(ptr->Rlink!=NULL)
    {
        ptr=ptr->Rlink;
    }
    ptr->Rlink=n3;
    n3->Rlink=NULL;
    n3->Llink=ptr;
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
        ptr=ptr->Rlink;
    }
    if(ptr==NULL)
    {
        printf("KEY NOT PRESENT");
        exit(0);
    }
    else{
        new->data=ele;
        ptr1=ptr->Rlink;
        ptr->Rlink=new;
        new->Llink=ptr;
        new->Rlink=ptr1;
        ptr1->Llink=new;
    }
return start;
}
node* deletef(node* start)
{
    node *ptr,*ptr1;
    ptr=start;
    start=ptr->Rlink;
    ptr1=start;
    ptr1->Llink=NULL;
    ptr->Rlink=NULL;
    free(ptr);
return start;
}
node* deletel(node* start){
    node *ptr,*temp;
    ptr=start;
    while(ptr->Rlink!=NULL)
    {
        ptr=ptr->Rlink;
    }
    temp=ptr->Llink;
    temp->Rlink=NULL;
    ptr->Llink=NULL;
return start;
}
node* deletem(node* start){
    node *ptr,*ptr1=NULL,*ptr2=NULL;
    int key;
    printf("\n enter the key whose node is to be deleted\n");
    scanf("%d",&key);
    ptr=start;
    while(ptr->data!=key&&ptr!=NULL)
    {
        ptr=ptr->Rlink;
    }
    printf("%d",ptr->data);
        printf("%d %d",ptr1->data,ptr2->data);
    ptr1=ptr->Llink;
    ptr2=ptr->Rlink;
    ptr1->Rlink=ptr2;
    ptr2->Llink=ptr1;
    ptr->Rlink=NULL;
    ptr->Llink=NULL;
    printf("%d %d",ptr1->data,ptr2->data);
    //free(ptr);
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
        ptr=ptr->Rlink;
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