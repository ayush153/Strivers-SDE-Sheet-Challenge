#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if (first == NULL)  return second;
      
    if (second == NULL)  return first;
       
    if (first->data >= second->data)
    {
        second->next = sortTwoLists(first, second->next);
        return second;
    }
    else
    {
        first->next = sortTwoLists(first->next, second);
        return first;
    }
}

