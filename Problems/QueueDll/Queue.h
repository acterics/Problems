#pragma once

#include <iostream>


namespace Queue {

	template <typename Type>
	class Queue
	{
	private:

		class Node
		{
		private:
			Type * data_;
			Node * next_;
			Node * prev_;
		public:
			Node();
			Node(Type data);
			Node(Type * data);
			Node(Node * copiedNode);
			Type * data() const;
			Node * next() const;
			Node * prev() const;
			void setData(Type * value);
			void setData(Type value);
			void setNext(Node * value);
			void setPrev(Node * value);
		};

		Node * head_;
		Node * tail_;

		void fillQueue(int queueSize, Type(*getRandomItem)(void));
		void recursiveQuickSort(typename Queue<Type>::Node * leftItem, typename Queue<Type>::Node * rightItem,
			bool(*compare)(Type firstComparedItem, Type secondComparedItem));
	public:
		Queue();
		Queue(int queueSize, Type(*getRandomItem)(void));
		Queue(typename Queue<Type> * copiedQueue);
		~Queue();
		void push(Type value);
		void push(Type * value);
		void push(typename Queue<Type>::Node * value);
		void pop();
		void swap(typename Queue<Type>::Node * firstItem, typename Queue<Type>::Node * secondItem);
		Type front();
		void quickSort(bool(*compare)(Type firstComparedItem, Type secondComparedItem));
		void insertSort(bool(*compare)(Type firstComparedItem, Type secondComparedItem));
		//void clear();
		int size();

		Node * head() const;
		Node * tail() const;
		void setHead(typename Queue<Type>::Node * value);
		void setTail(typename Queue<Type>::Node * value);
		void reFillQueue(Type(*getRandomItem)(void));

		template <typename Type>
		friend std::ostream& operator<<(std::ostream& outputStream, Queue<Type> const & queue);

	};
	
}



