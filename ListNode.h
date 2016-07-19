struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createListNode(const vector<int> vec, int n) {
	// base case: NULL
	if ( n > vec.size() - 1 ) return NULL;
	// recurssion
	ListNode* head = new ListNode(vec[n]);
	head->next = createListNode(vec, n + 1);
	return head;
}

void deleteListNode(ListNode* head) {
	// base case
	if ( head == NULL ) return;
	
	deleteListNode(head->next);
	delete head;
}