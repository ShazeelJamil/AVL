#include "Stack.h"
#include<iostream>
using namespace std;

template<typename T>
Stack<T>::Stack()
{
	head = nullptr;
}
template<typename T>
bool Stack<T>:: isEmpty()
{
	return head == nullptr;
}
template<typename T>
void Stack<T>::push(T h)
{
	Node<T>* temp = new Node<T>(h);
	temp->next = head;
	head = temp;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& ref)
{
	if (!ref.head)
	{
		head = nullptr;
		return;
	}
	Node<T>* refPtr = ref.head;
	Node<T>* objPtr = new Node<T>(refPtr->info);
	head = objPtr;
	while (refPtr->next)
	{
		refPtr = refPtr->next;
		objPtr->next = new Node<T>(refPtr->info);
		objPtr = objPtr->next;
	}
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& ref)
{
	if (&ref == this)
		return *this;
	this->~Stack<T>();
	if (!ref.head)
		return *this;
	Node<T>* refPtr = ref.head;
	Node<T>* objPtr = new Node<T>(refPtr->info);
	head = objPtr;
	while (refPtr->next)
	{
		refPtr = refPtr->next;
		objPtr->next = new Node<T>(refPtr->info);
		objPtr = objPtr->next;
	}
	return *this;
}
template <typename T>
Stack<T>::~Stack()
{
	if (!head)
		return;
	Node<T>* temp = head;
	Node<T>* traverse;
	while (temp)
	{
		traverse = temp->next;
		delete temp;
		temp = traverse;
	}
	head = nullptr;
}
template<typename T>
T Stack<T>::pop()
{
	if (!head)
		throw string("Stack is empty");
	Node<T>* temp1 = head->next;
	T temp2 = head->info;
	delete head;
	head = temp1;
	return temp2;
}
template<typename T>
T Stack<T> :: stackTop()
{
	if (!head)
		throw string("Stack is empty");
	Node<T>* temp1 = head->next;
	return head->info;
}