#include "assignment3.h"
#include <stdlib.h>

ListNodePtr reverseList(ListNodePtr head)
{
   struct ListNode *headrev;
   struct ListNode *cur, *prev;
   headrev = (struct ListNode *)malloc(sizeof(struct ListNode));
   headrev->next = NULL;
   if (head->next != NULL)
   {
      for(cur = head, prev = NULL; cur->next != NULL; prev = cur, cur = cur->next);
      headrev->key = cur->key;
      free(prev->next);
      prev->next = NULL;
      headrev->next = reverseList(head);
      return headrev;
   }
   else
   {
      headrev->key = head->key;
      free(head);
      head = NULL;
      return headrev;
   }
}

void deallocateList(ListNodePtr head)
{
   struct ListNode *prev;
   while (head->next != NULL)
   {
   prev = head;
   head = head->next;
   free(prev);
   }
   free(head);
}
