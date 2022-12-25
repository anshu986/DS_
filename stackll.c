#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
int data;
struct Stack *link;
}node;
node *top=NULL;
push(int n)
{
    node *new=(node*)malloc(sizeof(new));
    if(new==NULL)
    {
        printf("OVERFLOW\n");
    }
    else{
        new->data=n;
        new->link=top;
        top=new;
    }
}
 int pop()
{
    int temp;
    if(top==NULL)
    {
        printf("STACK IS EMPTY\n");
    }
    else{
        temp=top->data;
        top=top->link;
    }
    return temp;
}
display()
{
    node *temp;
    temp=top;
    if(top==NULL)
    {
     printf("STACK IS EMPTY");   
    }
    else{
        while(top!=NULL)
        {
            printf("%d",top->data);
            printf("->");
            top=top->link;
        }
    }
    printf("NULL");
    top=temp;
}
int main()
{
    int x,choice=1,ans,n;
    printf("enter the choice\n 1.push\n2.pop\n 3.display");
     scanf("%d",&ans);
    
while(choice==1)
{ 
    
   switch(ans)
   {
    case 1:
        printf("ENTER THE ELEMENT TO BE INSERTED");
        scanf("%d",&n);
        push(n);
        break;
    case 2:
        x=pop();
        printf("POPPPED ELEMENT IS %d",x);
        break;
    case 3:
        display();
        break;
   }
   printf("\nDO YOU WANT T0 CONTINUE ");
   scanf("%d",&choice);
   printf("enter the choice\n 1.push\n2.pop\n 3.display");
   scanf("%d",&ans);

}
   
}
