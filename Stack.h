#ifndef Stack_H
#define Stack_H
#include"Node.h"

template<typename T>
class Stack
{
	Node<T>* head;
public:
	Stack();
	void push(T h);
	bool isEmpty();
	T pop();
	T stackTop();
	~Stack();
	Stack(const Stack<T>& ref);
	Stack<T>& operator=(const Stack<T>& ref);
};

#endif // !LSLL_H


