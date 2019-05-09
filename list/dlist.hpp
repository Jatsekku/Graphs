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

	dlinklist_iterator begin(void) {return dlinklist_iterator(head);}
	dlinklist_iterator end(void) {return dlinklist_iterator(tail);}

	dlinklist();
	~dlinklist();

	void push_front(T value);
	void push_back(T value);
	void pop_front(void);
	void pop_back(void);

	dlinklist_iterator insert(dlinklist_iterator pos, T value)
	{
		dlinklist_node_t<T>* node_tmp = new dlinklist_node_t<T>;
		node_tmp->data = value;

		node_tmp->prev = pos.current_node;
		node_tmp->next = pos.current_node->next;

		pos.current_node->next->prev = node_tmp;
		pos.current_node->next = node_tmp;
	};

	dlinklist_iterator erase(dlinklist_iterator pos)
	{

	};

	void display_list(){
		dlinklist_node_t<T> *node_tmp = head;
		for(int i=0;i<_size ;i++){
		cout<<node_tmp->data<<endl;
		node_tmp=node_tmp->prev;
		}
	}

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
dlinklist<T>::~dlinklist()
{

}


template <typename T>
void dlinklist<T>::push_front(T value)
{
	dlinklist_node_t<T>* node_tmp = new dlinklist_node_t<T>;
	node_tmp->data = value;

	/*
	node_tmp->next = head;
	node_tmp->prev = nullptr;
	if(head != nullptr)
		head->prev =  node_tmp;
	this->head = node_tmp;
	 */

	if(head == nullptr)
	{
		node_tmp->next = head;
		node_tmp->prev = tail;
		head = node_tmp;
		tail = node_tmp;
	}
	else
	{
		head->next = node_tmp;
	    node_tmp->prev=head;
		head=node_tmp;
		node_tmp->next=nullptr;
	}


	_size++;
}

template <typename T>
void dlinklist<T>::push_back(T value)
{
	dlinklist_node_t<T>* node_tmp = new dlinklist_node_t<T>;
	node_tmp->data = value;
	if(tail == nullptr)
	{
		head = node_tmp;
		tail = node_tmp;
	}
	else
	{
		tail->prev = node_tmp;
		node_tmp->next = tail;
		tail = node_tmp;
		node_tmp->prev=nullptr;
	}
	_size++;
}

template <typename T>
void dlinklist<T>::pop_front(void)
{
	if(!empty())
	{
		dlinklist_node_t<T>* node_tmp = head;

		if(head == tail)
		{
			tail = nullptr;
			head = nullptr;
		}
		else
		{
			head = head->next;
			head->prev = nullptr;
		}

		delete node_tmp;
		_size--;
	}
}

template<typename T>
void dlinklist<T>::pop_back(void)
{
	if(!empty())
	{
		dlinklist_node_t<T>* node_tmp = tail;

		if(head == tail)
		{
			head == nullptr;
			tail == nullptr;
		}
		else
		{
			tail->next = nullptr;
			tail = tail->prev;
		}

		delete node_tmp;
		_size--;
	}
}

template <typename T>
T dlinklist<T>::front(void) {return head->data;}

template <typename T>
T dlinklist<T>::back(void) {return tail->head;}

template <typename T>
bool dlinklist<T>::empty(void) {return (size > 0)? false : true;}

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
