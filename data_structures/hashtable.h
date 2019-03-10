// Own implemented Hast Table class

#ifndef HASH_TABLE
#define HASH_TABLE

#include "node.h"
#include "array.h"
#include "linked_list.h"

#include <iostream>

const int N = 5;

using namespace std;

template <typename K, typename V>
class HashTable{

public:

	HashTable(){
		buffer_size_ = N;
		buffer_ = Array<LinkedList<K,V>>(N);
	}
	HashTable(const int size){
		buffer_size_ = size;
		buffer_ = Array<LinkedList<K,V>>(size);
	}

	void insert(const K & key, const V & value){
		int hash_key = compute_hash_key(key);
		buffer_[hash_key].push_back(HashNode<K,V>(key, value));
		cout << "Key " << key << " Value " << value << " HK "
			<< hash_key << endl;
	}

	void get(const K & key){

		cout << "Look for " << key;
		int hash_key = compute_hash_key(key);
		cout << " HK " << hash_key << " => ";
		if(buffer_[hash_key].size() == 1){
			cout << buffer_[hash_key].begin()->value_ << endl;
			return;
		}
		else{
			HashNode<K,V> * current = buffer_[hash_key].begin();
			while(current->next_ != nullptr){
				if(current->key_ == key){
					cout << current->value_ << endl;
					return;
				}
				current = current->next_;
			}
			if(current->key_ == key){
					cout << current->value_ << endl;
					return;
			}
		}
		cout << "No entry found" << endl;
	}


private:

	int compute_hash_key(const K & key){
		return int(key) % buffer_size_;
	}


	int buffer_size_;
	Array<LinkedList<K,V>> buffer_;
};

#endif