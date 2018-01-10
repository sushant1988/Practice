/* How to create a LinkList generic one to use in other programs */

#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<stack>

using namespace std;

struct node {
    int data;
    struct node *next ;
} ;

map <int , int> buf;
typedef struct node Node;

Node * CreateNode(int n)
{
    Node *nw_node = new Node;
    nw_node->data = n;
    nw_node->next = NULL;
    return nw_node;
}

// Insert nodes into LinkList using pointer to pointer
// O(N) time complexity
void InsertNode(Node **head , int data)
{
    Node *nw_node = CreateNode(data);
    if (*head == NULL)
        *head = nw_node ;
    else
    {
        nw_node->next = *head;
        *head = nw_node ;
    }
}

// Search node in the LinkList
// O(N) time complexity
bool SearchNode(Node *head , int data)
{
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            cout<<"Search Element "<<data<<endl;
            return true;
        }
    temp = temp->next;
    }
    cout<<"Not Found Element "<<data<<endl;
    return false;
}

// Delete nodes from LinkList
// O(1) to delete and O(N) to search the node
void DeleteNode(Node *&head, int data)
{
    Node *temp = head;
    Node *temp1 = NULL;

    while (head != NULL && head->data == data)
    {
    	temp = head;
        head = head->next;
        delete temp;
    }

    if (head == NULL)
    	return;

    temp = head;

    while(temp->next != NULL)
    {
        if(temp->next->data == data)
        {
        	Node* temp2 = temp->next;
        	temp->next  = temp->next->next;
        	delete temp2;
        	continue;
        }
        temp = temp->next;
    }

    if ( temp == NULL )
        cout<< "No data found "<< endl;
}

// Remove duplicate node using map
// O(N) space complexity for hash map and O(N) time complexity to traverse the linklist
void RemoveDuplicate(Node **head)
{
    Node *temp = *head;
    Node *temp2;
    buf[temp->data] = 1;    // add first element into map
    while( temp->next != NULL)
    {
        map<int,int> ::iterator it = buf.find(temp->next->data);
        if(it != buf.end())
        {
            temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            continue;
        }
        else
        {
            buf[temp->next->data] = 1;
        }
    temp = temp->next;
    }
}

