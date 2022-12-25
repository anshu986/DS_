#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int data;
    struct NODE *link
}node;
node* getnode()
{
    node *new;
    new=(node*)malloc(sizeof(node));
    new->link=new;
    return new;
}
node* create(){
    node *start,*new,*temp;
    int ele;
    char ans;
    start=getnode();
    printf("\nEnter the element\n");
    scanf("%d",&ele);
    start->data=ele;
    temp=start;
    start->link=start;
    printf("do you want to enter more element:y for yes or n for no");
    ans=getch();
    while(ans=='y')
    {
        new=getnode();
        printf("\nEnter the element\n");
        scanf("%d",&ele);
        new->data=ele;
        temp->link=new;
        new->link=start;
        temp=new;
        printf("do you want to enter more element:y for yes or n for no\n");
        ans=getch();
    }
return temp;
}
node* insertf(node* start){
    node *n2,*ptr;
    int ele;
    n2=getnode();
    printf("\n enter the element\n");
    scanf("%d",&ele);
    ptr=start->link;
    n2->link=ptr;
    n2->data=ele;
    start->link=n2;
  
    return start;
}
node* insertl(node* start){
    node *ptr,*n3;
    int ele;
    printf("\n enter the element\n");
    scanf("%d",&ele);
    n3=getnode();
    ptr=start->link;
    start->link=n3;
    n3->link=ptr;
    n3->data=ele;
    start=n3;

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
    ptr=start->link;
    while(ptr->data!=key&&ptr!=start)
    {
        ptr=ptr->link;
    }
    if(ptr==start)
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
    node *ptr,*ptr1;
    ptr=start->link;
    ptr1=ptr->link;
    start->link=ptr1;
    ptr->link=NULL;
    free(ptr);
return start;
}
node* deletel(node* start){
    node *ptr,*temp;
    ptr=start->link;
    while(ptr!=start)
    {
        temp=ptr;
        ptr=ptr->link;
    }
   
    temp->link=start->link;
    start=temp;
    ptr->link=NULL;
    free(ptr);
return start;
}
node* deletem(node* start){
    node *ptr,*temp;
    int key;
    printf("\n enter the key after which the node is to be deleted\n");
    scanf("%d",&key);
    ptr=start->link;
    while(ptr->data!=key&&ptr!=start)
    {
        ptr=ptr->link;
    }
    if(ptr==start)
    {
        printf("KEY NOT PRESENT");
    }
    else{
        temp=ptr->link;
        ptr->link=temp->link;
        temp->link=NULL;
    }
   
    free(temp);
return start;

}
display(node* start){
    node *ptr;
    ptr=start->link;
    while((ptr!=start)){
        printf("%d",ptr->data);
        printf("->");
        ptr=ptr->link;
    }
    printf("%d",ptr->data);
}
int main()
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