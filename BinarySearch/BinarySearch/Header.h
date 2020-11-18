#include <iostream>
using namespace std;

struct node
{
	int key;
	node *p_left, *p_right;
};

node* CreateNode(int data);
void NLR(node* p_root);
void LNR(node* p_root);
void LRN(node* p_root);
node* Search(node* p_root, int x);
void Insert(node* &p_root, int x);
int Height(node* p_root);