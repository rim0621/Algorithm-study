#include<bits/stdc++.h>

struct node{
  char data;
  struct node* left;
  struct node* right;
}

node *createNode(char data)
{
  node *n=(node *)malloc(sizeof(node));
  n->left=NULL;
  n->right=NULL;

  n->data=data;

  return n;
}

void inOrder( node* root)
{
  if(root==NULL)
  {
     return ;
  }
  else
  {
    inOrder(root->left);
    printf("%c ",root->data);
    inOrder(root->right);
  }
}
void preOrder(node* root)
{
  if(root==NULL)
  {
    return ;
  }
  else
  {
    printf("%c ",root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}
void postOrder(node* root)
{
  if(root==NULL)
  {
    return ;
  }
  else
  {
    postOrder(root->left);
    PostOrder(root->right);
    printf("%c",root->data);
  }
}



int main()
{

}
