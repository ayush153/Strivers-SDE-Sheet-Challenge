/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead == NULL && secondHead == NULL)
        return NULL;
    Node *ptr1 = firstHead;
    Node *ptr2 = secondHead;
    
    while(ptr1 != NULL && ptr2 != NULL && ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(ptr1 == ptr2)  return ptr1;
        if(ptr1 == NULL) ptr1 = secondHead;
        if(ptr2 == NULL) ptr2 = firstHead;  
    }
    return ptr1;
}
