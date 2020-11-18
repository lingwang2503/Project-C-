#include "Header.h"

//tạo node mới
node* CreateNode(int data)
{
	node *p = new node;
	p->p_left = NULL;
	p->p_right = NULL;
	p->key = data;
	return p;
}

//duyệt trước
void NLR(node* p_root)
{
	if (p_root != NULL)
	{
		cout << p_root->key << " ";
		NLR(p_root->p_left);
		NLR(p_root->p_right);
	}
	cout << endl;
}

//duyệt giữa
void LNR(node* p_root)
{
	if (p_root != NULL)
	{
		LNR(p_root->p_left);
		cout << p_root->key << " ";
		LNR(p_root->p_right);
	}
	cout << endl;
}

//duyệt sau
void LRN(node* p_root)
{
	if (p_root != NULL)
	{
		LRN(p_root->p_left);
		LRN(p_root->p_right);
		cout << p_root->key << " ";
	}
	cout << endl;
}

//tìm giá trị cho trước
node* Search(node* p_root, int x)
{
	if (p_root == NULL) //cây rỗng
		return NULL;
	else if (p_root->key == x) //giá trị = giá trị tại nút -> trả về nút 
		return p_root;
	else if (p_root->key < x) //giá trị > giá trị tại nút -> search tiếp con bên trái
		return Search(p_root->p_left, x);
	else if (p_root->key > x) //giá trị < giá trị tại nút -> search tiếp con bên phải
		return Search(p_root->p_right, x);
}

//thêm vào cây 1 giá trị cho trước
void Insert(node* &p_root, int x)
{
	if (p_root == NULL) //rỗng -> tạo cây mới
	{
		CreateNode(x);
	}
	else if (x > p_root->key) //giá trị > giá trị tại nút -> thêm vào con bên phải
	{
		Insert(p_root->p_right, x);
	}
	else if (x < p_root->key) //giá trị < giá trị tại nút -> thêm vào con bên trái
	{
		Insert(p_root->p_left, x);
	}
}

//tính chiều cao của cây
int Height(node* p_root)
{
	if (p_root == NULL)
		return 0;
	int heightLeft = Height(p_root->p_left);
	int heightRight = Height(p_root->p_right);
	if (heightLeft > heightRight)
		return (heightLeft + 1);
	else
		return (heightRight + 1);

}

