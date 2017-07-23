#ifndef _LIST_H__
#define _LIST_H__

#include <iostream>
#include <cstdio>
#include <cstdlib>
struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct List
{
	Node* head;
	Node* tail;
	int size;
};

Node* create_node(int data);
void init(List* list);
void deinit(List* list);
void push_head(List* list,int data);
void push_tail(List* list,int data);
bool insert(List* list,int index,int data);
bool pop_head(List* list);
bool pop_tail(List* list);
//bool delete(List* list,int index);
Node* get_head(List* list);
Node* get_tail(List* list);
Node* get_node(List* list,int index);
//bool updata(List* list,int old,int new);
//bool modify(List* list,int index,int new);
bool empty(List* list);
size_t size(List* list);
Node* find(List* list,int data);
void travel(List* list);

#endif //_LIST_H__
