#include "assignment3.h"
#include <stdlib.h>

TreeNodePtr createBSTnode(int key)
{
   struct TreeNode *new_node;
   new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
   if (new_node == NULL)
      exit(EXIT_FAILURE);
   new_node->key = key;
   new_node->left = NULL;
   new_node->right = NULL;
   return new_node;
}

TreeNodePtr insertNodeIntoBST(TreeNodePtr root, const TreeNodePtr z)
{
   struct TreeNode *temp;
   temp = root;
   while(1)
   {
      if (z->key > temp->key && temp->right != NULL)
         temp = temp->right;
      else if (z->key <= temp->key && temp->left != NULL)
         temp = temp->left;
      else if (z->key > temp->key)
      {
         temp->right = z;
         break;
      }
      else
      {
         temp->left = z;
         break;
      }
   }
   return root;
}

TreeNodePtr insertArrayIntoBST(int n, int *A)
{
   struct TreeNode *root, *temp;
   int i;

   temp = createBSTnode(A[0]);
   root = temp;
   for (i = 1; i < n; i++)
   {
      temp = createBSTnode(A[i]);
      root = insertNodeIntoBST(root, temp);
   }

   return root;
}

void deallocateBST(TreeNodePtr root)
{
   if (root->left != NULL && root->right != NULL)
   {
      deallocateBST(root->left);
      deallocateBST(root->right);
   }
   else if (root->left != NULL && root->right == NULL)
      deallocateBST(root->left);
   else if (root->right != NULL && root->left == NULL)
      deallocateBST(root->right);

   free(root);
}

ListNodePtr convertBSTtoLinkedList(TreeNodePtr root)
{
   struct ListNode *base, *first, *p;
   base = (struct ListNode *)malloc(sizeof(struct ListNode));
   base->next = NULL;
   first = NULL;
   p = NULL;
   if (root->right != NULL)
      base->next = convertBSTtoLinkedList(root->right);
   if (root->left != NULL)
   {
      base->key = root->key;
      first = convertBSTtoLinkedList(root->left);
      p = first;
      while (first->next != NULL)
         first = first->next;
      first->next = base;
      return p;
   }
   if ((root->left == NULL && root->right == NULL) || root != NULL)
   {
      base->key = root->key;
      return base;
   }

   return NULL;
}

