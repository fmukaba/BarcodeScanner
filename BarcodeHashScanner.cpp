///*
// * BarcodeHashScanner.cpp
// *
// *  Created on: Dec 2, 2018
// *      Author: fxkik
// */
//
//#include <iostream>
//#include "LinkedList.h"
//#include "Item.h"
//#include <sstream>
//#include <fstream>
//#include <chrono>
//#include <iostream>
//#include "HashMap.h"
//using namespace std;
//using namespace std::chrono;
//int s = 0;
//void initializeHash(string fileName, HashMap<Item> & map) {
//	ifstream file(fileName); // store the file in a ifstream object
//	string line;
//	while (getline(file, line)) { //reads line by line in the file
//		string itemName;
//		string temp;
//		long long barcode;
//		stringstream stream(line);
//		getline(stream, temp, ','); // read from where it 'points' until it reaches a comma and store substring in itemName
//		getline(stream, itemName); // read from where it 'points' until the end of the line
//		istringstream(temp) >> barcode; // parse/cast into long long type
//		//create and add the item retrieved from the line
//		Item item(itemName, barcode);
//		map.add(item);
//		s++;
//
//	}
//}
//
//int main() {
//	HashMap<Item> h(1000);
//	Item q("fear", 121221499900);
//	h.add(q);
//	string fileName = "upc_corpus.txt";
//	initializeHash(fileName, h);
//
////	Item s = h.search(q.getBarcode());
////	Item w = h.search(52569732953);
////	cout << "itemFound : " << w << endl;
//
//	//SAMPLE RuN 1
//	cout << "SAMPLE RUN 1" << endl;
//	long long target1 = 52569758373;
//	high_resolution_clock::time_point start = high_resolution_clock::now();
//	Item found = h.search(target1);
//	cout << "itemFound : " << found;
//	high_resolution_clock::time_point end = high_resolution_clock::now();
//	auto duration = duration_cast<microseconds>(end - start).count();
//	cout << "time1: " << duration << " microseconds\n" << endl;
//
//	//SAMPLE RuN 2
//	cout << "SAMPLE RUN 2" << endl;
//	long long target2 = 52569744956;
//	start = high_resolution_clock::now();
//	found = h.search(target2);
//	cout << "itemFound : " << found;
//	end = high_resolution_clock::now();
//	duration = duration_cast<microseconds>(end - start).count();
//	cout << "time2: " << duration << " microseconds\n" << endl;
//
//	//SAMPLE RuN 3
//	cout << "SAMPLE RUN 3" << endl;
//	long long target3 = 23900007368;
//	start = high_resolution_clock::now();
//	found = h.search(target3);
//	cout << "itemFound : " << found;
//	end = high_resolution_clock::now();
//	duration = duration_cast<microseconds>(end - start).count();
//	cout << "time3: " << duration << " microseconds\n" << endl;
//
//	//SAMPLE RuN 4
//	cout << "SAMPLE RUN 4" << endl;
//	long long target4 = 11279000080;
//	start = high_resolution_clock::now();
//	found = h.search(target4);
//	cout << "itemFound : " << found;
//	end = high_resolution_clock::now();
//	duration = duration_cast<microseconds>(end - start).count();
//	cout << "time4: " << duration << " microseconds\n" << endl;
//
//	//SAMPLE RuN 5
//	cout << "SAMPLE RUN 5" << endl;
//	long long target5 = 99999;
//	start = high_resolution_clock::now();
//	found = h.search(target5);
//	cout << "itemFound : " << found;
//	end = high_resolution_clock::now();
//	duration = duration_cast<microseconds>(end - start).count();
//	cout << "time5: " << duration << " microseconds" << endl;
//	//use getName() with the barcode inputed o get a conssistent output matching barcode parameter and name of product found
//}
//
