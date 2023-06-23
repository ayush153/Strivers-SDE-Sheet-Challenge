#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if (head == NULL)
        return NULL;

    LinkedListNode<int> *temp = head;

    while (temp)
    {
        LinkedListNode<int> *node = new LinkedListNode<int>(temp->data);
        node->next = temp->next;
        temp->next = node;
        temp = node->next;
    }

    temp = head;
    while (temp)
    {
        temp->next->random = (temp->random) ? temp->random->next : NULL;
        temp = temp->next->next;
    }

    LinkedListNode<int> *ans = head->next;
    temp = head->next;
    while (head)
    {
        head->next = temp->next;
        head = head->next;
        if (head == NULL)
            break;
        temp->next = head->next;
        temp = temp->next;
    }
    return ans;
}

