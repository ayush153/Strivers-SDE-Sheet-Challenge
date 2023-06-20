/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* mergeList(Node* a, Node* b)
{
	if(a == NULL)
	{
		b->next = NULL;
		return b;
	}

	if(b == NULL)
	{
		a->next = NULL;
		return a;
	}

	Node* merged = NULL;

	if(a->data > b->data)
	{
        merged = b;
		b->child = mergeList(a,b->child);
	}
	else
	{
		merged = a;
		a->child = mergeList(a->child, b);
	}

	merged->next = NULL;
	return merged;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head == NULL || head->next == NULL)
		return head;
	head->next = flattenLinkedList(head->next);
	head = mergeList(head, head->next);
	return head;
}

