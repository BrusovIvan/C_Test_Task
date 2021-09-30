#include<iostream>

#include "LRU.h"

using namespace std;
const int capacity = 4;
int main() {
	LRU cache(capacity); ////define the capacity
	cache.insert(4);
	cache.insert(5);
	cache.insert(7);
	cache.insert(2);
	cache.insert(9);
	cache.insert(4);
	cache.print();
}