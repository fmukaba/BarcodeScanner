/*
 * HashTable.h
 *
 *  Created on: Dec 2, 2018
 *      Author: fxkik
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_
#include "LinkedList.h"
#include <iostream>
using namespace std;

template<class T>
class HashMap {
	int tableSize = 100;
	LinkedList<T> *array;
public:

	HashMap() {
		tableSize = 100;
		array = new LinkedList<T> [tableSize];
	}

	HashMap(int size) {
		tableSize = size;
		array = new LinkedList<T> [tableSize];
	}
	
	void add(T &element) {
		int hashEntry = hash(element);
		array[hashEntry].insertLast(element);
	}
	LinkedList<T>& getList(int index) {
		return array[index];
	}
	
	template<typename U>
	T search(U hashable) {
		int hashEntry = hash(hashable);
		T itemFound = getList(hashEntry).search(hashable);
		return itemFound;
	}
	// identify the hashable field of an object and return an hash entry
	int hash(T &item) {
		return item() % 1000;
	}
	
private: //helper hash if user want to identify himself the hashable field
	template<typename U>
	int hash(U element) {
		return element % 1000;
	}
};

#endif /* HASHTABLE_H_ */
