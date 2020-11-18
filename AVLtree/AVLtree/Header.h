#include <iostream>
using namespace std;

struct node
{
	int key;
	node* p_left, *p_right;
	int height;
};

node* CreateNode(int data); //câu 1
int getHeight(node* h);
int getBalance(node* p);
int max(int a, int b);
node* rightRotate(node* p);
node* leftRotate(node* p);
node *unBalance(node* p, int bal, int data);
node* Insert(node* &p_root, int x); //câu 2
void NLR(node* p_root); //câu 5
void LNR(node* p_root); //câu 6
void LRN(node* p_root); //câu 7