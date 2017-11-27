


#include "assignment3.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generateRandomIntArray(int N, int *A, int NMAX)
{
   int i;

   srand(time(NULL));

   for (i = 0; i < N; i++)
   {
      A[i] = rand() % NMAX;
   }
}

void printArray(int n, int *A)
{
   int i;
   for (i = 0; i < n; i++)
      printf("%d ", A[i]);
}

void printBSTinorder(TreeNodePtr root)
{
   if (root->right == NULL && root->left == NULL)
      printf("%d ", root->key);
   if (root->left != NULL && root->right != NULL)
   {
      printBSTinorder(root->left);
      printf("%d ", root->key);
      printBSTinorder(root->right); 
   }
   if (root->left == NULL && root->right != NULL)
   {
      printf("%d ", root->key);
      printBSTinorder(root->right);
   }
   if (root->right == NULL && root->left != NULL)
   {
      printBSTinorder(root->left);
      printf("%d ", root->key);
   }

}

void printList(ListNodePtr head)
{
   struct ListNode *headTemp = head;
   while(headTemp->next != NULL)
   {
      printf("%d ", headTemp->key);
      headTemp = headTemp->next;
   }
   printf("%d ", headTemp->key);
}

