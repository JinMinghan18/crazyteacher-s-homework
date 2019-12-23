#ifndef BTS_H_H
#define BTS_H_H
 
#include <bits/stdc++.h>

using namespace std;
class Node 
{
private:
	int data;
public:

	Node *left,*right,*father;
	Node() {data = 0;left = 0;right = 0;father = 0;}
	Node(int d){data = d;left = 0;right = 0;father = 0;}
	int get_data();
	Node *get_father_node();
	Node *get_left_node();
	Node *get_right_node();
	void set_root(Node *r);
	void set_left(Node *l);
	void set_right(Node *righ);
};
class Bts 
{
public:
	void del(int);
	Bts():root(0),size(0),maxLength(0){}
	void midOrder(Node *r) const;//÷––Ú 
	void preOrder(Node *r) const;//«∞–Ú 
	void postOrder(Node *r) const;//∫Û–Ú
	Node *search(Node *x,int dat) const;
	Node *get_root() const;
	Node *get_min_node(Node *x);
	Node *get_max_node(Node *x);
	void insert(int date);
	void delete_node(Node *z);
	void print_tree();
	int tree_size() const;
	int tree_height(Node *r) const;
	
private:
	int size,maxLength;
	Node *root;
	Node* del(Node*,int);
	void transplant(Node *u,Node *v);
	void find_node_index(Node*r,int layer);
	int get_max_data_length() const;
	map<Node *,pair<int,int> > nodes_index;
	bool change;
};
#endif

