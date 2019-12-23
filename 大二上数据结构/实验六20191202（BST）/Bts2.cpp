#include <bits/stdc++.h>
#include "Bts1.cpp"
using namespace std;
int main()
{
	Bts tree;
	int tmp[10] = {23,11,56,5,20,30,89,77,45,50};
    for (int i = 0;i<10;i++) tree.insert(tmp[i]);
	cout<<"²åÈë³É¹¦"<<endl; 
	tree.preOrder(tree.get_root());
	cout<<endl;
	tree.midOrder(tree.get_root());
	cout<<endl;
	tree.postOrder(tree.get_root());
	cout<<endl;
	Node *x = tree.get_root(); 
	tree.print_tree();
}


