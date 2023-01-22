

#include <iostream>// for basic i/o
#include <iomanip>// for fixed and setprecision
#include <stdexcept>// for exception
#include <string>// for string
#include <typeinfo>// for typeid
#include <stdint.h>// for uintptr_t
//#include <fstream>// for file


template<class T>
class Node;

template<class T>
class ListNode {
private:// content
    T data;
    ListNode* xnode;

private:
    ListNode(const ListNode& copy) {}

    // operator
    ListNode& operator=(const ListNode& copy) { return *this; }

public:
	// constructor
	ListNode(): data(0), xnode(0) {}
	ListNode(T a): data(a), xnode(0) {}
	~ListNode() {
    data = 0;
    xnode = 0;
  }



  T get_data() const { return data; }
  ListNode* get_xnode() const { return xnode; }

	friend class Node<T>;
	template<class U> friend std::ostream& operator<<(std::ostream& os, const Node<U>& print);
};

////// Node.h

template<class T>
class Node {

protected:
	// size
	int size;

	// head / end pointer
	ListNode<T>* last;
	ListNode<T>* end;

public:
	// constructor
	Node(): last(0), end(0), size(0) {};
	Node(const Node& copy);
	virtual ~Node();

	// operator
	Node& operator=(const Node& copy);
	T& operator[](const unsigned int x);
	//T& operator[](const unsigned int x) const;// the same even with const
	//T operator[](const unsigned int x) const;// not mutable


  	ListNode<T>* root() const;// root of list
	int length() const;// size of list
	void Print_elements() const;// print list
	void Clear();
	void push_rear(T x);// add entity
	void push_front(T x);// add entity
  	T pop_front();// pop entity
  	T pop_rear();
  	T peek_front();
	// inline
	//static inline ListNode<T>* XOR(uintptr_t a, uintptr_t b) { return a ^ b; }
	static inline ListNode<T>* XOR(uintptr_t a, uintptr_t b) { return (ListNode<T>*)(a ^ b); }
	// tran
	Node transverse() const;// transverse

	// exception class

};

////// Node.cpp

template<class T>
Node<T>::Node(const Node<T>& copy): last(0), end(0) {
	// copy content
	ListNode<T>* current = copy.last;
	ListNode<T>* prev = 0;
	ListNode<T>* next;
	while (current != 0) {
		this->push_rear(current->data);
		// iteration
		next = XOR((uintptr_t)prev, (uintptr_t)current->xnode);
		prev = current;
		current = next;
	}
}

template<class T>
Node<T>::~Node() {
	this->Clear();
}

template<class T>
Node<T>& Node<T>::operator=(const Node<T>& copy) {
	// check
	if (&copy == this) {
		return *this;
	}
	// clear
	this->Clear();
	// copy content
	ListNode<T>* current = copy.last;
	ListNode<T>* prev = 0;
	ListNode<T>* next;
	while (current) {
		this->push_rear(current->data);
		// iteration
	        next = XOR((uintptr_t)prev, (uintptr_t)current->xnode);
	        prev = current;
	        current = next;
	}
	// return
	return *this;
}





template<class T>
ListNode<T>* Node<T>::root() const {
  return last;
}

template<class T>
int Node<T>::length() const {
	return size;
}




template<class T>
void Node<T>::Print_elements() const {

	ListNode<T>* current = last;             // point to last
	ListNode<T>* prev = 0;
	ListNode<T>* next;
	std::cout << "List: ";
	while (current != 0) {                    // execute to last NULL
		if (typeid(T) == typeid(double)) {
			std::cout << std::fixed << std::setprecision(3) << current->data << " ";
		}
		else if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(std::string)) {
			std::cout << current->data << " ";
		}
	        // iteration
	        next = XOR((uintptr_t)prev, (uintptr_t)current->xnode);
	        prev = current;
	        current = next;
	}
	std::cout << std::endl;
}


template<class T>
void Node<T>::Clear() {
	ListNode<T>* current;
	ListNode<T>* prev = 0;
	ListNode<T>* next;
	while (last != 0) {
		current = last;
		next = XOR((uintptr_t)prev, (uintptr_t)last->xnode);
		prev = last;
		last = next;
		// !!! delete and prevent bug
    		current->xnode = 0;
		delete current;
		current = 0;
	}
	// !!! remembr to 0 pointer
	end = 0;
	// !!! reset size
	size = 0;
}

template<class T>
void Node<T>::push_rear(T x) {
	// add new node
	ListNode<T>* newNode = new ListNode<T>(x);
  //newNode->xnode = 0;
	// connection
	if (last == 0 && end == 0) {              // indicate list is empty now
		last = newNode;                         // fist and end are all point to new node
		end = newNode;
	}
	else {                                     // xnode new node to end pointer
		newNode->xnode = end;                // default xnode for new node
    		end->xnode = XOR((uintptr_t)end->xnode, (uintptr_t)newNode);// update previous xnode
		end = newNode;
	}
	// increase size number
	size++;
}

template<class T>
void Node<T>::push_front(T x) {
	// add new node
	ListNode<T>* newNode = new ListNode<T>(x);
	// connection
	if (last == 0 && end == 0) {              // indicate list is empty now
		last = newNode;                         // fist and end are all point to new node
		end = newNode;
	}
	else {                                     // xnode new node to end pointer
    		newNode->xnode = last;                // default xnode for new node
    		last->xnode = XOR((uintptr_t)last->xnode, (uintptr_t)newNode);// update previous xnode
		last = newNode;
	}
	// increase size number
	size++;
}

template<class T>
T Node<T>::pop_front() {
  // check

  // pop
  ListNode<T>* current = last;

  T rt = current->data;
  last = last->xnode;
  if (last) {
    last->xnode = XOR((uintptr_t)current, (uintptr_t)last->xnode);
  }
  current->xnode = 0;
  delete current;
  // decrese size
  size--;
  // return
  return rt;
}
template<class T>
T Node<T>::peek_front() {
  // check
  T rt = last->data;
 return rt;
}

template<class T>
T Node<T>::pop_rear() {

  ListNode<T>* current = end;
  //rt = current->data; it is protected data from Node (not parent class)
  T rt = current->data;
  end = end->xnode;
  if (end) {
    end->xnode = XOR((uintptr_t)current, (uintptr_t)end->xnode);
  }
  current->xnode = 0;
  delete current;
  // decrese size
  size--;
  // return
  return rt;
}

template<class T>
Node<T> Node<T>::transverse() const {
	// list for retrun
	Node<T> RT;
	// copy content
	ListNode<T>* current = last;
  	ListNode<T>* prev = 0;
  	ListNode<T>* next;
	while (current != 0) {
		RT.push_front(current->data);
		// iteration
    		next = XOR((uintptr_t)prev, (uintptr_t)current->xnode);
    		prev = current;
    		current = next;
	}
	// return
	return RT;
}

