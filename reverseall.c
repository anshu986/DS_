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
node* reverse(node* llist) {
    node *temp,*current,*temp2,*start;
    
    temp=NULL;
    current=llist;
    temp2=current->link;
    while(temp2!=NULL)
    {
        current->link=temp;
        temp=current;
        current=temp2;
        temp2=temp2->link;
    }
    current->link=temp;
    return current;
}
int compare(node* start,node*start1)
{
    node *ptr1,*ptr2;
    ptr1=start;
    ptr2=start1;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->data!=ptr2->data)
        {
            return 0;
        }
        ptr1=ptr1->link;
        ptr2=ptr2->link;
        
    }
    return 1;


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
    node *start,*start1;
    int n;
    start=create();
    printf("\nFIRST LL");
    display(start);
    start1=reverse(start);
    printf("\nREVERSE LL");
    display(start1);
    n=compare(start,start1);
    if(n==0)
    printf("\nNOT PALLINDROME");
    else{
        printf("\nPALLINDROME");
    }

}