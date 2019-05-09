#ifndef LIST_LIST_HPP_
#define LIST_LIST_HPP_
#include <iostream>

using namespace std;
//mojastara
template <typename object_t>
struct slinklist_node_t
{
	object_t data;
	struct slinklist_node_t<object_t>* next;
};

template <typename object_t>
class slinklist
{
  public:
	slinklist();
	void push_front(object_t value);
	void pop_front(void);
	object_t front(void);
	bool empty(void);
	void display(void);
	object_t acces(int pos);
	int size(void);

  private:
	slinklist_node_t<object_t> *head;
	int _size;
};

template <typename object_t>
slinklist<object_t>::slinklist()
{
	this->_size = 0;
	this->head = nullptr;
}

template <typename object_t>
void slinklist<object_t>::push_front(object_t value)
{
	slinklist_node_t<object_t>* node = new slinklist_node_t<object_t>;
	node->data = value;
	node->next = this->head;
	this->head = node;
	this->_size++;
}

template <typename object_t>
void slinklist<object_t>::pop_front(void)
{
	slinklist_node_t<object_t>* node = head->next;
	delete head;
	this->head = node;
}

template <typename object_t>
object_t slinklist<object_t>::front(void)
{
	return head->data;
}

template <typename object_t>
object_t slinklist<object_t>::acces(int pos)
{
	slinklist_node_t<object_t>* node_tmp = this->head;
	while(pos--)
	{
		if(node_tmp != nullptr)
			node_tmp = node_tmp->next;
	}
	return node_tmp->data;
}

template <typename object_t>
int slinklist<object_t>::size(void)
{
	return this->_size;
}

#endif /* LIST_LIST_HPP_ */
