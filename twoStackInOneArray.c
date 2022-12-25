#include <stdio.h>
typedef struct stack
{
    int a[10];
    int top1,top2;
} stack_type;

int overflow(stack_type *v)
{
    if(v->top1+1==v->top2)
    return 0;
    else
    return 1;
    
}

int underflow(stack_type *v)
{
    if(v->top1==-1&&v->top2==10)
    return 0;
    else
    return 1;
    
}
void push1(stack_type *v)
{
    int ele;
    printf("ENTER THE ELEMENT TO BE INSERTED");
    scanf("%d",&ele);
    (v->top1)++;
    v->a[v->top1]=ele;
}
void push2(stack_type *v)
{
    int ele;
    printf("ENTER THE ELEMENT TO BE INSERTED");
    scanf("%d",&ele);
    (v->top2)--;
    v->a[v->top2]=ele;
}

int pop1(stack_type *v)
{

    int temp =v->a[v->top1];
    v->top1--;
    return temp;
}
int pop2(stack_type *v)
{

    int temp =v->a[v->top2];
    v->top2++;
    return temp;
}

void display1(stack_type *v)
{
   int i;
   printf("STACK1:");
   for (i=(v->top1);i>=0;i--)
   {
       printf("%d ",v->a[i]);
   }
}
void display2(stack_type *v)
{
   int i;
      printf("STACK2:");
   for (i=(v->top2);i<=9;i++)
   {
       printf("%d ",v->a[i]);
   }
}

void init(stack_type *v)
{
    v->top1=-1;
    v->top2=10;
}

int main(void) {
stack_type s;
int o,ov,r,choice,wish;
init(&s);
do{
    printf("ENTER THE CHOICE\n1)push1\n2)push2\n3)pop1\n4)pop2\n5)display1\n6)display2\n");
    scanf("%d",&choice);
    switch(choice){
   
    case 1:
    ov=overflow(&s);
    if(ov==0){
        printf("Push not possible");
    }
    else{
        push1(&s);
    }
     break;

     case 2:
    ov=overflow(&s);
    if(ov==0){
        printf("Push not possible");
    }
    else{
        push2(&s);
    }
     break;

      case 3:
    ov=underflow(&s);
    if(ov==0){
        printf("pop not possible");
        }
    else{
        r=pop1(&s);
        printf("POPPED ELEMENT: %d",r);
    }
    break;

    
      case 4:
    ov=underflow(&s);
    if(ov==0){
        printf("pop not possible");
        }
    else{
        r=pop2(&s);
        printf("POPPED ELEMENT: %d",r);
    }
    break;
    case 5:
    display1(&s);
     break;

    case 6:
    display2(&s);
     break;

    }
    printf("\nDo You Want To Continue?");
scanf("%d",&wish);
}while(wish==1);
return 0;
}