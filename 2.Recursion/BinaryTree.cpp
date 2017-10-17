#include<bits/stdc++.h>
#include<algorithm>
struct node{
  char data;
  struct node* left;
  struct node* right;
};

node* createNode(char data)
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
    postOrder(root->right);
    printf("%c",root->data);
  }
}
int size(node *root)
{
	if(root==NULL)
		return 0;
	else
		return (size(root->left) +1 +size(root->right));
}
int max(int a, int b)
{
  if(a>b)
	return a;
  else
	return b;
}
int height(node *root)
{
        if(root==NULL) 
	{
	 	return -1; //처음노드가 0이므로.. -1 로 하나 빼준다.
	}
	else
	{
                return max(height(root->left),height(root->right))+1;		
	}
}


void mirror( node* root) {
  if (root==NULL) {
    return;
  }
  else {
    struct node* temp;

    // do the subtrees
    mirror(root->left); 
    mirror(root->right); 

    // swap the pointers in this node
    printf("swap %c \n",root->data);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
}

int main()
{
	node *root=createNode('a');
	root->left = createNode('b');
	root->right = createNode('c');
	root->left->left=createNode('d');
	root->left->left->right=createNode('g');
	root->right->right=createNode('f');
	root->right->left=createNode('e');
	printf("size = %d\n",size(root));
	printf("height= %d\n",height(root));
	preOrder(root);
	printf("\n");
	mirror(root);
	preOrder(root);
	printf("\n");
}
