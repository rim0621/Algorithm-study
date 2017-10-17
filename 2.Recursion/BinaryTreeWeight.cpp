#include<bits/stdc++.h>


struct node{
	int weight;
	struct node* left;
	struct node* right;
};

node* createNode(int data)
{
  node *n=(node *)malloc(sizeof(node));
  n->left=NULL;
  n->right=NULL;

  n->weight=data;

  return n;
}

int sumOfWeight(struct node *root)
{
	if(root==NULL)
	{
		 return 0;
	}
	else
	{
		 return sumOfWeight(root->left)+sumOfWeight(root->right)+root->weight;
	}
}
int max(int left,int right)
{
	if(left>right)
		return left;
	else
		return right;
}
int maxPathWeight(struct node *root)
{
	if(root==NULL)
		 return 0;
	else
	{
		 int leftWeight,rightWeight;
		 leftWeight=root->weight+maxPathWeight(root->left);
		 rightWeight=root->weight+maxPathWeight(root->right);
		 return max(leftWeight,rightWeight);
	}
}

int main()
{
	node *root=createNode(6);
	root->left=createNode(2);
	root->left->left=createNode(4);
	root->left->left->right=createNode(3);
	root->right=createNode(1);
	root->right->left=createNode(9);
	root->right->right=createNode(7);
	printf("%d\n",sumOfWeight(root));
	printf("%d\n",maxPathWeight(root));
}	
