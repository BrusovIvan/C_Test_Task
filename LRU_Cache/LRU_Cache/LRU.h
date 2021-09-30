#pragma once
#ifndef LRU_H
#define LRU_H
#include<list>
#include<unordered_map>

using namespace std;

class LRU
{
private:
	list<int> elelents;//list for storing elements
	unordered_map<int, list<int>::iterator> cache;//hashtable with linked key and value 
	int length;//capacity of hashtable
public:
	LRU(int len) {length = len;}//initialize the capacity of hashtable with cache
	void insert(int);
	void print();
};
#endif
