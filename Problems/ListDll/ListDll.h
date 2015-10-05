#pragma once

#ifdef LISTDLL_EXPORTS
#define LISTDLL_API __declspec(dllexport) 
#else
#define LISTDLL_API __declspec(dllimport) 
#endif

#include <iostream>

namespace List
{
	template <typename Type>
	class List
	{
	public:
		class Node
		{
		private:
			Type* data_;
			Node* next_;
		public:
			Node();
			Node(Node* copiedNode);
			Node(Type* data);
			Node(Type data);
			Type* data() const;
			void setData(Type* val);
			Node* next() const;
			void setNext(Node* val);
		};
	private:
		Node* head_;
		Node* tail_;


	public:
		List();
		List(typename List<Type>* copiedList);
		~List();

		void clear();
		void pushFront(Type* data);
		void pushFront(Type data);
		void pushFront(Node* inputNode);
		void pushBack(Type* data);
		void pushBack(Type data);
		void pushBack(Node* inputNode);
		void pushAfter(unsigned int position, Type data);
		Type* popFront();
		Type* popBack();
		Type* remove(int position);
		Type get(unsigned int position);
		Node* at(unsigned int position);
		int indexOf(Node* inputNode);

		Node* head() const;
		Node* tail() const;
		void setTail(Node* value);
		void setHead(Node* value);


		template <typename Type>
		friend std::ostream& operator<<(std::ostream& outputStream, List<Type> const & list);
	};
}