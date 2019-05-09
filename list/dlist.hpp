#ifndef LIST_LIST_HPP_
#define LIST_LIST_HPP_
#include <iostream>

using namespace std;

template <typename T>
struct dlinklist_node_t
{
	T data;
	struct dlinklist_node_t<T>* next;
	struct dlinklist_node_t<T>* prev;
};

template <typename T>
class dlinklist
{

  public:
	class dlinklist_iterator;

	dlinklist_iterator begin(){return dlinklist_iterator(head);}
	dlinklist_iterator end(){return dlinklist_iterator(nullptr);}

	dlinklist();
	~dlinklist();
	void push_front(T value);
	void push_back(T value);
	void pop_front(void);
	void pop_back(void);
	T front(void);
	T back(void);
	bool empty(void);
	void display(void);
	T acces(int pos);
	int size(void);

	class dlinklist_iterator
	{
	  public:
		dlinklist_iterator() : current_node(head) {};
		dlinklist_iterator(const dlinklist_node_t<T>* node_tmp) : current_node(node_tmp) {};

		dlinklist_iterator& operator=(dlinklist_node_t<T>* node_tmp)
		{
			this->current_node = node_tmp;
			return *this;
		}

		dlinklist_iterator& operator++()
		{
			if(current_node != nullptr)
				current_node=current_node->next;
			return *this;
		}


		dlinklist_iterator operator++(int)
		{
			dlinklist_iterator it_tmp = *this;
			++*this;
			return it_tmp;
		}

		bool operator!=(const dlinklist_iterator& iterator)
		{
			return current_node != iterator.current_node;
		}

		T operator*()
		{
			return current_node->data;
		}

	  private:
		const dlinklist_node_t<T>* current_node;
	};

  private:
	dlinklist_node_t<T>* head;
	dlinklist_node_t<T>* tail;
	int _size;
};

template <typename T>
dlinklist<T>::dlinklist()
{
	this->_size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

template <typename T>
void dlinklist<T>::push_front(T value)
{
	dlinklist_node_t<T>* node = new dlinklist_node_t<T>;
	node->data = value;
	node->next = this->head;
	this->head = node;
	this->_size++;
}

template <typename T>
void dlinklist<T>::pop_front(void)
{
	dlinklist_node_t<T>* node = head->next;
	delete head;
	this->head = node;
	_size--;
}

template <typename T>
T dlinklist<T>::front(void)
{
	return head->data;
}

template <typename T>
T dlinklist<T>::acces(int pos)
{
	dlinklist_node_t<T>* node_tmp = this->head;
	while(pos--)
	{
		if(node_tmp != nullptr)
			node_tmp = node_tmp->next;
	}
	return node_tmp->data;
}

template <typename T>
int dlinklist<T>::size(void)
{
	return this->_size;
}


#endif /* LIST_LIST_HPP_ */
