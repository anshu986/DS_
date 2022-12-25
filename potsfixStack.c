#include <stdio.h>
#include <ctype.h>
#include<math.h>
typedef struct stack
{
    int a[10];
    int top;
} stack_type;

int overflow(stack_type *v)
{
    if(v->top==9)
    return 0;
    else
    return 1;
    
}

int underflow(stack_type *v)
{
    if(v->top==-1)
    return 0;
    else
    return 1;
    
}
void push(stack_type *v, int ele)
{
    (v->top)++;
    v->a[v->top]=ele;
}

int pop(stack_type *v)
{

    int temp =v->a[v->top];
    v->top--;
    return temp;
}

void display(stack_type *v)
{
   int i;
   for (i=(v->top+1);i>=0;i--)
   {
       printf("%d",v->a[i]);
   }
}

void init(stack_type *v)
{
    v->top=-1;
}

int main(void) {
stack_type s;
int i,j,n1,n2,n3;
init(&s);
char a[50];
printf("ENTER THE EXPRESSION");
scanf("%s",a);
printf("POSTFIX EXPRESSION IS:%s",a);
for(i=0;a[i]!='\0';i++)
{
    if(isdigit(a[i]))
    {
        j=a[i]-48;
        push(&s,j);
    }
    else{
        n1=pop(&s);
        n2=pop(&s);
        switch(a[i])
        {
            case '+':
            n3=n2+n1;
            break;
            case '-':
            n3=n2-n1;
            break;
            case '*':
            n3=n2*n1;
            break;
            case '/':
            n3=n2/n1;
            break;
            case '^':
            n3=pow(n2,n1);
            break;
        }
        push(&s,n3);
    }
}
 n1=pop(&s);
    printf("RESULT: %d",n1);
return 0;
}

