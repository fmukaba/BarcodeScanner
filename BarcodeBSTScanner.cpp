/*
* BarcodeBSTScanner.cpp
*
*  Created on: Nov 21, 2018
*      Author: fxkik
*/
#include <iostream>
#include "Item.h"
#include <sstream>
#include <fstream>
#include <chrono>

#include "BinarySearchTree.h"
using namespace std;
using namespace std::chrono;

void initializeBST(string fileName, BinarySearchTree<Item> & tree) {
	ifstream file(fileName); // store the file in a ifstream object
	string line;
	while (getline(file, line)) { //reads line by line in the file
		string itemName;
		string temp;
		long long barcode;
		stringstream stream(line);
		getline(stream, temp, ','); // read from where it 'points' until it reaches a comma and store substring in itemName
		getline(stream, itemName); // read from where it 'points' until the end of the line
		istringstream(temp) >> barcode; // parse/cast into long long type
		//create and add the item retrieved from the line
		Item item(itemName, barcode);
		tree.insert(item);
	}
}
int main() {

	string fileName = "upc_corpus.txt";
	BinarySearchTree<Item> tree;
	initializeBST(fileName, tree);

	//SAMPLE RuN 1
	cout << "SAMPLE RUN 1" << endl;
	Item target1("", 52569758373);
	high_resolution_clock::time_point start = high_resolution_clock::now();
	bool flag = tree.search(target1);
	high_resolution_clock::time_point end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start).count();
	cout << "time1: " << duration << " microseconds" << endl;
	cout << "Boolean value returned: " << flag << "\n" << endl;

	//SAMPLE RuN 2
	cout << "SAMPLE RUN 2" << endl;
	Item target2("", 52569744956);
	start = high_resolution_clock::now();
	flag = tree.search(target2);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end - start).count();
	cout << "time2: " << duration << " microseconds" << endl;
	cout << "Boolean value returned: " << flag << "\n" << endl;

	//SAMPLE RuN 3
	cout << "SAMPLE RUN 3" << endl;
	Item target3("", 23900007368);
	start = high_resolution_clock::now();
	flag = tree.search(target3);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end - start).count();
	cout << "time3: " << duration << " microseconds" << endl;
	cout << "Boolean value returned: " << flag << "\n" << endl;

	//SAMPLE RuN 4
	cout << "SAMPLE RUN 4" << endl;
	Item target4("", 11279000080);
	start = high_resolution_clock::now();
	flag = tree.search(target4);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end - start).count();
	cout << "time4: " << duration << " microseconds" << endl;
	cout << "Boolean value returned: " << flag << "\n" << endl;

	//SAMPLE RuN 5
	cout << "SAMPLE RUN 5" << endl;
	Item target5("", 99999);
	start = high_resolution_clock::now();
	flag = tree.search(target5);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end - start).count();
	cout << "time5: " << duration << " microseconds" << endl;
	cout << "Boolean value returned: " << flag << "\n" << endl;

	//cout<<tree.nodeCount()<<endl;
}

