#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    vector <int> v;
    vector <int> v1;
    int i = 0;
    while(head != NULL)
    {
        v.push_back(head->data);
        head = head->next;
        v1.push_back(v[i]);
        i++;
    }
    reverse(v.begin(),v.end());
    
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] != v1[i]) return false;
    }
    
    return true;

}
