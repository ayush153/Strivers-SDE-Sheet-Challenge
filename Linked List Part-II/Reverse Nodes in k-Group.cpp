#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head == NULL) return head;
	
	Node *dummy = new Node(0);

	dummy->next = head;

	Node *prev = dummy, *next = dummy, *curr = dummy;

	int cnt = 0;

	while(head)
	{
		cnt++;
		head = head->next;
	}

	int j = 0;

	while(j < n && cnt > 0)
	{
		if(b[j] == 0)
		{
			j++;
			continue;
		}

		curr = prev->next;
		next = curr->next;

		for(int i = 1; i < min(b[j], cnt); i++)
		{
			curr->next = next->next;
			next->next = prev->next;
			prev->next = next;
			next = curr->next;
		}
		prev = curr;
		cnt -= min(b[j],cnt);
		j++;
	}

	return dummy->next;

}