// Remove Duplicate node using two loops by comparing
// O(N 2) time complexity
void RemoveDup1(Node **head)
{
    Node *temp = *head;
    Node *temp2;
    Node *temp3;
    while(temp!=NULL)
    {
        temp2 = temp;
        while(temp2->next != NULL)
        {
            if(temp2->next->data == temp->data)
            {
                temp3 = temp2->next;
                temp2->next = temp2->next->next;
                delete temp3;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

// Print the LinkList
void Print(Node *head)
{
    Node *temp = head;
    while ( temp != NULL)
    {
        cout<< temp->data <<" -> ";
        temp = temp->next;
    }
}

// Reverse LinkList using Iterative Method
// O(N) time complexity
void ReverseI(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *forward = head->next;
    while(forward)
    {
        current->next = prev;
        prev = current;
        current = forward;
        forward = forward->next;
    }
    current->next = prev;
    head = current;
}

// Using global pointer with recursive method
Node *h;
void ReverseRec(Node *head)
{
    if(head->next == NULL)
        h = head;
    else
    {
        ReverseRec(head->next);
        head->next->next = head;
        head->next = NULL;
    }
}

// Using stack
Node * ReverseStack(Node *head)
{
    stack<Node*> st;
    Node *temp = head;
    while(temp != NULL)
    {
        st.push(temp);
        temp = temp->next;
    }

    Node *tmpHead = st.top();
    tmpHead->next = NULL;
    st.pop();
    temp = tmpHead;
    while(!st.empty()) {
        temp->next = st.top();
        st.pop();
        temp = temp->next;
        temp->next=NULL;
    }
    return tmpHead;
}

// Without global Variable
Node* Reverse4(Node *current ,Node *next)
{
    Node *ret = NULL;
    if(current->next == NULL)
        ret = current;
    else
    {
        ret = Reverse4(current->next,current);
    }
    current->next = current;		// changing the value
return ret;
}

//Node *head=NULL;
int AddLinkList(Node *&head,Node * l1, Node *l2)
{
    int value ;
    if(l1->next == NULL && l2->next == NULL)
        {
            Node *h = new node;
            h->next = NULL;
            value = (l1->data + l2->data);
            h->data = value %10;;
            head = h;
        return (value >= 10);
        }
    int carry = AddLinkList( head,l1->next, l2->next);
    value = (l1->data + l2->data + carry);
    Node *nw = new node;
    nw ->next = head;
    nw->data = value % 10;
    head = nw;
    //head->data = value;
return (value >= 10);
}

//Node *head=NULL;
// TODO
// if linklist is straight
int AddLinkListReverse(Node *&head,Node * l1, Node *l2)
{
    int value ;
    if(l1->next == NULL && l2->next == NULL)
        {
            Node *h = new node;
            h->next = NULL;
            value = (l1->data + l2->data);
            h->data = value %10;;
            head = h;
        return (value >= 10);
        }
    int carry = AddLinkList( head,l1->next, l2->next);
    value = (l1->data + l2->data + carry);
    Node *nw = new node;
    nw ->next = head;
    nw->data = value % 10;
    head = nw;
    //head->data = value;
return (value >= 10);
}


// Copy linkList from one list to another using recursion
Node* CopyLinkList(Node* source)
{
    Node * destination;
    if(source -> next == NULL)
    {
        destination = new Node;
        destination->data = source->data;
        destination->next = NULL;
    return destination;
    }
    destination = new Node;
    destination->next = CopyLinkList(source->next);
    destination->data = source->data;

return destination;
}

// Copy linkList from one list to another using Iterative Method
Node* CopyLinkListI(Node* source)
{
    Node *destination;
    Node *previous = NULL;
    Node *temp = source->next;

    destination = new Node;
    destination->data = source->data;
    destination->next = NULL;
    previous = destination;

    while(temp != NULL)
    {
        Node *current;
        current = new Node;
        current->data = temp->data;
        current->next = NULL;
        previous->next = current;

    previous = current;
    temp = temp->next;
    }
return destination;
}

// Get Kth to last element from LinkList recursive
int GetKthLastElement(Node *head, int K, Node *&result)
{
    if(head == NULL)
        return 0;

    int i = GetKthLastElement(head->next,K,result) + 1;

    if(i == K)
        result = head;

return i;
}

int main()
{
    Node * head = NULL;
    Node *l1 = NULL;
    Node * l2 = NULL;
    InsertNode(&l1 , 4);
    InsertNode(&l1 , 7);
    InsertNode(&l1 , 9);
    InsertNode(&l2 , 6);
    InsertNode(&l2 , 5);
    InsertNode(&l2 , 8);
    Print (l1);
    Node *revHead = ReverseStack(l1);
    cout<<endl;
	Print(revHead);
    cout<<endl;
    //insert(&head , i);
    //for(int i = 0; i<10;i++)
    //	insert(&head , i);
//    DeleteNode(l1, 9);
//    Print(NULL);
    //search(l1,3);
    //insert(&head,3);
    //insert(&head,2);
    //Print(head);
    //removedup1(&head);
    /*int x = add(head,l1,l2);
    if (x ==1)
            {
                    Node *nw = new node;
                    nw->data = x;
                    nw->next = head;
                    head = nw;
            }
    Print(head);*/
    cout<<endl;
    //Node *temp = NULL;
    //head = reverse4(head,temp);
/*	{
            Node *temp = reverse2(head);
            temp->next = NULL;
            Print(h);
    }*/
    //Print(head);

//    Node * header = CopyLinkListI(l1);
//    Print(header);
return 0;
}
