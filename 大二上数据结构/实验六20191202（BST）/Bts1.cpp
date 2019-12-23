#include<bits/stdc++.h>
#include "Bts.h"
using namespace std;
string T2string(int t) {
	ostringstream out;
	out << t;
	return out.str();
}



int Node::get_data()
{
	return data;
}

Node *Node::get_father_node()
{
	return father;
}

Node *Node::get_left_node()
{
	return left;
}

Node *Node::get_right_node()
{
	return right;
}
void Node::set_left(Node *l)
{
	left = l;
}

void Node::set_right(Node *righ)
{
	right = righ;
}

void Node::set_root(Node *r)
{
	father = r;
}                  
 
void Bts::midOrder(Node *r) const
{
	if(r != 0)
	{
		midOrder(r->get_left_node());
		cout<<r->get_data()<<" ";
		midOrder(r->get_right_node());
	}
}

void Bts::preOrder(Node *r) const
{
	if(r != 0)
	{
		cout<<r->get_data()<<" ";
		preOrder(r->get_left_node());
		preOrder(r->get_right_node());
	}
}

void Bts::postOrder(Node *r) const
{
	if(r != 0)
	{
		
		postOrder(r->get_left_node());
		postOrder(r->get_right_node());
		cout<<r->get_data()<<" ";
	}
}

Node *Bts::search(Node *x,int dat) const
{
	if(x == 0 && dat == x->get_data()) return x;
	if(x != 0 && dat < x->get_data()) return search(x->get_left_node(),dat);
	return search(x->get_right_node(),dat);
	
}

void Bts::insert(int data)
{
//	root->add(data);
	Node *z =new Node(data);
	size++;
	change = true;
	Node *y = 0;
	Node *x = root;
	while(x != 0)
	{
		y = x;//记录下变化前的x指的位置 
		if(z->get_data()<x->get_data())
		{
			x = x->get_left_node(); 
		}
		else
		{
			x = x->get_right_node(); 
		}
	}
	z->set_root(y);
	if(y == 0) root = z;//空树情况 
	else if (z->get_data()<y->get_data()) y->set_left(z);
	else y->set_right(z);
}

Node *Bts::get_max_node(Node *x)
{
	while(x->get_right_node() != 0) x = x->get_right_node();
	return x;
}

Node *Bts::get_min_node(Node *x)
{
	while(x->get_left_node() != 0) x = x->get_left_node();
	return x;
}



void Bts::transplant(Node *u,Node *v)
{
	if(u->get_father_node() != 0) root = v;
	else if(u == u->get_father_node()->get_left_node())
	{
		u->get_father_node()->set_left(v);
	}
	else
	{
		u->get_father_node()->set_right(v); 
	}
	if(v != 0) v->set_root(u->get_father_node());
}

void Bts::delete_node(Node *z)
{
	size--;
	change = true;
	if(z->get_left_node() == 0)
	{
		transplant(z,z->get_right_node());
	} 
	else if(z->get_right_node() == 0)
	{
		transplant(z,z->get_left_node());
	}
	else
	{
		Node *y = get_min_node(z->get_right_node());
		if(y->get_father_node() != z)
		{
			transplant(y,y->get_right_node());
			y->set_right(z->get_right_node());
			y->get_right_node()->set_root(y);
		}
		transplant(z,y);
		y->set_left(z->get_left_node());
		y->get_left_node()->set_root(y);
	}
}

Node *Bts::get_root() const
{
	return root;
}

int Bts::tree_size() const
{
	return size;
}
int Bts::tree_height(Node *r) const
{
	if(r == 0) return 0;
	int left_depth = 0,right_depth = 0;
	if(r->get_left_node() != 0)
	{
		left_depth = tree_height(r->get_left_node()); 
	} 
	if(r->get_right_node() != 0)
	{
		right_depth = tree_height(r->get_right_node());
	}
	return max(left_depth,right_depth)+1;
}

void Bts::find_node_index(Node *r,int layer)
{
	if(r != 0)
	{
		static int col;
		if(layer == 0) col = 0;
		find_node_index(r->get_left_node(),layer+1);
		nodes_index[r] = make_pair(layer,col++);
		find_node_index(r->get_right_node(),layer+1);
	}
}

int Bts::get_max_data_length() const
{
	return maxLength;
}
void Bts::print_tree() 
{ 
	if(root == 0) cout<<"空树\n";
	else
	{
		vector<pair<int ,int> >a;
		queue<Node*> q;
		q.push(root);
		a.push_back(make_pair(root->get_data(),1));
		int len = 0;
		while(!q.empty())
		{
			Node *u = q.front();
			q.pop();
			if(u->get_left_node() != 0)
			{
				q.push(u->get_left_node());
				a.push_back(make_pair(u->get_left_node()->get_data(),a[len].second<<1));	
			}
			if(u->get_right_node() != 0)
			{
				q.push(u->get_right_node());
				a.push_back(make_pair(u->get_right_node()->get_data(),a[len].second<<1|1));
			}
			len++;
		}
		int m = log(a[a.size()-1].second) / log(2);
		int num1 = (1<<(m+1)) - 1,i = 1,d = 0,p = 0;
		int num2 = num1<<1|1;
		while(i<=a[a.size()-1].second)
		{
			if(i == (1<<d))
			{
				num2>>=1;
				num1>>=1;
				for( int j = 1;j<=num1;j++) cout<<"  ";
				d++;
			}
			if(i == a[p].second)
			{
				cout<<setw(2)<<a[p].first;
				p++;
			}
			else cout<<"  ";
			if(i + 1 == (1<<d))
			{
				for(int j = 1;j<=num1;j++)
				{
					cout<<"  ";
				}
				cout<<'\n';
				cout<<'\n';
			}
			else
			{
				for(int j = 1;j<=num2;j++) cout<<"  ";
			}
			i++;
		} 
		cout<<'\n';
	}
	
	
	
	
	
	
	
//	int row = tree_height(root);
//	int col = tree_size();
//	int len = get_max_data_length() ;
//	vector<vector<string> >chart(row,vector<string>(col));
//	if(change)
//	{
//		nodes_index.clear();
//		find_node_index(root,0);
//		change = false;
//	}
//	for(int i = 0;i<row;i++)
//	{
//		for(int j = 0;j<col;j++)
//		{
//			chart[i][j] = string(len,' ');
//		}
//	}
//	map<Node *,pair<int ,int > >::iterator i = nodes_index.begin();
//	while(i != nodes_index.end())
//	{
//		int curr_row = i->second.first;
//		int curr_col = i->second.second;
//		int curr_data = i->first->get_data();
//		int blank_num = maxLength - T2string(curr_data).length();
//		string curr_str(blank_num, ' ');
//		curr_str += T2string(curr_data);
//		chart[curr_row][curr_col] = curr_str;
//		i++;
//	}
//	for (int i = 0; i < row; i++) 
//	{
//		for (int j = 0; j < col; j++) 
//		{
//			cout << chart[i][j];
//		}
//		cout << endl;
//	}

}



























