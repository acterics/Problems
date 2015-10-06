// QueueDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Queue.h"

namespace Queue {

	template <typename Type>
	Queue<Type>::Node::Node() :
		prev_(nullptr), next_(nullptr), data_(nullptr)
	{
	}
	template <typename Type>
	Queue<Type>::Node::Node(Type data) :
		prev_(nullptr), next_(nullptr), data_(new Type(data))
	{
	}

	template <typename Type>
	Queue<Type>::Node::Node(Type * data) :
		prev_(nullptr), next_(nullptr), data_(new Type(*data))
	{
	}

	template <typename Type>
	Queue<Type>::Node::Node(Node * copiedNode) :
		data_(copiedNode->data()), next_(copiedNode->next()), prev_(copiedNode->prev())
	{
	}
	
	template <typename Type>
	Type* Queue<Type>::Node::data() const
	{
		return data_;
	}

	template <typename Type>
	void Queue<Type>::Node::setData(Type * value)
	{
		data_ = value;
	}

	template <typename Type>
	void Queue<Type>::Node::setData(Type value) 
	{
		if (!data_)
			data_ = new Type(value);
		else
		{
			*data_ = value;
		}
	}

	template <typename Type>
	typename Queue<Type>::Node* Queue<Type>::Node::next() const
	{
		return next_;
	}

	template <typename Type>
	void Queue<Type>::Node::setNext(typename Queue<Type>::Node * value)
	{
		next_ = value;
	}

	template <typename Type>
	typename Queue<Type>::Node* Queue<Type>::Node::prev() const
	{
		return prev_;
	}

	template <typename Type>
	void Queue<Type>::Node::setPrev(typename Queue<Type>::Node * value)
	{
		prev_ = value;
	}

	template <typename Type>
	Queue<Type>::Queue() :
		head_(nullptr), tail_(nullptr)
	{
	}

	template <typename Type>
	Queue<Type>::Queue(int queueSize, Type(*getRandomItem)(void)) :
		head_(nullptr), tail_(nullptr)
	{
		fillQueue(queueSize, getRandomItem);
	}

	template <typename Type>
	Queue<Type>::Queue(typename Queue<Type> * copiedList) :
		head_(nullptr), tail_(nullptr)
	{
		if (!copiedList->head())
			return;
		Node * current = copiedList->head();
		while (current)
		{
			this->push(current->data());
			current = current->next();
		}
	}

	template <typename Type>
	Queue<Type>::~Queue()
	{

	}

	template <typename Type>
	void Queue<Type>::push(Type value)
	{
		if (!head_)
		{
			head_ = new Node(value);
			tail_ = head_;
		}
		else
		{
			Node * pushingNode = new Node(value);
			tail_->setNext(pushingNode);
			pushingNode->setPrev(tail_);
			tail_ = pushingNode;
		}
	}

	template <typename Type>
	void Queue<Type>::push(Type * value)
	{
		this->push(*value);
	}

	template <typename Type>
	void Queue<Type>::push(typename Queue<Type>::Node * value)
	{
		if (!head_)
		{
			head_ = new Node(value);
			tail_ = head_;
		}
		else
		{
			tail_->setNext(value);
			value->setPrev(tail_);
			tail_ = value;
		}
	}

	template <typename Type>
	void Queue<Type>::pop()
	{
		if (!head_)
			return;
		else if(!head->next())
		{
			delete head_;
			head_ = tail_ = nullptr;
		}
		else
		{
			Node * deletingNode = head_;
			head_ = head_->next();
			head_->setPrev(nullptr);
			delete deletingNode;
		}
	}

	template <typename Type>
	Type Queue<Type>::front()
	{
		return *head_->data();
	}

	template <typename Type>
	typename Queue<Type>::Node * Queue<Type>::head() const
	{
		return head_;
	}

	template <typename Type>
	typename Queue<Type>::Node * Queue<Type>::tail() const
	{
		return tail;_
	}

	template <typename Type>
	void Queue<Type>::setHead(typename Queue<Type>::Node * value)
	{
		head_ = value;
	}

	template <typename Type>
	void Queue<Type>::setTail(typename Queue<Type>::Node * value)
	{
		tail_ = value;
	}

	template <typename Type>
	std::ostream& operator<<(std::ostream& outputStream, Queue<Type> const & queue)
	{
		auto current = queue.head();

		while (current)
		{
			outputStream << *current->data() << " ";
			current = current->next();
		}
		outputStream << std::endl;
		return outputStream;
	}

	template <typename Type>
	void Queue<Type>::insertSort(bool(*compare)(Type firstComparedItem, Type secondComparedItem))
	{
		Node * outerIterator = head_->next();
		Node * innerIterator;
		while (outerIterator)
		{
			innerIterator = outerIterator;
			while (innerIterator->prev() && compare(*innerIterator->prev()->data(), *innerIterator->data()))
			{
				swap(innerIterator, innerIterator->prev());
				innerIterator = innerIterator->prev();
			}
			outerIterator = outerIterator->next();
		}
	}



	template <typename Type>
	void Queue<Type>::recursiveQuickSort(typename Queue<Type>::Node * leftItem, typename Queue<Type>::Node * rightItem, 
		bool(*compare)(Type firstComparedItem, Type secondComparedItem))
	{
		Node * startItem;
		Node * current;
		if (leftItem == rightItem)
			return;
		startItem = leftItem;
		current = startItem->next();
		while (true)
		{
			if (compare(*current->data(), *startItem->data()))
				swap(current, startItem);
			if (current == rightItem)
				break;
			current = current->next();
		}
		swap(current, leftItem);
		Node* oldCurrent = current;
		current = current->prev();
		if (current)
		{
			if ((leftItem->prev() != current) && (current->next() != leftItem))
				recursiveQuickSort(leftItem, current, compare);
		}

		current = oldCurrent->next();
		if (current)
		{
			if ((current->prev() != rightItem) && (rightItem->next() != current))
				recursiveQuickSort(current, rightItem, compare);
		}

	}

	
	template <typename Type>
	void Queue<Type>::quickSort(bool(*compare)(Type firstComparedItem, Type secondComparedItem))
	{
		recursiveQuickSort(head_, tail_, compare);
	}

	template <typename Type>
	void Queue<Type>::swap(typename Queue<Type>::Node * firstItem, typename Queue<Type>::Node * secondItem)
	{
		Type * tempData = firstItem->data();
		firstItem->setData(secondItem->data());
		secondItem->setData(tempData);
	}

	template <typename Type>
	int Queue<Type>::size()
	{
		int iterator = 0;
		Node* current = head_;
		while (current)
		{
			iterator++;
			current = current->next();
		}
		return iterator;
	}

	template <typename Type>
	void Queue<Type>::fillQueue(int queueSize, Type(*getRandomItem)(void))
	{
		for (int iterator = 0; iterator < queueSize; iterator++)
			this->push(getRandomItem());
	}

	template <typename Type>
	void Queue<Type>::reFillQueue(Type(*getRandomItem)(void))
	{
		Node * current = head_;
		while (current)
		{
			current->setData(getRandomItem());
			current = current->next();
		}
	}

}