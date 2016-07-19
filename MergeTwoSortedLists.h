#indef MTSL_H
#define MTSL_H

#include "list.h"

class MeregeTwoSortedList
{

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
			
		ListNode* head = l1;
		// insert l2 in to l1

		ListNode* prev = NULL;
		ListNode* curr = l1;
		ListNode* p2_prev = NULL;
		ListNode* p2 = l2;

		// if needed, insert to the head
		if(p2->val < curr->val) {
			head = p2;
			findFirstNodeGreaterThan(curr->val, p2, p2_prev);
			p2_prev->next = curr;
		}

		// in the middle
		while(curr != NULL || p2 != NULL) {
			findFirstNodeGreaterThan(p2->val, curr, prev);
			prev->next = p2;
			findFirstNodeGreaterThan(curr->val, p2, p2_prev);
			p2_prev->next = curr;
		}

		// if needed, add all the left nodes in list 2 to the tail of list 1
		if(curr == NULL) {
			prev->next = p2;
		}
		return head;
    }

private:
    void findFirstNodeGreaterThan(int val, ListNode*& curr, ListNode*& prev) {
		while(curr->val <= val && curr != NULL) {
			prev = curr;
			curr = curr->next;
		}
    }
};

#endif