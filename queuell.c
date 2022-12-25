#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
int data;
struct queue *link;
}node;
node *front=NULL;
node *rear=NULL;
enqueue(int n)
{
    node *new=(node*)malloc(sizeof(new));
    new->data=n;
    new->link=NULL;
    if(new==NULL)
    {
        printf("\nOVERFLOW");
    }
    else{
        if(front==NULL&&rear==NULL)
        {
            front=new;
            rear=new;
        }
        else{
            rear->link=new;
            rear=new;
        }
    }
}
dequeue()
{
    node *temp;
    if(front==NULL)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else{
        temp=front;
        front=front->link;
        printf("\nELEMENT DELETED IS- %d\n",temp->data);
        temp->link=NULL;
        if(front==NULL)
        {
            rear=NULL;
        }
        free(temp);

    }
}
display()
{
    node *temp;
    temp=front;
    while(front!=NULL)
    {
        printf("%d",front->data);
        printf("->");
        front=front->link;
    }
    printf("NULL");
    front=temp;
}
int main()
{
    int choice=1,ans,n;
    printf("enter the choice\n 1.enqueue\n 2.dequeue\n 3.display");
     scanf("%d",&ans);
    
while(choice==1)
{ 
    
   switch(ans)
   {
    case 1:
        printf("ENTER THE ELEMENT TO BE INSERTED");
        scanf("%d",&n);
        enqueue(n);
        break;
    case 2:
        dequeue();
        display();
        break;
    case 3:
        display();
        break;
   }
   printf("\nDO YOU WANT T0 CONTINUE ");
   scanf("%d",&choice);
   printf("enter the choice\n 1.enqueue\n 2.dequeue\n 3.display");
   scanf("%d",&ans);

}

}