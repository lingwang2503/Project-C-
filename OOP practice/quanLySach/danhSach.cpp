#include "Header.h"
#include <list>

danhSach::danhSach() 
{
	head = NULL;
	tail = NULL;
};
void danhSach::themSach(Sach sach) 
{
	if (head == NULL) {
		head = new node;
		head->sach = sach;
		tail = new node;
		tail = head;
	}
	else {
		node* temp = new node;
		temp->sach = sach;
		tail->next = temp;
		tail = temp;
	}
};
Sach* danhSach::timSach(string& tensach, string& masach) 
{
	if (head == NULL) return nullptr;
	else {
		node* headtemp = new node;
		node *temp = head;
		node* temp2;
		while (temp != nullptr) 
		{
			if ((temp->sach).ten() == tensach) 
			{
				if (headtemp == nullptr) 
				{
					headtemp->sach = temp->sach;
					headtemp->next = nullptr;
				}
				else {
					temp2 = headtemp;
					while (temp2->next != nullptr) 
					{
						temp2 = temp2->next;
					}
					temp2->next = new node;
					temp2 = temp2->next;
					temp2->sach = temp->sach;
				}
			}
			temp = temp->next;
		}
		temp2 = headtemp;
		if (temp2->next != nullptr) 
		{
			while (temp2 != nullptr) 
			{
				if ((temp2->sach).ma() == masach)
					return &temp2->sach;
				else temp2->next;
			}
		}
	}
}