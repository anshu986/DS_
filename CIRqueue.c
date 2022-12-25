#include<stdio.h>
typedef struct Queue{
    int a[5];
    int rear;
    int front;
}queue;
enqueue(queue* q)
{
    int ele;
    if((q->front==0&&q->rear==4)||(q->front==((q->rear)+1)))
    {
        printf("OVERFLOW");
    }
    else if((q->front==-1)&&(q->rear==-1))
    {
        q->front=0;
        q->rear=0;
        printf("\nEnter the element to be inserted\n");
        scanf("%d",&ele);
        q->a[q->rear]=ele;
    }
    else if(q->rear==4)
    {
        q->rear=0;
         printf("\nEnter the element to be inserted\n");
        scanf("%d",&ele);
         q->a[q->rear]=ele;
    }
    else {
        q->rear++;
        printf("\nEnter the element to be inserted\n");
        scanf("%d",&ele);
         q->a[q->rear]=ele;
    }

}
int dequeue(queue* q)
{
    int temp;
    if((q->front==-1)||(q->front==q->rear+1))
    {
        printf("QUEUE IS EMPTY");
    }
    else if(q->front==4)
    {
        q->front=0;
        temp=q->a[q->front];
        q->front++;
    }
    else {
        temp=q->a[q->front];
        q->front++;

    }

    return temp;
}
display(queue* q)
{
    int i;
    if((q->front==-1)||(q->front==q->rear+1))
    {
        printf("QUEUE IS EMPTY");
    }
    else if(q->front==0)
    {
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->a[i]);
        }
    }
    else if(q->rear<q->front) {
        for(i=0;i<=q->rear;i++)
        {
            printf("%d ",q->a[i]);
        }
       for(i=q->front;i<=4;i++)
       {
        printf("%d ",q->a[i]);
       }
    }
    else{
        
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d",q->a[i]);
        }

    }

   
}
int main()
    {
        queue q;
        int i,ch,result,ans;
        ans=1;
        q.front=-1;
        q.rear=-1;
        while(ans==1)
        {
        printf("enter \n 1.ENQUEUE\n 2.DEQUEUE \n 3.DISPLAY");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            enqueue(&q);
            break;
            case 2:
            result=dequeue(&q);
            printf("REMOVED ELEMENT IS:%d",result);
            break;
            case 3:
            display(&q);
            break;
        }
        printf("\nDO YOU WANT TO CONTINUE\n");
        scanf("%d",&ans);
        }
        
 return 0;


    }