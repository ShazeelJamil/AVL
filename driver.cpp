#include<iostream>
using namespace std;
#include "AVL.h"
int main()
{
	AVL<int> t;
	int temp;
	cin >> temp;
	while (temp != -99)
	{
		t.insert(temp);
		cin >> temp;
	} 
	t.preOrder();
	cout << endl;
	cin >> temp;
	t.remove(temp);
	
	t.preOrder();
	return 0;
}