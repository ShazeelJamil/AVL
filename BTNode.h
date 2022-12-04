#ifndef BTNODE_H
#define BTNODE_H

template<typename T>
class BTNode
{
public:
	BTNode<T>* left;
	BTNode<T>* right;
	T info;
	int height;
	
	BTNode();
	BTNode(T val);
};
#endif // !BTNODE_H