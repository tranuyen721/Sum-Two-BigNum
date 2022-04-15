#ifndef _A04_H
#define _A04_H

struct DNode
{
	int data;
	DNode* next;
	DNode* prev;
};
struct DList
{
	DNode* head;
	DNode* tail;
};
struct SNode
{
	int data;
	SNode* next;
};
struct SList
{
	SNode* head;
};
void Input(DList& numa, DList& numb);
DNode* MakeNode(int data);
void AddHead(SList& s, int x);
void Sum(DList numa, DList numb, SList& s);
void Output(SList s);
#endif
