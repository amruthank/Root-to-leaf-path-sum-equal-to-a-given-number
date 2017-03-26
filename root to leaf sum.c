#include<stdio.h>
#include<stdlib.h>
#define bool int
 

struct node
{
   int data;
   struct node* left;
   struct node* right;
};
 
/*
 Given a tree and a sum, return true if there is a path from the root
 down to a leaf.
 
 Strategy: subtract the node value from the sum when recurring down,
 and check to see if the sum is 0 when you run out of tree.
*/


bool hasPathSum(struct node* root, int sum)
{
    if(!root)
		  return (sum==0);

	  sum -= root->data;

	  return (hasPathSum(root->left,sum)||hasPathSum(root->right,sum));
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
int main()
{
 
  int sum = 10;
 
  /* Constructed binary tree is
            2
          /   \
         4     5
       /  \   /  \
      3     1 3   7
  */
  struct node *root = newnode(2);
  root->left        = newnode(4);
  root->right       = newnode(5);
  root->left->left  = newnode(3);
  root->left->right = newnode(1);
  root->right->left = newnode(3);
  root->right->right = newnode(7);
 
  if(hasPathSum(root, sum))
    printf("There is a root-to-leaf path with sum %d\n", sum);
  else
    printf("There is no root-to-leaf path with sum %d\n", sum);

  return 0;
}
