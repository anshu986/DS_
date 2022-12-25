#include<stdio.h>
#include<stdlib.h>
typedef struct Tree{
    int data;
    struct Tree *Llink;
    struct Tree *Rlink;
}tree;
 tree* getnode()
 {
    tree *new;
    new=(tree*)malloc(sizeof(tree));
    new->Llink=NULL;
    new->Rlink=NULL;
    return new;
 }
 tree* create(int t)
 {
    tree *n1;
    n1=getnode();
    n1->data=t;
    n1->Llink=NULL;
    n1->Rlink=NULL;
    return n1;

 }
void preorder(tree* root)
 {
    if(root!=NULL)
    {

        printf("%d",root->data);

        preorder(root->Llink);
        preorder(root->Rlink);
    }
 }
void postorder(tree* root)
 {
    if(root!=NULL)
    {
        postorder(root->Llink);
        postorder(root->Rlink);
        printf("%d",root->data);
    }
 }
void inorder(tree* root)
 {
    if(root!=NULL)
    {
       
        inorder(root->Llink);
         printf("%d",root->data);
        inorder  (root->Rlink);
    }

 }
 int countnodes(tree* root)
 {
   if(root==NULL)
   return 0;
   else{
      return 1+ countnodes(root->Llink)+countnodes(root->Rlink);

   }
 }
 int count;
 int countleafnodes(tree* root)
 {
   if(root!=NULL)
   {
      countleafnodes(root->Llink);
      if(root->Llink==NULL&&root->Rlink==NULL)
      {
         count++;
      }
      countleafnodes(root->Rlink);

   }
   return count;
 }
 int countchild;
 int count1child(tree* root)
 {
   if(root!=NULL)
   {
      count1child(root->Llink);
      if((root->Llink==NULL&&root->Rlink!=NULL)||(root->Llink!=NULL&&root->Rlink==NULL))
      {
         countchild++;
      }
      count1child(root->Rlink);

   }
   return countchild;
 }
 int ans;
 int count2child(tree* root)
 {
   if(root!=NULL)
   {
      count2child(root->Llink);
      if(root->Llink!=NULL&&root->Rlink!=NULL)
      {
         ans++;
      }
      count2child(root->Rlink);

   }
   return ans;
 }
int sumofnodes(tree* root)
{
   if(root==NULL)
   return 0;
   else
   return (root->data)+ sumofnodes(root->Llink)+ sumofnodes(root->Rlink);
}
 int main()
 {
    tree *n1=NULL,*n2=NULL,*n3=NULL,*n4=NULL;
    int x,y,count;
    n1=create(2);
    n2=create(4);
    n3=create(5);
    n4=create(6);
    n1->Llink=n2;
    n1->Rlink=n3;
    n3->Llink=n4;
    printf("\nPREORDER ");
    preorder(n1);  
    printf("\nPOSTORDER ");
    postorder(n1); 
    printf("\nINORDER ");
    inorder(n1); 
    x=countnodes(n1);
    printf("\nno. of nodes %d",x);
    y=countleafnodes(n1);
    printf("\nno. of nodes %d",y); 
    y=count1child(n1);
    printf("\nno. of nodes having one child %d",countchild);  
    y=count2child(n1);
    printf("\nno. of nodes having two child %d",ans);  
    y=sumofnodes(n1);
    printf("\nsum of all nodes data is:%d",y
    );   

 }
