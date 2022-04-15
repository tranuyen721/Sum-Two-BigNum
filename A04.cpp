#include <iostream>
#include "A04.h"
#include <string>

using namespace std;

DNode* MakeNode(int data)
{
	DNode* p = new DNode;
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void Input(DList& numa, DList& numb)
{
	string temp;
	cin >> temp;
	numa.head = MakeNode(-1);
	numa.tail = MakeNode(-1);
	numb.head = MakeNode(-1);
	numb.tail = MakeNode(-1);
	DNode* p = numa.head;
	DNode* t = numa.tail;
	for (int i = 0; i < temp.length(); i++)
	{
		int data = int(temp[i]) - 48;
		DNode* q = MakeNode(data);
		p->next = q;
		q->prev = t->prev;
		t->prev = q;
		t->next = q;
		p = p->next;
	}
	cin >> temp;
	p = numb.head;
	t = numb.tail;
	for (int i = 0; i < temp.length(); i++)
	{
		int data = int(temp[i]) - 48;
		DNode* q = MakeNode(data);
		p->next = q;
		q->prev = t->prev;
		t->prev = q;
		t->next = q;
		p = p->next;
	}
}
void AddHead(SList& s,int x)
{
	SNode* p = new SNode;
	p->data = x;
	SNode* temp = s.head->next;
	s.head->next = p;
	p->next = temp;
}
void Sum(DList numa, DList numb, SList& s)
{
	int nho = 0;
	DNode* p = numa.tail->prev;
	DNode* q = numb.tail->prev;
	s.head = new SNode;
	s.head->next = NULL;
	while (p != NULL || q != NULL)
	{
		if (p == NULL && q != NULL)
		{
			AddHead(s, (q->data + nho));
			nho = 0;
			q = q->prev;
		}
		else if (p != NULL && q == NULL)
		{
			AddHead(s, (p->data + nho));
			nho = 0;
			p = p->prev;
		}
		else
		{
			int temp = p->data + q->data + nho;
			AddHead(s, (temp % 10));
			nho = (temp > 9) ? 1 : 0;
			p = p->prev;
			q = q->prev;
		}
	}
	if (nho == 1) AddHead(s, 1);
}
void Output(SList s)
{
	for (SNode* p = s.head->next; p; p = p->next)
	{
		cout << p->data;
	}
}
