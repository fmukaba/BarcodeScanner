#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

template<class T>
struct node {
	T data;
	node *next;
};
template<class T>
class LinkedList {
private:
	LinkedList(const LinkedList &) = delete; //copy constructor
protected:
	int count;
	node<T> *head, *last;

public:
	LinkedList();
	bool isEmpty();
	int length();
	T front();
	T back();
	T search(const T&);
	void list();
	void insertFirst(T &);
	void insertLast(T &);
	void deleteNode(T &);
	void destroylist();
	LinkedList<T> &operator=(LinkedList<T> &);
	template<class U>
	friend ostream &operator<<(ostream &os, LinkedList<U> &list);
	~LinkedList();
};
template<class T>
LinkedList<T>::LinkedList() {
	head = last = NULL;
	count = 0;
}
template<class T>
bool LinkedList<T>::isEmpty() {
	return head == NULL;
}
template<class T>
int LinkedList<T>::length() {
	return count;
}
template<class T>
T LinkedList<T>::front() {
	return head->data;
}
template<class T>
T LinkedList<T>::back() {
	return last->data;
}
template<class T>
void LinkedList<T>::insertFirst(T &item) {
	if (isEmpty()) {
		head = last = new node<T>(item);
	} else {
		node<T> *temp = new node<T>;
		temp->data = item;
		temp->next = head;
		head = temp;
		count++;
		if (last == NULL)
			last = temp;
	}
}
template<class T>
void LinkedList<T>::insertLast(T &item) {
	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = NULL;
	if (head == NULL) {
		head = last = newnode;
	} else {
		last->next = newnode;
		last = newnode;
	}
	count++;
}
template<class T>
void LinkedList<T>::deleteNode(T &item) {
	if (head == NULL) {
		//	throw NullPntrException("Empty List");
	} else {
		if (head->data == item) {
			node<T> *p = head;
			head = head->next;
			delete p;
			count--;
			if (head == NULL)
				last = NULL;
		} else {
			node<T> *p = head;
			node<T> *q = p->next;
			while (q != NULL && q->data != item) {
				p = q;
				q = q->next;
			}
			if (q != NULL) {
				p->next = q->next;
				count--;
				if (last == q)
					last = p;
				delete q;
			}
		}
	}
}
template<class T>
void LinkedList<T>::destroylist() {
	node<T> *p;
	while (head != NULL) {
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}
template<class T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &list) {
	if (this != &list) {
		copylist(list); //copylist() doesnt exist, but this doesnt give an error because its a template and has not been used by any class in my program
						//The guess is that copyList() will destroy this and rebuild it with equal nodes as the parameter
	}
	return *this; // we return this only because of channeling, ex: list1=list2=list3;, But the method is already complete with copyList
}
template<class T>
ostream &operator<<(ostream &os, LinkedList<T> &list) {
	node<T> *p = list.head;
	while (p != NULL) {
		os << p->data << " " << endl;
		p = p->next;
	}
	return os;
}
// operator << overload cant be part of the method because the operator works in this way: (ostream object << string,..)
//It always require a ostream object at the left of the operator "<<'. and if we use it as a member in any class except the ostream class,
//we will end up with : this << strings... << AND if "this" object is not an ostream then we have an error
template<class T>
LinkedList<T>::~LinkedList() {
	destroylist();
}
template<class T>
void LinkedList<T>::list() {
	node<T> *temp = head;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}
template<class T>
T LinkedList<T>::search(const T& item) {
	node<T> *temp = head;
	while (temp != NULL && temp->data != item) {
		temp = temp->next;
	}
	if (temp != NULL) {
		return temp->data;
	} else {
		return NULL;
	}

}
#endif /* LINKEDLIST_H_ */
