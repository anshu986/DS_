#include<stdio.h>
typedef struct QUEUE
{
    int a[10];
    int front;
    int rear;
    
}queue;
enqueue(queue *q)
{
    int ele;
    if(q->front==0&&q->rear==9)
    {
    printf("OVERFLOW");
    exit(1);
    }
    else if(q->front==-1&&q->rear==-1)
    {
        q->front=0;
        q->rear=0;
        printf("\nEnter the element to be inserted\n");
        scanf("%d",&ele);
        q->a[q->rear]=ele;
    }
    else{
        q->rear++;
        printf("\nEnter the element to be inserted\n");
        scanf("%d",&ele);
        q->a[q->rear]=ele;
    }
    
}
int dequeue(queue *q)
{
    int temp;
    if(q->front==-1&&q->rear==-1)
    {
        printf("UNDERFLOW");
        exit(1);
    }
    else if(q->front==q->rear)
    {
        temp=q->a[q->front];
        q->front=-1;
        q->rear=-1;
    }
    else{
        temp=q->a[q->front];
        q->front++;
    }
return temp;
}
display(queue *q)
{
   int i;
   if(q->rear==-1)
   {
    printf("Queue is empty\n");
   }
   else{
    for(i=q->front;i<=q->rear;i++)
    {
        printf("%d ",q->a[i]);
    }
   }
}
main()
{
    queue Q;
    int i=1,res;
   int choice;
    Q.front=-1;
    Q.rear=-1; 
    while(i==1)
    {
    printf("\nEnter the operations to be performed\n1 for enqueue\n2 for dequeue\n3 for display");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            enqueue(&Q);
            break;
        case 2:
            res=dequeue(&Q);
            printf("REMOVED ELEMENT IS:%d",res);
            break;
            case 3:
            display(&Q);
            break;

    }
    printf("\n Do you want to continue?\n");
    scanf("%d",&i);
    }
   
}
   
