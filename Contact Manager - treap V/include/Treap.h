#ifndef TREAP_H_
#define TREAP_H_
#include <iostream>

using namespace std;

template<class T, class V>
class Treap {
public:
	class Node {
	public:
		Node *left, *right;
		T key;
		V value;
		int priority;

		Node(T k, V v);
		template<class U, class X>
		friend ostream& operator<<(ostream &o, typename Treap<U, X>::Node root);
	};
private:
	Node* root;

	Node* rotateRight(Node* Q);
	Node* rotateLeft(Node* P);
	Node* balance(Node* root);
	Node* insert(Node* root, T k, V v);
	V find(Node* root, T k);
public:
	Treap();
	void insert(T k, V v);
	V find(T k);
	template<class U, class X>
	friend ostream& operator<<(ostream &o, Treap<U, X> tree);
};

#endif /* TREAP_H_ */
