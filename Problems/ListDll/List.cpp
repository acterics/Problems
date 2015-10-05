// ListDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "List.h"



namespace List
{
	template <typename Type>
	List<Type>::Node::Node() :
		next_(nullptr), data_(nullptr)
	{
	}

	template<typename Type>
	List<Type>::Node::Node(Node * copiedNode) :
		this(copiedNode)
	{
	}

	template <typename Type>
	List<Type>::Node::Node(Type* data) :
		next_(nullptr), data_(new Type(*data))
	{
	}

	template<typename Type>
	List<Type>::Node::Node(Type data) :
		next_(nullptr), data_(new Type(data))
	{
	}

	template<typename Type>
	Type * List<Type>::Node::data() const
	{
		return data_;
	}

	template<typename Type>
	void List<Type>::Node::setData(Type * val)
	{
		data_ = val;
	}

	template<typename Type>
	typename List<Type>::Node * List<Type>::Node::next() const
	{
		return next_;
	}

	template<typename Type>
	void List<Type>::Node::setNext(Node * val)
	{
		next_ = val;
	}

	template<typename Type>
	typename List<Type>::Node * List<Type>::at(unsigned int position)
	{
		Node* current = head_;
		for (unsigned int iterator = 0; (iterator < position) && current; iterator++)
			current = current->next();
		return current;
	}

	template<typename Type>
	int List<Type>::indexOf(typename List<Type>::Node * inputNode)
	{
		Node* current = head_;
		for (unsigned int iterator = 0; !current; iterator++)
		{
			if (inputNode == current)
				return iterator;
			current = current->next();
		}
		return -1;
	}

	template <typename Type>
	List<Type>::List() :
		head_(nullptr), tail_(nullptr)
	{
	}

	template<typename Type>
	List<Type>::List(List<Type> *copiedList) :
		head_(nullptr), tail_(nullptr)
	{
		if (!copiedList->head())
			return;
		Node* current = copiedList->head();
		while (current)
		{
			this->pushBack(current->data());
			current = current->next();
		}
	}

	template <typename Type>
	List<Type>::~List()
	{
		this->clear();
	}

	template <typename Type>
	void List<Type>::pushBack(Type* data)
	{
		this->pushBack(*data);
	}

	template<typename Type>
	void List<Type>::pushBack(Type data)
	{
		if (!head_)
		{
			Node* current = new Node(data);
			head_ = tail_ = current;
		}
		else
		{
			Node* current = new Node(data);
			tail_->setNext(current);
			tail_ = current;
		}
	}

	template<typename Type>
	void List<Type>::pushBack(Node * inputNode)
	{
		if (!head_)
			head_ = tail_ =  inputNode;
		else
		{
			tail_->setNext(inputNode);
			tail_ = inputNode;
		}
	}



	template<typename Type>
	void List<Type>::pushAfter(unsigned int position, Type data)
	{
		Node* inputNode = new Node(data);
		Node* current = this->at(position);
		if (!current)
		{
			this->pushBack(data);
			delete inputNode;
		}
		else
		{
			Node* tempNode = current->next();
			current->setNext(inputNode);
			inputNode->setNext(tempNode);
		}
	}

	template<typename Type>
	Type* List<Type>::popFront()
	{
		if (!head_)
			return nullptr;

		Type* returnData = head_->data();

		if (head_ == tail_)
		{
			delete head_;
			head_ = tail_ = nullptr;
		}
		else
		{
			Node* deletingNode = head_;
			head_ = head_->next();
			delete deletingNode;
		}


		return returnData;
	}

	template<typename Type>
	Type * List<Type>::popBack()
	{
		if (!head_)
			return nullptr;

		Type* returnData = tail_->data();

		if (head_ == tail_)
		{
			delete tail_;
			head_ = tail_ = nullptr;
		}
		else
		{
			Node* current = head_;
			while (current->next() != tail_)
				current = current->next();
			current->setNext(nullptr);
			delete tail_;
			tail_ = current;
		}
		return returnData;


		return returnData;
	}

	template<typename Type>
	Type * List<Type>::remove(int position)
	{
		if (!head_)
			return nullptr;
		if (head_ == tail_)
			head_ = tail_ = nullptr;


		Type* returnedData = head_->data();
		if (!position)
		{
			Node* deletingNode = head_;
			head_ = head_->next();
			delete deletingNode;
		}
		else
		{
			Node* current = head_;
			for (int iterator = 0; (iterator < position - 1) && current->next()->next(); iterator++)
				current = current->next();

			returnedData = current->next()->data();
			Node* deletingNode = current->next();
			if (!current->next()->next())
			{
				tail_ = current;
				current->setNext(nullptr);
			}
			else
				current->setNext(current->next()->next());

			delete deletingNode;
		}
		return returnedData;



	}

	template<typename Type>
	typename List<Type>::Node * List<Type>::head() const
	{
		return this->head_;
	}

	template<typename Type>
	typename List<Type>::Node * List<Type>::tail() const
	{
		return this->tail_;
	}

	template<typename Type>
	void List<Type>::setTail(Node * value)
	{
		tail_ = value;
	}

	template<typename Type>
	void List<Type>::setHead(Node * value)
	{
		head_ = value;
	}

	template<typename Type>
	void List<Type>::clear()
	{
		while (head_)
		{
			Node* deletingNode = head_;
			head_ = head_->next();
			delete deletingNode;
		}
		delete head_;
	}

	template <typename Type>
	void List<Type>::pushFront(Type* data)
	{
		this->pushFront(*data);
	}

	template<typename Type>
	void List<Type>::pushFront(Type data)
	{
		if (!head_)
		{
			Node* current = new Node(data);
			head_ = tail_ = current;
		}
		else
		{
			Node* current = new Node(data);
			current->setNext(head_);
			head_ = current;
		}
	}

	template<typename Type>
	void List<Type>::pushFront(Node * inputNode)
	{
		if (!head_)
			head_ = inputNode;
		else
		{
			Node* tempNode = head_;
			head_ = inputNode;
			head_->setNext(tempNode);
		}
	}

	template <typename Type>
	Type List<Type>::get(unsigned int position)
	{
		Node* current = head_;
		for (unsigned int iterator = 0; iterator < position; iterator++)
			current = current->next();
		return *(current->data());
	}

	template <typename Type>
	std::ostream& operator<<(std::ostream& outputStream, List<Type> const & list)
	{
		auto current = list.head();

		while (current)
		{
			outputStream << *current->data() << " ";
			current = current->next();
		}
		outputStream << std::endl;
		return outputStream;
	}


}

