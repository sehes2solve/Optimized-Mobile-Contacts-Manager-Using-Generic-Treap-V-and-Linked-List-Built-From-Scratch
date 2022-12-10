#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <string>

using namespace std;

template<class T>
class LinkedList {
public:
	class Node {
	public:
		T value;
		Node* next;
        Node();
		Node(T v);
	};
public:
	Node* head;
public:
	string delimeter; // optional: just for printing

	LinkedList();
	LinkedList(const LinkedList&);
	LinkedList operator=(const LinkedList& lis);
	Node* addSorted(T v);
	Node* get(T v);
    ~LinkedList();
	// operator overloading for printing

	template <class U>
	friend ostream& operator<<(ostream& o, LinkedList<U> & c);
};

#endif  /* LINKED_LIST_H_ */
