#ifndef AVL_H
#define AVL_H
#include"BTNode.h"
#include"Stack.h"
template <typename T>
class AVL
{
	BTNode<T>* root;

	void balanceTree(Stack<BTNode<T>*>& st);
	void llCase(BTNode<T>* pp, BTNode<T>* p, BTNode<T>* lp, BTNode<T>* rlp);
	void rrCase(BTNode<T>* pp, BTNode<T>* p, BTNode<T>* lp, BTNode<T>* rlp);
	void rlCase(BTNode<T>* pp, BTNode<T>* p, BTNode<T>* rp, BTNode<T>* rrp);
	void lrCase(BTNode<T>* pp, BTNode<T>* p, BTNode<T>* lp, BTNode<T>* rlp);
	void descendantsDisplay(BTNode<T>* ptr);
	T removeDegree2Node(Stack<BTNode<T>*>& st, BTNode<T>* ptr);
	void removeElem(Stack<BTNode<T>*>& st, T key);
public:
	AVL();
	void preOrder();
	void insert(T val);
	void remove(T val);
	bool search(T key);
};
#endif // !AVL_H


