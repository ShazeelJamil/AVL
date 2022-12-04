#include "AVL.h"
#include<iostream>
using namespace std;
template <typename T>
AVL<T>::AVL()
{
	root = nullptr;
}
template <typename T>
bool AVL<T>:: search(T key)
{
	if (!root)
		return false;
	BTNode<T>* ptr = root;
	do
	{
		if (ptr->info == key)
			return true;
		else if (key > ptr->info)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	} while (ptr);
	return false;
}
template <typename T>
void AVL<T>::insert(T val)
{
	if (!root)
	{
		root = new BTNode<T>(val);
		return;
	}	
	bool isContinue = true;
	BTNode<T>* ptr = root;
	Stack<BTNode<T>*> st;
	while (isContinue)
	{
		if (ptr->info == val)
			return;
		if (val > ptr->info)
		{
			if (!ptr->right)
			{
				isContinue = false;
				ptr->right = new BTNode<T>(val);
				if (!ptr->left)
				{
					ptr->height = 2;
					balanceTree(st);
				}
			}
			else
			{
				st.push(ptr);
				ptr = ptr->right;
			}
		}
		else
		{
			if (!ptr->left)
			{
				isContinue = false;
				ptr->left = new BTNode<T>(val);
				if (!ptr->right)
				{
					ptr->height = 2;
					balanceTree(st);
				}
			}
			else
			{
				st.push(ptr);
				ptr = ptr->left;
			}
		}

	}
}
template<typename T>
void AVL<T>::  balanceTree(Stack<BTNode<T>*>& st)
{
	while (!st.isEmpty())
	{
		BTNode<T>* temp = st.pop();
		int l, r;
		l = (temp->left ? temp->left->height : 0);
		r = (temp->right ? temp->right->height : 0);
		if (l - r == 2)
		{
			if (temp->left->left)
				l = temp->left->left->height;
			else
				l = 0;
			if (temp->left->right)
				r = temp->left->right->height;
			else
				r = 0;
			if (l > r)	//LL
			{		
				BTNode<T>* p = temp;
				BTNode<T>* lp = p->left;
				BTNode<T>* rlp = lp->right;
				if (st.isEmpty())
					llCase(0, p, lp, rlp);
				else
					llCase(st.stackTop(), p, lp, rlp);
			}
			else				//LR
			{
				BTNode<T>* p = temp;
				BTNode<T>* lp = p->left;
				BTNode<T>* rlp = lp->right;
				if (st.isEmpty())
					lrCase(0, p, lp, rlp);
				else
					lrCase(st.stackTop(), p, lp, rlp);
			}
		}
		else if (l - r == -2)
		{
			if (temp->right->right)
				r = temp->right->right->height;
			else
				r = 0;
			if (temp->right->left)
				l = temp->right->left->height;
			else
				l = 0;
			if (l > r)	//RL
			{
				BTNode<T>* p = temp;
				BTNode<T>* rp = p->right;
				BTNode<T>* lrp = rp->left;
				if (st.isEmpty())
					rlCase(0, p, rp, lrp);
				else
					rlCase(st.stackTop(), p, rp, lrp);

			}
			else				//RR
			{
				BTNode<T>* p = temp;
				BTNode<T>* rp = p->right;
				BTNode<T>* lrp = rp->left;
				if (st.isEmpty())
					rrCase(0, p, rp, lrp);
				else
					rrCase(st.stackTop(), p, rp, lrp);
			}
		}
		else
		{
			if (temp->left && temp->right)
			{
				if (temp->left->height > temp->right->height)
					temp->height = temp->left->height + 1;
				else
					temp->height = temp->right->height + 1;
			}
			else if (!temp->left && temp->right)
				temp->height = temp->right->height + 1;
			else if (!temp->right && temp->left)
				temp->height = temp->right->height + 1;
			else
				temp->height = 1;

		}
	}
}
template <typename T>
void AVL<T>::preOrder()
{
	if (!root)
		return;
	cout << root->info << ' ';
	if (root->left)
		descendantsDisplay(root->left);
	if (root->right)
		descendantsDisplay(root->right);
}
template <typename T>
void AVL<T>::descendantsDisplay(BTNode<T>* ptr)
{
	cout << ptr->info << ' ';
	if (ptr->left)
		descendantsDisplay(ptr->left);
	if (ptr->right)
		descendantsDisplay(ptr->right);
}
template <typename T>
void AVL<T>::llCase(BTNode<T>* pp, BTNode<T>* p, BTNode<T>* lp, BTNode<T>* rlp)
{
	lp->right = p;
	p->left = rlp;
	if (p->left && p->right)
	{
		if (p->left->height > p->right->height)
			p->height = p->left->height + 1;
		else
			p->height = p->right->height + 1;
	}
	else if (p->left && !p->right)
		p->height = p->left->height + 1;
	else if (p->right && !p->left)
		p->height = p->right->height + 1;
	else
		p->height = 1;
	if (!pp)
		root = lp;
	else
	{
		if (pp->left == p)
			pp->left = lp;
		else
			pp->right = lp;
	}
	if (lp->left->height > lp->right->height)
		lp->height = lp->left->height + 1;
	else
		lp->height = lp->right->height + 1;
}
template <typename T>
void AVL<T>::rrCase(BTNode<T>* pp, BTNode<T>* p, BTNode<T>* rp, BTNode<T>* lrp)
{
	p->right = lrp;
	rp->left = p;
	if (p->left && p->right)
	{
		if (p->left->height > p->right->height)
			p->height = p->left->height + 1;
		else
			p->height = p->right->height + 1;
	}
	else if (p->left && !p->right)
		p->height = p->left->height + 1;
	else if (p->right && !p->left)
		p->height = p->right->height + 1;
	else
		p->height = 1;
	if (!pp)
		root = rp;
	else
	{
		if (pp->left == p)
			pp->left = rp;
		else
			pp->right = rp;
	}
	if (rp->left->height > rp->right->height)
		rp->height = rp->left->height + 1;
	else
		rp->height = rp->right->height + 1;
}
template<typename T>
void AVL<T>:: lrCase(BTNode<T>* pp, BTNode<T>* p, BTNode<T>* lp, BTNode<T>* rlp)
{
	lp->right = rlp->left;
	if (lp->right && lp->left)
	{
		if (lp->left->height > lp->right->height)
			lp->height = lp->left->height + 1;
		else
			lp->height = lp->right->height + 1;
	}
	else if (lp->left && !lp->right)
		lp->height = lp->left->height + 1;
	else if (lp->right && !lp->left)
		lp->height = lp->right->height + 1;
	else
		lp->height = 1;
	rlp->left = lp;
	p->left = rlp->right;
	if (p->left && p->right)
	{
		if (p->left->height > p->right->height)
			p->height = p->left->height + 1;
		else
			p->height = p->right->height + 1;
	}
	else if (!p->left && p->right)
		p->height = p->right->height + 1;
	else if (!p->right && p->left)
		p->height = p->left->height + 1;
	else
		p->height = 1;
	rlp->right = p;
	if (rlp->left && rlp->right)
	{
		if (rlp->left->height > rlp->right->height)
			rlp->height = rlp->left->height + 1;
		else
			rlp->height = rlp->right->height + 1;
	}
	else if (rlp->left && !rlp->right)
		rlp->height = rlp->left->height + 1;
	else if (rlp->right && !rlp->left)
		rlp->height = rlp->right->height + 1;
	else
		rlp->height = 1;
	if (!pp)
		root = rlp;
	else
	{
		if (pp->left == p)
			pp->left = rlp;
		else
			pp->right = rlp;
	}
}
template <typename T>
void AVL<T>:: rlCase(BTNode<T>* pp, BTNode<T>* p, BTNode<T>* rp, BTNode<T>* lrp)
{
	p->right = lrp->left;
	if (p->right && p->left)
	{
		if (p->left->height > p->right->height)
			p->height = p->left->height + 1;
		else
			p->height = p->right->height + 1;
	}
	else if (p->right && !p->left)
		p->height = p->right->height + 1;
	else if (p->left && !p->right)
		p->height = p->left->height + 1;
	else
		p->height = 1;
	rp->left = lrp->right;
	if (rp->left && rp->right)
	{
		if (rp->left->height > rp->right->height)
			rp->height = rp->left->height + 1;
		else
			rp->height = rp->right->height + 1;
	}
	else if (rp->left && !rp->right)
		rp->height = rp->left->height + 1;
	else if (rp->right && !rp->left)
		rp->height = rp->right->height + 1;
	else
		rp->height = 1;
	lrp->left = p;
	lrp->right = rp;
	if (lrp->left && lrp->right)
	{
		if (lrp->left->height > lrp->right->height)
			lrp->height = lrp->left->height + 1;
		else
			lrp->height = lrp->right->height + 1;
	}
	else if (lrp->left && !lrp->right)
		lrp->height = lrp->left->height + 1;
	else if (lrp->right && !lrp->left)
		lrp->height = lrp->right->height + 1;
	else
		lrp->height = 1;
	if (!pp)
		root = lrp;
	else
	{
		if (pp->left == p)
			pp->left = lrp;
		else
			pp->right = lrp;
	}
}
template <typename T>
void AVL<T>::remove(T val)
{
	if (!root)
		return;
	Stack<BTNode<T>*> st;
	if (root->info == val)
	{
		if (!root->left && !root->right)
			root = nullptr;
		else if (!root->left)
			root = root->right;
		else if (!root->right)
			root = root->left;
		else
		{
			st.push(root);
			root->info = removeDegree2Node(st, root);
			balanceTree(st);
		}
		return;
	}
	st.push(root);
	removeElem(st, val);
	balanceTree(st);
}
template <typename T>
void AVL<T>::removeElem(Stack<BTNode<T>*>& st, T key)
{
	if (!root->left && !root->right)
		return;
	BTNode<T>* ptr = (key >= root->info ? root->right : root->left);
	BTNode<T>* prev = root;
	while (ptr)
	{
		st.push(ptr);
		if (key == ptr->info)
		{
			if (!ptr->left && !ptr->right)
			{
				if (prev->left == ptr)
					prev->left = nullptr;
				else
					prev->right = nullptr;
				st.pop();
				delete ptr;
			}
			else if (!ptr->right && ptr->left)
			{
				if (prev->left == ptr)
					prev->left = ptr->left;
				else
					prev->right = ptr->left;
				st.pop();
				delete ptr;
			}
			else if (!ptr->left && ptr->right)
			{
				if (prev->left == ptr)
					prev->left = ptr->right;
				else
					prev->right = ptr->right;
				st.pop();
				delete ptr;
			}
			else
				ptr->info = removeDegree2Node(st,ptr);
			return;
		}
		else if (key > ptr->info)
		{
			prev = ptr;
			ptr = ptr->right;
		}
		else
		{
			prev = ptr;
			ptr = ptr->left;
		}
	}
}
template <typename T>
T AVL<T>::removeDegree2Node(Stack<BTNode<T>*>& st,BTNode<T>* ptr)
{
	BTNode<T>* prev = ptr;
	ptr = ptr->right;
	while (ptr->left)
	{
		prev = ptr;
		st.push(ptr);
		ptr = ptr->left;
	}
	if (prev->right == ptr)
		prev->right = ptr->right;
	else
		prev->left = ptr->right;
	T temp = ptr->info;
	delete ptr;
	return temp;
}