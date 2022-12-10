#include <random>
#include <stack>
#include <queue>
#include <ctime>
#include "Treap.h"

template<class T, class V>
Treap<T, V>::Treap()
{
    root = nullptr;
}
template<class T, class V>
typename Treap<T, V>::Node* Treap<T, V>::rotateRight(Node* Q)
{
    Node* temp = Q->right;
    Q->right = Q->left->right;
    Q->left->right = temp;
    temp = Q->left;          ///Q node got children of Q->left &
    Q->left = Q->left->left;///Q->left got Q->right in it's right
    temp->left = Q;
    return temp;
}
template<class T, class V>
typename Treap<T, V>::Node* Treap<T, V>::rotateLeft(Node* Q)
{
    Node* temp = Q->left;
    Q->left = Q->right->left;
    Q->right->left = temp;
    temp = Q->right;
    Q->right = Q->right->right;
    temp->right = Q;
    return temp;
}

template<class T, class V>
typename Treap<T, V>::Node* Treap<T, V>::balance(Node* root)
{
    Node* node = root;
    if(node->right != nullptr)
    {
        if(node->right->priority > node->priority)
            return rotateLeft(node);
    }
    if(node->left != nullptr)
    {
        if(node->left->priority > node->priority)
            return rotateLeft(node);
    }
    return node;
}
template<class T, class V>
typename Treap<T, V>::Node* Treap<T, V>::insert(Node* root, T k, V v)
{
    cout << v->getName() << endl;
    stack<Node*> parents;
    Node *node = this->root, *prev_node = this->root, *added_node = new Node(k,v);
    while(node != nullptr)
    {
        if(node->key > k)
        {
            if(node != prev_node)
                parents.push(prev_node);
            prev_node = node;
            node = node->left;
        }
        else
        {
            if(node != prev_node)
                parents.push(prev_node);
            prev_node = node;
            node = node->right;
        }
    }
    if(prev_node == nullptr)///node == root,prev_node == node,sizz == 0
    {
        this->root = added_node;
        return this->root;
    }
    else if(prev_node->key > k)
    {
        prev_node->left = added_node;
    }
    else
    {
        prev_node->right = added_node;
    }
    Node* parent;
    while(!parents.empty())
    {
        node = balance(prev_node);
        if(node == prev_node)
            break;
        parent = parents.top();
        parents.pop();
        ///Link Parent of prev_node with new head resulted from rotation
        if(parent->left != nullptr && parent->left == prev_node)
            parent->left = node;
        else
            parent->right = node;
        prev_node = parent;
    }
    return prev_node;
}
template<class T, class V>
void Treap<T, V>::insert(T k, V v)
{
    insert(root,k,v);
}
template<class T, class V>
V  Treap<T, V>::find(Node* root, T k)
{
    while(root != nullptr)
    {
        if(root->key == k)
            return root->value;
        else if(root->key > k)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}
template<class T, class V>
V Treap<T, V>::find(T k)
{
    return find(root,k);
}
template<class T, class V>
Treap<T, V>::Node::Node(T k, V v)
{
    key = k;
    value = v;
    srand(time(0));
    int maxx = 1000;
    maxx = (int)(rand()%(maxx + 1));
    priority = maxx;
    left = nullptr;
    right = nullptr;
}

template<class T, class V>
ostream& operator<<(ostream &o, typename Treap<T, V>::Node root)
{
    o << "Key : " << root.key << "Value : " << *root.value ;
    return o;
}
template<class T, class V>
ostream& operator<<(ostream &o, Treap<T, V> tree)
{
    typename Treap<T, V>::Node* node = tree.root;
    if(node != nullptr)
    {
        queue<typename Treap<T, V>::Node*> nodes;
        nodes.push(node);
        while(!nodes.empty())
        {
            node = nodes.front();
            nodes.pop();
            o << node << " ";
            if(node->left != nullptr)
                nodes.push(node->left);
            if(node->right != nullptr)
                nodes.push(node->right);
        }
        o << endl;
    }
    else
        o << "Tree is empty!!!" << endl;
    return o;
}
