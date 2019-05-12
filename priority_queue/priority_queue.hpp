#ifndef PRIORITY_QUEUE_HPP_
#define PRIORITY_QUEUE_HPP_

template<typename T>
class priority_queue
{
  public:
	priority_queue(int capcity);
	~priority_queue(void);
	T top(void);
	bool empty(void);
	void push(T value);
	void pop(void);
	int size(void);
	void display(void);

  private:
	void swap(int idx1, int idx2);
	int _size;
	int _capacity;
	T* _heap;
};

template <typename T>
priority_queue<T>::priority_queue(int capacity)
{
	this->_capacity = capacity;
	this->_size = 0;
	this->_heap = new T[capacity+1];
}

template <typename T>
priority_queue<T>::~priority_queue()
{
	delete[] this->_heap;
}

template <typename T>
int priority_queue<T>::size(void)
{
	return this->_size;
}

template <typename T>
bool priority_queue<T>::empty()
{
	return (this->_size > 0) ? false : true;
}

template <typename T>
void priority_queue<T>::push(T value)
{
	if(this->_size < this->_capacity)
	{
		_heap[++_size] = value;
		int idx = _size;

		while(_heap[idx] < _heap[idx/2] && idx/2 != 0)
		{
			swap(idx, idx/2);
			idx = idx/2;
		}
	}
	return;
}

template <typename T>
void priority_queue<T>::pop(void)
{
	if(!empty())
	{
		_heap[1] = _heap[_size];
		_size--;
		int idx = 1;
		int sm_child;
		while(2*idx < _size && (_heap[idx] > _heap[idx*2] || _heap[idx] > _heap[2*idx +1]))
		{
			if(_heap[2*idx] < _heap[2*idx+1])
				sm_child = 2*idx;
			else
				sm_child = 2*idx+1;

			swap(idx, sm_child);
			idx = sm_child;
		}
	}
}

template <typename T>
void priority_queue<T>::swap(int idx1, int idx2)		//Swapping two choosen elements of array
{
	T element_tmp = _heap[idx1];
	_heap[idx1] = _heap[idx2];
	_heap[idx2] = element_tmp;
}

template <typename T>
void priority_queue<T>::display(void)
{
	std::cout << "rozmiar: " << _size << endl;
	for(int i = 1; i < _size+1; i++)
		std::cout << _heap[i] << std::endl;
}

template <typename T>
T priority_queue<T>::top(void)
{
	return _heap[1];
}

#endif /* PRIORITY_QUEUE_HPP_ */
