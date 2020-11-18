#include "Header.h"

// tạo node mới
node* CreateNode(int data) 
{
	node* p = new node;
	p->key = data;
	p->p_left = p->p_right = NULL;
	p->height = 1;
}

// lấy chiều cao của 1 cây con
int getHeight(node* h) 
{
	if (h == NULL) return 0;
	return h->height;
}

// lấy trạng thái cân bằng của cây con
int getBalance(node* p) 
{
	if (p == NULL) // cây rỗng
		return 0; 
	return getHeight(p->p_left) - getHeight(p->p_right); 
	/*có 3 trường hợp: 
	0 -> cân bằng
	>1 -> cây trái cao hơn cây phải
	<-1 -> cây phải cao hơn cây trái*/
}

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

// xoay phải
node* rightRotate(node* p)
{
	node *r = p->p_left;
	node *temp = r->p_right;

	//thực hiện xoay phải
	r->p_right = p;
	p->p_left = temp;

	// thay đổi chiều cao
	p->height = max(getHeight(p->p_left),
		getHeight(p->p_right)) + 1;
	r->height = max(getHeight(r->p_left),getHeight(r->p_right)) + 1;

	return r; //trả về nút vừa xoay
}

// xoay trái
node* leftRotate(node* p)
{
	node *l = p->p_right;
	node *temp = l->p_left;

	//thực hiện xoay trái
	l->p_left = p;
	p->p_right = temp;

	// thay đổi chiều cao
	p->height = max(getHeight(p->p_left),
		getHeight(p->p_right)) + 1;
	l->height = max(getHeight(l->p_left), getHeight(l->p_right)) + 1;

	return l; //trả về nút vừa xoay
}

//xoay cây con (nếu không cân bằng)
node *unBalance(node* p, int bal, int data)
{
	// trái trái 
	if (bal > 1 && data < p->p_left->key)
		return rightRotate(p);

	// phải phải
	if (bal < -1 && data > p->p_right->key)
		return leftRotate(p);

	// trái phải  
	if (bal > 1 && data > p->p_left->key)
	{
		p->p_left = leftRotate(p->p_left);
		return rightRotate(p);
	}

	// phải trái  
	if (bal < -1 && data < p->p_right->key)
	{
		p->p_right = rightRotate(p->p_right);
		return leftRotate(p);
	}
	
	else return p;
}

// thêm vào cây 1 giá trị cho trước
node* Insert(node* &p_root, int x) 
{
	if (p_root == NULL) //cây trống -> thêm vào gốc
		CreateNode(x);
	else if (p_root->key == x) //đã tồn tại giá trị trong cây -> thông báo
	{
		cout << "Gia tri da ton tai trong cay." << endl;
		return NULL;
	}
	else if (x > p_root->key) //giá trị cho trước > giá trị tại nút hiện tại -> thêm vào con bên phải
		p_root->p_right = Insert(p_root->p_right, x);
	else if (x < p_root->key) //giá trị cho trước < giá trị tại nút hiện tại -> thêm vào con bên trái
		p_root->p_left = Insert(p_root->p_left, x);
	int bal = getBalance(p_root); // lấy giá trị cân băng tại nút
	p_root = unBalance(p_root, bal, x); //thực hiện xoay
	return p_root;
	
}

//duyệt trước: thăm gốc - thăm nút trái - thăm nút phải
void NLR(node* p_root)
{
	if (p_root != NULL) 
	{
		cout << p_root->key << " ";
		NLR(p_root->p_left); //thăm nút trái
		NLR(p_root->p_right); //thăm nút phải
	}
	cout << endl;
}

//duyệt giữa: thăm nút trái  - thăm gốc của trái - thăm phải của gốc
void LNR(node* p_root) 
{
	if (p_root != NULL)
	{
		LNR(p_root->p_left); //thăm nút trái
		cout << p_root->key << " ";
		LNR(p_root->p_right); //thăm nút phải
	}
	cout << endl;
}

//duyệt sau: thăm nút trái  - thăm phải - thăm gốc 
void LRN(node* p_root)
{
	if (p_root != NULL)
	{
		LRN(p_root->p_left);//thăm nút trái
		LRN(p_root->p_right); //thăm nút phải
		cout << p_root->key << " ";
	}
	cout << endl;
}

