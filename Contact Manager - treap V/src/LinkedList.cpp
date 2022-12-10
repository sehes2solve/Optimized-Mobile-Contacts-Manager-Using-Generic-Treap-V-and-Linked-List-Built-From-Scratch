#include "LinkedList.h"
template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& lis)
{
    head = nullptr;
    delimeter = lis.delimeter;
    Node *node_ptr = lis.head;
    while(node_ptr != nullptr)
    {
        addSorted(node_ptr->value);
        node_ptr = node_ptr->next;
    }
    //cout << *this;
}
template<class T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList& lis)
{
    head = nullptr;
    delimeter = lis.delimeter;
    Node *node_ptr = lis.head;
    while(node_ptr != nullptr)
    {
        addSorted(node_ptr->value);
        node_ptr = node_ptr->next;
    }
    return *this;
}
template<class T>
LinkedList<T>::~LinkedList()
{
    Node *node_ptr = head,*temp;
    while(node_ptr != nullptr)
    {
        temp = node_ptr;
        node_ptr = node_ptr->next;
        delete temp;
    }
}
template<class T>
typename LinkedList<T>::Node* LinkedList<T>::addSorted(T v)
{
    Node *node_ptr;
    if(head == nullptr)
    {
        head = new Node(v);
        head->next = nullptr;
        return head;
    }
    else
    {
        node_ptr = head;
        if(v < node_ptr -> value)
        {
            head = new Node(v);
            head->next = node_ptr;
            return head;
        }
    }

    while(node_ptr -> next != nullptr)
    {
        if(v < node_ptr -> next -> value)
            break;
        node_ptr = node_ptr -> next;
    }
    Node* temp = node_ptr -> next;
    node_ptr -> next = new Node(v);
    node_ptr -> next -> next = temp;
    return node_ptr -> next;
}
template<class T>
typename LinkedList<T>::Node* LinkedList<T>::get(T v)
{
    Node* node_ptr = head;
    while(node_ptr != nullptr)
    {
        if(node_ptr->value == v)
            break;
        node_ptr = node_ptr->next;
    }
    return node_ptr;
}
template<class T>
LinkedList<T>::Node::Node()
{

}
template<class T>
LinkedList<T>::Node::Node(T v)
{
    value = v;
}

template<class T>
ostream& operator<<(ostream& o, LinkedList<T> & c)
{
    typename LinkedList<T>::Node* node_ptr = c.head;
    while(node_ptr != nullptr)
    {
        o << node_ptr->value << c.delimeter;
        node_ptr = node_ptr->next;
    }
    o << '\n' ;
    return o;
}

