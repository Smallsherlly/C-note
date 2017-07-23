#include "list.h"

//创建链表节点
Node* create_node(int data)
{
	Node* node = new Node;
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return node;
}
class MyList
{
private:
	Node* m_head;
	Node* m_tail;
	int m_size;
public:
	//构造函数
	MyList()
	{
		m_head = NULL;
		m_tail = NULL;
		m_size = 0;
	}
	//拷贝构造函数
	MyList(const MyList& that):m_size(that.m_size)
	{
		int i = 0;
	}
	bool empty(List* list)
	{
		return list.m_size;
	}
	void push_head(List* list,int data)
	{
		Node* node = create_node(data);
		if(empty(list))
		{
			list->m_head = node;
			list->m_tail = node;
			list->m_size++;
			return ;
		}
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
		list->m_size++;
	}
	void push_tail(List* list,int data)
	{
		Node* node = create_node(data);
		if(empty(list))
		{
			list->m_head = node;
			list->m_tail = node;
			list->m_size++;
			return;
		}
		list->m_tail->next = node;
		node->prev = list->m_tail;
		list->m_tail = node;
		list->m_size++;
	}
};

int main()
{
	
	return 0;
}
