#include <iostream>
using namespace std;


template<typename T>
class List
{
public:
	class Node
	{
	private:
		Node* prev_node;
		Node* next_node;
		T m_data;
	public:
		Node()
		{
			prev_node = NULL;
			next_node = NULL;
			m_data = 0;
		}
		Node(T data)
		{
			m_data = data;
		}
		friend class List;
	};
	class Iterator
	{
	private:
		Node* m_p;
	public:
		Iterator()
		{
			m_p = NULL;
		}
		Iterator(Node* p)
		{
			m_p = p;
		}
		T& operator*()
		{
			return m_p->m_data;
		}
		
		Iterator& operator++()
		{
			m_p = m_p->next_node;
			return Iterator(m_p);
		}
		Iterator operator++(int)
		{
			Iterator temp(m_p);
			m_p = m_p->next_node;
			return temp;
		}
		Node* getNode()
		{
			return m_p;
		}
		bool operator!=(const Iterator& other)
		{
			return m_p!=other.m_p?1:0;
		}
		bool operator==(const Iterator& other)
		{
			return m_p==other.m_p?1:0;
		}

	};
private:
	Node* m_head;
	Node* m_tail;
	size_t m_size;
public:
	List()
	{
		m_tail = new Node();
		m_head = m_tail;
		m_size = 0;
	}
	void push_back(T data)
	{
		Node* node = new Node(data);
		if(m_size==0)
		{
			m_head = node;
			m_tail->prev_node = m_head;
			m_head->next_node = m_tail;
			m_size++;
		}else
		{
			node->prev_node = m_tail->prev_node;
			m_tail->prev_node->next_node = node;
			node->next_node = m_tail;
			m_tail->prev_node = node;
			m_size++;
		}
	}

	Iterator insert(Iterator it,const T& data)
	{
		Node* node = it.getNode();
		Node* n_node = new Node(data);
		if(it==begin())
		{
			n_node->next_node = node;
			node->prev_node = n_node;
			m_head = n_node;
		}else
		{
			node->prev_node->next_node = n_node;
			n_node->prev_node = node->prev_node;
			n_node->next_node = node;
			node->prev_node = n_node;
		}
		m_size++;
		return n_node;
	}
	Iterator erase(Iterator it)
	{
		Node* node = it.getNode();
		if(it==begin())
		{
			node->next_node->prev_node = NULL;
			m_head = node->next_node;
		}else if(it==end())
		{
			throw "over flow!";
		}else
		{
			Node* prev = node->prev_node;
			Node* next = node->next_node;
			prev->next_node = next;
			next->prev_node = prev;
		}
		m_size--;
		Node* n_node = node->next_node;
		delete node;
		return n_node;
	}

	void clear()
	{
		while(m_size!=0)
		{
			if(m_size == 1)
			{
				m_head = m_tail;
				m_size = 0;
				return ;
			}
			Node* node = m_head;
			m_head = m_head->next_node;
			m_head->prev_node = NULL;
			delete node;
			m_size--;
		}
	}

	size_t size()
	{
		return m_size;
	}
	bool empty()
	{
		return m_size==0?1:0;	
	}
	Iterator begin()
	{
		return Iterator(m_head);
	}
	Iterator end()
	{
		return Iterator(m_tail);
	}
	bool operator<(List l)
	{
		return m_size < l.m_size;
	}
	void merge(List& l)
	{
		if(*this < l)
		{
			List<T>::Iterator it = l.begin();
			for(; it!=l.end(); it++)
			{
				insert(end(),*it);
			}
		}else
		{
			List<T>::Iterator it = l.begin();
			for(; it!=l.end(); it++)
			{
				insert(begin(),*it);
			}

		}
	}
	void remove(const T& val)
	{
		List<T>::Iterator it = begin();
		for(; it!=end();)
		{
			if(*it == val)
				it = erase(it);
			else
				it++;

		}
	}
//	typedef bool (*f)(void*);
	void remove(bool (*fun)(void*))
	{
		List<T>::Iterator it = begin();
		for(; it!=end();)
		{
			if(fun(&(*it)))
				it = erase(it);
			else
				it++;

		}	
	}

};

bool func(void* m)
{
	int* p = (int*)m;
	if(*p%2!=0)
		return true;
	else
		return false;
}

template<typename T>
void show(T begin,T end)
{
	while(begin!=end)
		cout << *begin++ << " ";
	cout << endl;
}
int main()
{
	List<int> l;
	l.push_back(4);
	l.push_back(7);
	l.insert(l.begin(),9);
	List<int>::Iterator it = l.begin();
	show(l.begin(),l.end());
	cout << l.size() << endl;
	List<int> l2;
	l2.push_back(7);
	l2.push_back(9);
	l2.push_back(15);
	l2.push_back(20);
	l.merge(l2);
	show(l.begin(),l.end());
	l.remove(9);
//	it = l.begin();
//	l.erase(it);
	show(l.begin(),l.end());
	l.remove(func);
	show(l.begin(),l.end());

	return 0;
}
