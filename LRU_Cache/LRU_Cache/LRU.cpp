#include <iostream>

#include<unordered_map>

#include<list>

#include<algorithm>

#include "LRU.h"

using namespace std;

void show(int num) {
    cout << num << "  ";
}

void LRU::insert(int
    var) {
    if (cache.find(var) == cache.end()) { //if the element is now found in the list
        if (cache.size() == length) { //if the cache is full
            int buff = elelents.back();
            cache.erase(buff); //removing the pair in the cache
            elelents.pop_back(); //removing the last element
        }
    }
    else {
        elelents.erase(cache.find(var)->second); //erasing the exist element
    }
    elelents.push_front(var);
    cache[var] = elelents.begin();
}
//Print from the the entire of a list
void LRU::print() {
    for_each(elelents.begin(), elelents.end(), show);
    cout << endl;
}