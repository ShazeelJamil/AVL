#include "BTNode.h"
template <typename T>
BTNode<T>::BTNode()
{
	right = left = nullptr;
	height = 1;
}
template <typename T>
BTNode<T>::BTNode(T val) : info(val)
{
	right = left = nullptr;
	height = 1;
}