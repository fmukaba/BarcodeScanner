/*
 * Item.h
 *
 *  Created on: Nov 18, 2018
 *      Author: fxkik
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
using namespace std;

class Item {
	long long barcode;
	string name;
public:
	Item() {
		barcode = 0;
		name = "";
	}
	Item(long long code) {
		name = "";
		barcode = code;
	}

	Item(string title, long long code) {
		name = title;
		barcode = code;
	}

	long long getBarcode() {
		return barcode;
	}

	string getName() {
		return name;
	}

	friend bool operator<(Item &item1, Item &item2) {
		if (item1.barcode < item2.barcode)
			return true;
		else
			return false;
	}

	friend bool operator >(Item &item1, Item &item2) {
		if (item1.barcode > item2.barcode)
			return true;
		else
			return false;
	}
	friend ostream &operator<<(ostream &os, const Item &item) {
		os << item.barcode << " : " << item.name << endl;
		return os;
	}

	friend bool operator ==(Item &item1, Item &item2) {
		if (item1.barcode == item2.barcode)
			return true;
		else
			return false;
	}

	friend bool operator!=(const Item &item1, const Item &item2) {
		if (item1.barcode != item2.barcode)
			return true;
		else
			return false;
	}

	long long operator()() {
		if (barcode < 0) {
			return -1 * barcode;
		}
		return barcode;
	}
}
;

#endif /* ITEM_H_ */
